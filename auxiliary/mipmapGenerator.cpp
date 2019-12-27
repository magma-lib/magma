/*
Magma - C++1x interface over Khronos Vulkan API.
Copyright (C) 2018 Victor Coda.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#include "pch.h"
#pragma hdrstop
#include "mipmapGenerator.h"
#include "../objects/device.h"
#include "../objects/physicalDevice.h"
#include "../objects/image.h"
#include "../objects/commandBuffer.h"
#include "../objects/queue.h"
#include "../objects/fence.h"
#include "../barriers/imageMemoryBarrier.h"
#include "../misc/imageSubresourceRange.h"

namespace magma
{
namespace aux
{
MipmapGenerator::MipmapGenerator(std::shared_ptr<Device> device):
    device(std::move(device)),
    queue(this->device->getQueue(VK_QUEUE_GRAPHICS_BIT, 0))
{}

bool MipmapGenerator::checkFormatSupport(VkFormat format) const noexcept
{
    std::shared_ptr<PhysicalDevice> physicalDevice = device->getPhysicalDevice();
    const VkFormatProperties& properties = physicalDevice->getFormatProperties(format);
    bool srcBlit = (properties.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT);
    bool dstBlit = (properties.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT);
    return srcBlit && dstBlit;
}

bool MipmapGenerator::generateMipmap(const std::shared_ptr<Image>& image, uint32_t baseLevel, VkFilter filter,
    const std::shared_ptr<CommandBuffer>& cmdBuffer, bool flush) const noexcept
{
    if (flush)
        cmdBuffer->begin();
    VkExtent3D prevMipExtent = image->getMipExtent(baseLevel);
    for (uint32_t level = baseLevel + 1; level < image->getMipLevels(); ++level)
    {
        const VkExtent3D& nextMipExtent = image->getMipExtent(level);
        VkImageBlit blitRegion;
        blitRegion.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        blitRegion.srcSubresource.mipLevel = level - 1;
        blitRegion.srcSubresource.baseArrayLayer = 0;
        blitRegion.srcSubresource.layerCount = 1;
        blitRegion.srcOffsets[0] = VkOffset3D{0, 0, 0};
        blitRegion.srcOffsets[1] = VkOffset3D{int32_t(prevMipExtent.width), int32_t(prevMipExtent.height), 1};
        blitRegion.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        blitRegion.dstSubresource.mipLevel = level;
        blitRegion.dstSubresource.baseArrayLayer = 0;
        blitRegion.dstSubresource.layerCount = 1;
        blitRegion.dstOffsets[0] = VkOffset3D{0, 0, 0};
        blitRegion.dstOffsets[1] = VkOffset3D{int32_t(nextMipExtent.width), int32_t(nextMipExtent.height), 1};
        const ImageSubresourceRange nextMipRange(image, level, 1);
        // Transition of next mip level to transfer dest
        const ImageMemoryBarrier transferDstOptimal(image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, nextMipRange);
        cmdBuffer->pipelineBarrier(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, transferDstOptimal);
        // Downsample larger mip to smaller one
        cmdBuffer->blitImage(image, image, blitRegion, filter);
        // Transition of next mip level back to transfer source
        const ImageMemoryBarrier transferSrcOptimal(image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, nextMipRange);
        cmdBuffer->pipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, transferSrcOptimal);
        prevMipExtent = nextMipExtent;
    }
    // Blitted mip levels are transitioned to shader read layout
    const ImageSubresourceRange blitMipsRange(image, baseLevel + 1, image->getMipLevels() - baseLevel - 1);
    const ImageMemoryBarrier shaderReadOnlyOptimal(image, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, blitMipsRange);
    cmdBuffer->pipelineBarrier(VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT, shaderReadOnlyOptimal);
    if (flush)
    {
        cmdBuffer->end();
        return commit(cmdBuffer);
    }
    return true;
}

bool MipmapGenerator::commit(const std::shared_ptr<CommandBuffer>& cmdBuffer) const noexcept
{
    std::shared_ptr<Fence> fence(cmdBuffer->getFence());
    if (!queue->submit(std::move(cmdBuffer), 0, nullptr, nullptr, fence))
        return false;
    if (!fence->wait())
        return false;
    return true;
}
} // namespace aux
} // namespace magma
