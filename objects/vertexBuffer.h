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
#pragma once
#include "buffer.h"

namespace magma
{
    class VertexBuffer : public Buffer
    {
    public:
        VertexBuffer(std::shared_ptr<const Device> device,
            const void *data, VkDeviceSize size,
            uint32_t vertexCount,
            VkBufferCreateFlags flags = 0);

        template <typename VertexType, size_t ArraySize>
        VertexBuffer(std::shared_ptr<const Device> device,
            const VertexType(&vertices)[ArraySize],
            VkBufferCreateFlags flags = 0):
            Buffer(device, sizeof(VertexType) * ArraySize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, flags,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT),
            vertexCount(static_cast<uint32_t>(ArraySize))
        {
            if (void *buffer = memory->map(0, size))
            {
                memcpy(buffer, vertices, static_cast<size_t>(size));
                memory->unmap();
            }
        }

        template <typename VertexType>
        VertexBuffer(std::shared_ptr<const Device> device,
            const std::vector<VertexType>& vertices,
            VkBufferCreateFlags flags = 0):
            Buffer(device, sizeof(VertexType) * vertices.size(), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, flags,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT),
            vertexCount(static_cast<uint32_t>(vertices.size()))
        {
            if (void *buffer = memory->map(0, size))
            {
                memcpy(buffer, vertices.data(), static_cast<size_t>(size));
                memory->unmap();
            }
        }

        uint32_t getVertexCount() const { return vertexCount; }

    protected:
        VertexBuffer(std::shared_ptr<const Device> device,
            VkDeviceSize size,
            VkBufferUsageFlags usage,
            VkBufferCreateFlags flags,
            VkMemoryPropertyFlags memoryFlags);

    private:
        uint32_t vertexCount;
    };

    class LocalVertexBuffer : public VertexBuffer
    {
    public:
        LocalVertexBuffer(std::shared_ptr<const Device> device, VkDeviceSize size, VkBufferCreateFlags flags = 0);
    };
} // namespace magma
