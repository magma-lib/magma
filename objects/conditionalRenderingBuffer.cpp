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
#include "conditionalRenderingBuffer.h"
#include "srcTransferBuffer.h"
#include "commandBuffer.h"
#include "deviceMemory.h"

namespace magma
{
ConditionalRenderingBuffer::ConditionalRenderingBuffer(std::shared_ptr<Device> device, const void *data, VkDeviceSize size,
    VkBufferCreateFlags flags /* 0 */,
    std::shared_ptr<IAllocator> allocator /* nullptr */,
    CopyMemoryFunction copyFn /* nullptr */):
    Buffer(std::move(device), size,
        VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT,
        flags, std::move(allocator),
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
{
    if (data)
        copyToMapped(data, std::move(copyFn));
}

ConditionalRenderingBuffer::ConditionalRenderingBuffer(std::shared_ptr<CommandBuffer> copyCmdBuffer, const void *data, VkDeviceSize size,
    VkBufferCreateFlags flags /* 0 */,
    std::shared_ptr<IAllocator> allocator /* nullptr */,
    CopyMemoryFunction copyFn /* nullptr */):
    ConditionalRenderingBuffer(copyCmdBuffer,
        std::make_shared<SrcTransferBuffer>(copyCmdBuffer->getDevice(), data, size, 0, allocator, std::move(copyFn)),
        flags, std::move(allocator))
{}

ConditionalRenderingBuffer::ConditionalRenderingBuffer(std::shared_ptr<CommandBuffer> copyCmdBuffer, std::shared_ptr<SrcTransferBuffer> srcBuffer,
    VkBufferCreateFlags flags /* 0 */,
    std::shared_ptr<IAllocator> allocator /* nullptr */):
    Buffer(copyCmdBuffer->getDevice(), srcBuffer->getMemory()->getSize(),
        VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        flags, std::move(allocator),
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
{
    copyTransfer(std::move(copyCmdBuffer), std::move(srcBuffer));
}
} // namespace magma