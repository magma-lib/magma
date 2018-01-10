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
#include "fence.h"
#include "device.h"
#include "../shared.h"

namespace magma
{
Fence::Fence(std::shared_ptr<const Device> device, VkFenceCreateFlags flags /* 0 */):
    NonDispatchable(VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT, device)
{
    VkFenceCreateInfo info;
    info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    info.pNext = nullptr;
    info.flags = flags;
    const VkResult create = vkCreateFence(*device, &info, nullptr, &handle);
    MAGMA_THROW_FAILURE(create, "failed to create fence");
}

Fence::~Fence()
{
    vkDestroyFence(*device, handle, nullptr);
}

bool Fence::reset() noexcept
{
    const VkResult reset = vkResetFences(*device, 1, &handle);
    return (VK_SUCCESS == reset);
}

bool Fence::wait(uint64_t timeout /* UINT64_MAX */) const noexcept
{
    const VkResult wait = vkWaitForFences(*device, 1, &handle, VK_TRUE, timeout);
    return (VK_SUCCESS == wait);
}

VkResult Fence::getStatus() const noexcept
{
    return vkGetFenceStatus(*device, handle);
}
} // namespace magma
