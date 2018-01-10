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
#include <vector>
#include "../shared.h"

namespace magma
{
    class ViewportState final
    {
    public:
        ViewportState(float x, float y, float width, float height, 
            float minDepth = 0.f, float maxDepth = 1.f);
        ViewportState(float x, float y, const VkExtent2D& extent, 
            float minDepth = 0.f, float maxDepth = 1.f);
        ViewportState(const VkRect2D& viewport, const VkRect2D& scissor,
            float minDepth = 0.f, float maxDepth = 1.f);
        ViewportState(const VkViewport& viewport);     
        ViewportState(const VkViewport& viewport, const VkRect2D& scissor);
        ViewportState(const std::vector<VkViewport>& viewports);
        ViewportState(const std::vector<VkViewport>& viewports, 
            const std::vector<VkRect2D>& scissors);
        ~ViewportState();
        MAGMA_TYPE_CAST(VkPipelineViewportStateCreateInfo, state)

    private:
        void initialize(const VkViewport& viewport,
            const VkRect2D& scissor);
        void initialize(const std::vector<VkViewport>& viewports,
            const std::vector<VkRect2D>& scissors);

    private:
        VkPipelineViewportStateCreateInfo state;
    };
} // namespace magma
