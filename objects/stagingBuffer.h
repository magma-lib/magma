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
    class StagingBuffer : public Buffer
    {
    public:
        StagingBuffer(std::shared_ptr<const Device> device,
            VkDeviceSize size,
            VkBufferCreateFlags flags = 0);
        StagingBuffer(std::shared_ptr<const Device> device,
            const void *data,
            VkDeviceSize size,
            VkBufferCreateFlags flags = 0);

        template <typename Type, size_t ArraySize>
        StagingBuffer(std::shared_ptr<const Device> device,
            const Type(&data)[ArraySize],
            VkBufferCreateFlags flags = 0) :
            Buffer(device, sizeof(Type) * ArraySize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, flags,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
        {
            const size_t size = sizeof(Type) * ArraySize;
            if (void *buffer = memory->map(0, size))
            {
                memcpy(buffer, data, size);
                memory->unmap();
            }
        }

        template <typename Type>
        StagingBuffer(std::shared_ptr<const Device> device,
            const std::vector<Type>& data,
            VkBufferCreateFlags flags = 0) :
            Buffer(device, sizeof(Type) * data.size(), VK_BUFFER_USAGE_TRANSFER_SRC_BIT, flags,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)
        {
            const size_t size = sizeof(Type) * data.size();
            if (void *buffer = memory->map(0, size))
            {
                memcpy(buffer, data.data(), size);
                memory->unmap();
            }
        }
    };
} // namespace magma
