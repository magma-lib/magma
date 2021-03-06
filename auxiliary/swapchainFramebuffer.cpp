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
#include "swapchainFramebuffer.h"
#include "../objects/device.h"
#include "../objects/image2DAttachment.h"
#include "../objects/imageView.h"
#include "../objects/renderPass.h"
#include "../objects/framebuffer.h"
#include "../misc/format.h"

namespace magma
{
namespace aux
{
SwapchainFramebuffer::SwapchainFramebuffer(std::shared_ptr<SwapchainColorAttachment> color,
    VkFormat depthStencilFormat /* VK_FORMAT_UNDEFINED */,
    const VkComponentMapping& swizzle /* VK_COMPONENT_SWIZZLE_IDENTITY */,
    std::shared_ptr<IAllocator> allocator /* nullptr */):
    Framebuffer(color->getFormat(), depthStencilFormat, color->getSamples())
{
    std::shared_ptr<Device> device = color->getDevice();
    colorView = std::make_shared<ImageView>(color, swizzle, allocator);
    if (depthStencilFormat != VK_FORMAT_UNDEFINED)
    {
        const VkExtent2D extent{color->getMipExtent(0).width, color->getMipExtent(0).height};
        depthStencil = std::make_shared<DepthStencilAttachment>(device, depthStencilFormat, extent, 1, color->getSamples(), false, allocator);
        depthStencilView = std::make_shared<ImageView>(depthStencil, swizzle, allocator);
    }
    const AttachmentDescription colorAttachment(color->getFormat(), 1,
        op::clearStore, // Clear color, store
        op::dontCare, // Stencil don't care
        VK_IMAGE_LAYOUT_UNDEFINED, // Don't care
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
    if (depthStencilFormat != VK_FORMAT_UNDEFINED)
    {
        const AttachmentDescription depthStencilAttachment(depthStencilFormat, 1,
            op::clearStore, // Clear depth, store
            hasStencil() ? op::clearStore : op::dontCare,
            VK_IMAGE_LAYOUT_UNDEFINED, // Don't care
            VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL); // Stay as attachment
        renderPass = std::make_shared<RenderPass>(std::move(device), std::initializer_list<AttachmentDescription>{
            colorAttachment, depthStencilAttachment}, allocator);
        framebuffer = std::make_shared<magma::Framebuffer>(renderPass, std::vector<std::shared_ptr<ImageView>>{
            colorView, depthStencilView}, 0, std::move(allocator));
    }
    else
    {
        renderPass = std::make_shared<RenderPass>(std::move(device), colorAttachment, allocator);
        framebuffer = std::make_shared<magma::Framebuffer>(renderPass, colorView, 0, std::move(allocator));
    }
}
} // namespace aux
} // namespace magma
