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
#pragma once
#include "dispatchable.h"
#include "../misc/deviceQueueDescriptor.h"

namespace magma
{
    class Instance;
    class Surface;
    class Display;

    /* A physical device usually represents a single complete implementation of Vulkan
       (excluding instance-level functionality) available to the host,
       of which there are a finite number. */

    class PhysicalDevice : public Dispatchable<VkPhysicalDevice>,
        public std::enable_shared_from_this<PhysicalDevice>
    {
        explicit PhysicalDevice(std::shared_ptr<Instance> instance, VkPhysicalDevice handle,
            std::shared_ptr<IAllocator> allocator) noexcept;
        friend class Instance;

    public:
        VkPhysicalDeviceFeatures getFeatures() const noexcept;
        VkFormatProperties getFormatProperties(VkFormat format) const noexcept;
        VkImageFormatProperties getImageFormatProperties(VkFormat format,
            VkImageType, bool optimalTiling, VkImageUsageFlags usage,
            VkImageCreateFlags flags = 0) const;
        VkPhysicalDeviceProperties getProperties() const noexcept;
        std::vector<VkQueueFamilyProperties> getQueueFamilyProperties() const;
        VkPhysicalDeviceMemoryProperties getMemoryProperties() const noexcept;
        std::shared_ptr<Device> createDevice(const std::vector<DeviceQueueDescriptor>& queueDescriptors,
            const std::vector<const char *>& layers,
            const std::vector<const char *>& extensions,
            const VkPhysicalDeviceFeatures& deviceFeatures,
            const std::vector<void *>& extendedDeviceFeatures = {}) const;
        std::vector<VkLayerProperties> enumerateLayers() const;
        std::vector<VkExtensionProperties> enumerateExtensions(const char *layerName = nullptr) const;
        bool getSurfaceSupport(std::shared_ptr<const Surface> surface) const noexcept;
        VkSurfaceCapabilitiesKHR getSurfaceCapabilities(std::shared_ptr<const Surface> surface) const;
        std::vector<VkSurfaceFormatKHR> getSurfaceFormats(std::shared_ptr<const Surface> surface) const;
        std::vector<VkPresentModeKHR> getSurfacePresentModes(std::shared_ptr<const Surface> surface) const;
        // VK_KHR_xxx_surface
        bool getPresentationSupport(uint32_t queueFamilyIndex,
            void *display = nullptr,
            const void *visualID = nullptr) const noexcept;
#ifdef VK_KHR_display
        std::vector<VkDisplayPropertiesKHR> getDisplayProperties() const;
        std::vector<VkDisplayPlanePropertiesKHR> getDisplayPlaneProperties() const;
        std::vector<std::shared_ptr<Display>> getSupportedDisplays(uint32_t planeIndex) const;
#endif
#ifdef VK_AMD_shader_core_properties
        VkPhysicalDeviceShaderCorePropertiesAMD getShaderCoreProperties() const;
#endif
#ifdef VK_AMD_shader_core_properties2
        VkPhysicalDeviceShaderCoreProperties2AMD getShaderCoreProperties2() const;
#endif
#ifdef VK_NV_ray_tracing
        VkPhysicalDeviceRayTracingPropertiesNV getRayTracingProperties() const;
#endif
        // Non-API
        std::shared_ptr<Instance> getInstance() const noexcept { return instance; }
        std::shared_ptr<Device> createDefaultDevice() const;
        bool checkExtensionSupport(const char *extensionName) const;
        bool checkPipelineCacheDataCompatibility(const void *cacheData) const noexcept;

    private:
        // VK_KHR_get_physical_device_properties2
        void getExtendedProperties(void *properties) const;

        std::shared_ptr<Instance> instance;
        mutable std::set<std::string> extensions; // Cached implicit extensions
    };

    /* A logical device can be created that connects to one or more physical devices. */

#ifdef VK_KHR_device_group
    class PhysicalDeviceGroup
    {
        explicit PhysicalDeviceGroup(const std::vector<std::shared_ptr<PhysicalDevice>>& physicalDevices,
            uint32_t groupId) noexcept;
        friend class Instance;

    public:
        std::shared_ptr<Device> createDevice(const std::vector<DeviceQueueDescriptor>& queueDescriptors,
            const std::vector<const char *>& layers,
            const std::vector<const char *>& extensions,
            const VkPhysicalDeviceFeatures& deviceFeatures,
            const std::vector<void *>& extendedDeviceFeatures = {}) const;
        uint32_t getGroupId() const { return groupId; }
        uint32_t physicalDeviceCount() const
            { return static_cast<uint32_t>(physicalDevices.size()); }
        std::shared_ptr<PhysicalDevice> getPhysicalDevice(uint32_t deviceId) const
            { return physicalDevices[deviceId]; }

    private:
        std::vector<std::shared_ptr<PhysicalDevice>> physicalDevices;
        uint32_t groupId;
    };
#endif // VK_KHR_device_group
} // namespace magma
