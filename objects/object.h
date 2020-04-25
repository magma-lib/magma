/*
Magma - abstraction layer to facilitate usage of Khronos Vulkan API.
Copyright (C) 2018-2019 Victor Coda.

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
#include "../allocator/objectAllocator.h"

#if !defined(VK_VERSION_1_1)
typedef enum VkObjectType {
    VK_OBJECT_TYPE_UNKNOWN = 0,
    VK_OBJECT_TYPE_INSTANCE = 1,
    VK_OBJECT_TYPE_PHYSICAL_DEVICE = 2,
    VK_OBJECT_TYPE_DEVICE = 3,
    VK_OBJECT_TYPE_QUEUE = 4,
    VK_OBJECT_TYPE_SEMAPHORE = 5,
    VK_OBJECT_TYPE_COMMAND_BUFFER = 6,
    VK_OBJECT_TYPE_FENCE = 7,
    VK_OBJECT_TYPE_DEVICE_MEMORY = 8,
    VK_OBJECT_TYPE_BUFFER = 9,
    VK_OBJECT_TYPE_IMAGE = 10,
    VK_OBJECT_TYPE_EVENT = 11,
    VK_OBJECT_TYPE_QUERY_POOL = 12,
    VK_OBJECT_TYPE_BUFFER_VIEW = 13,
    VK_OBJECT_TYPE_IMAGE_VIEW = 14,
    VK_OBJECT_TYPE_SHADER_MODULE = 15,
    VK_OBJECT_TYPE_PIPELINE_CACHE = 16,
    VK_OBJECT_TYPE_PIPELINE_LAYOUT = 17,
    VK_OBJECT_TYPE_RENDER_PASS = 18,
    VK_OBJECT_TYPE_PIPELINE = 19,
    VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 20,
    VK_OBJECT_TYPE_SAMPLER = 21,
    VK_OBJECT_TYPE_DESCRIPTOR_POOL = 22,
    VK_OBJECT_TYPE_DESCRIPTOR_SET = 23,
    VK_OBJECT_TYPE_FRAMEBUFFER = 24,
    VK_OBJECT_TYPE_COMMAND_POOL = 25,
    VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION = 1000156000,
    VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE = 1000085000,
    VK_OBJECT_TYPE_OBJECT_TABLE_NVX = 1000086000,
    VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NVX = 1000086001,
    VK_OBJECT_TYPE_SURFACE_KHR = 1000000000,
    VK_OBJECT_TYPE_SWAPCHAIN_KHR = 1000001000,
    VK_OBJECT_TYPE_DISPLAY_KHR = 1000002000,
    VK_OBJECT_TYPE_DISPLAY_MODE_KHR = 1000002001,
    VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT = 1000011000,
    VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT = 1000128000,
    VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR = 1000165000,
    VK_OBJECT_TYPE_VALIDATION_CACHE_EXT = 1000160000,
    VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL = 1000210000,
    VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR = 1000268000,
    VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV = 1000277000,
    VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE,
    VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION,
    VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV = VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR,
    VK_OBJECT_TYPE_BEGIN_RANGE = VK_OBJECT_TYPE_UNKNOWN,
    VK_OBJECT_TYPE_END_RANGE = VK_OBJECT_TYPE_COMMAND_POOL,
    VK_OBJECT_TYPE_RANGE_SIZE = (VK_OBJECT_TYPE_COMMAND_POOL - VK_OBJECT_TYPE_UNKNOWN + 1),
    VK_OBJECT_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkObjectType;
#endif // !VK_VERSION_1_1

namespace magma
{
    class Device;
    class IAllocator;

    /* Base non-copyable object for dispatchable and non-dispatchable handles.
       Provides user-defined new and delete operators for custom allocations. */

    class Object : public core::NonCopyable
    {
    public:
        void *operator new(std::size_t size);
        void *operator new(std::size_t size, const std::nothrow_t&) noexcept;
        void* operator new(std::size_t, void* where) noexcept;
        void operator delete(void *ptr);
        void operator delete(void *, void *) {}
        explicit Object(std::shared_ptr<Device> device,
            std::shared_ptr<IAllocator> allocator) noexcept;
        virtual ~Object() = default;
        std::shared_ptr<Device> getDevice() const noexcept { return device; }
        std::shared_ptr<IAllocator> getAllocator() const noexcept { return allocator; }
        virtual uint64_t getHandle() const noexcept = 0;
        static void overrideDefaultAllocator(std::shared_ptr<IObjectAllocator> allocator);
        static std::shared_ptr<IObjectAllocator> getOverridenAllocator() noexcept;

    protected:
        void setObjectName(VkObjectType objectType,
            const char *name) noexcept;
        void setObjectTag(VkObjectType objectType,
            uint64_t tagName,
            std::size_t tagSize,
            const void *tag) noexcept;

        std::shared_ptr<Device> device;
        std::shared_ptr<IAllocator> allocator;

    private:
        static std::shared_ptr<IObjectAllocator> objectAllocator;
        static std::atomic<int64_t> allocCount;
    };

#ifdef MAGMA_X64
    template<typename Type>
    struct ObjectType
    {
        static constexpr VkObjectType getType() { return VK_OBJECT_TYPE_UNKNOWN; }
    };

#define MAGMA_SPECIALIZE_OBJECT_TYPE(Type, type)\
    template<> struct ObjectType<Type>\
    {\
        static constexpr VkObjectType getType() { return type; }\
    };

    MAGMA_SPECIALIZE_OBJECT_TYPE(VkInstance, VK_OBJECT_TYPE_INSTANCE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkPhysicalDevice, VK_OBJECT_TYPE_PHYSICAL_DEVICE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkDevice, VK_OBJECT_TYPE_DEVICE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkQueue, VK_OBJECT_TYPE_QUEUE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkSemaphore, VK_OBJECT_TYPE_SEMAPHORE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkCommandBuffer, VK_OBJECT_TYPE_COMMAND_BUFFER)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkFence, VK_OBJECT_TYPE_FENCE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkDeviceMemory, VK_OBJECT_TYPE_DEVICE_MEMORY)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkBuffer, VK_OBJECT_TYPE_BUFFER)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkImage, VK_OBJECT_TYPE_IMAGE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkEvent, VK_OBJECT_TYPE_EVENT)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkQueryPool, VK_OBJECT_TYPE_QUERY_POOL)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkBufferView, VK_OBJECT_TYPE_BUFFER_VIEW)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkImageView, VK_OBJECT_TYPE_IMAGE_VIEW)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkShaderModule, VK_OBJECT_TYPE_SHADER_MODULE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkPipelineCache, VK_OBJECT_TYPE_PIPELINE_CACHE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkPipelineLayout, VK_OBJECT_TYPE_PIPELINE_LAYOUT)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkRenderPass, VK_OBJECT_TYPE_RENDER_PASS)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkPipeline, VK_OBJECT_TYPE_PIPELINE)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkDescriptorSetLayout, VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkSampler, VK_OBJECT_TYPE_SAMPLER)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkDescriptorPool, VK_OBJECT_TYPE_DESCRIPTOR_POOL)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkDescriptorSet, VK_OBJECT_TYPE_DESCRIPTOR_SET)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkFramebuffer, VK_OBJECT_TYPE_FRAMEBUFFER)
    MAGMA_SPECIALIZE_OBJECT_TYPE(VkCommandPool, VK_OBJECT_TYPE_COMMAND_POOL)
#endif // MAGMA_X64

    /* */

    template<typename Type>
    class ObjectTemplate : public Object
    {
    public:
        ObjectTemplate(VkObjectType objectType,
            std::shared_ptr<Device> device,
            std::shared_ptr<IAllocator> allocator) noexcept;
#ifdef MAGMA_X64
        constexpr VkObjectType getObjectType() const noexcept { return ObjectType<Type>::getType(); }
#else
        VkObjectType getObjectType() const noexcept { return objectType; }
#endif
        void setObjectName(const char *name) noexcept;
        void setObjectTag(uint64_t tagName,
            std::size_t tagSize,
            const void *tag) noexcept;
        template<typename TagType>
        void setObjectTag(uint64_t tagName,
            const TagType& tag) noexcept;

    private:
#if !defined(MAGMA_X64)
        VkObjectType objectType;
#endif
    };
} // namespace magma

#include "object.inl"
