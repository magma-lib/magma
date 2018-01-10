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
#include "../objects/uniformBuffer.h"

namespace magma
{
    template <typename Block>
    inline void mapScoped(
        const std::shared_ptr<UniformBuffer<Block>>& buffer,
        bool clearMemory,
        std::function<void(Block *block)> fn)
    {
        Block *block = buffer->map(clearMemory);
        if (block)
        {
            fn(block);
            buffer->unmap();
        }
    }
} // namespace magma
