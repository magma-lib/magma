/*
Magma - abstraction layer to facilitate usage of Khronos Vulkan API.
Copyright (C) 2018-2020 Victor Coda.

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
#include "baseFramebuffer.h"
#include "../objects/device.h"
#include "../objects/physicalDevice.h"
#include "../objects/framebuffer.h"
#include "../states/multisampleState.h"

namespace magma
{
namespace aux
{
Framebuffer::Framebuffer(const VkFormat colorFormat, const VkFormat depthStencilFormat, const uint32_t sampleCount) noexcept:
    colorFormat(colorFormat),
    depthStencilFormat(depthStencilFormat),
    sampleCount(sampleCount)
{
    MAGMA_ASSERT(!this->colorFormat.depth());
    MAGMA_ASSERT(!this->colorFormat.stencil());
    MAGMA_ASSERT(!this->colorFormat.depthStencil());
}

bool Framebuffer::hasDepth() const noexcept
{
    return depthStencilFormat.depth() || depthStencilFormat.depthStencil();
}

bool Framebuffer::hasStencil() const noexcept
{
    return depthStencilFormat.stencil() || depthStencilFormat.depthStencil();
}

const VkExtent2D& Framebuffer::getExtent() const noexcept
{
    return framebuffer->getExtent();
}

const MultisampleState& Framebuffer::getMultisampleState() const noexcept
{
    switch (sampleCount)
    {
    case 1: return renderstates::dontMultisample;
    case 2: return renderstates::multisample2;
    case 4: return renderstates::multisample4;
    case 8: return renderstates::multisample8;
    case 16: return renderstates::multisample16;
    case 32: return renderstates::multisample32;
    case 64: return renderstates::multisample64;
    default:
        return renderstates::dontMultisample;
    }
}

VkImageLayout Framebuffer::finalDepthStencilLayout(std::shared_ptr<Device> device,
    const VkFormat depthStencilFormat, const bool depthSampled) const
{
#ifdef VK_KHR_separate_depth_stencil_layouts
    std::shared_ptr<const PhysicalDevice> physicalDevice = device->getPhysicalDevice();
    if (physicalDevice->checkExtensionSupport("VK_KHR_separate_depth_stencil_layouts"))
    {
        const Format format(depthStencilFormat);
        if (format.depth())
        {
            return depthSampled ? VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR :
                VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR;
        }
        if (format.stencil())
        {
            return depthSampled ? VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR :
                VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR;
        }
    }
#endif // VK_KHR_separate_depth_stencil_layouts
    return depthSampled ? VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL :
        VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
}
} // namespace aux
} // namespace magma
