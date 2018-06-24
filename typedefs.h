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

namespace magma
{
    typedef std::shared_ptr<class Buffer> BufferPtr;
    typedef std::shared_ptr<class BufferView> BufferViewPtr;
    typedef std::shared_ptr<class CommandBuffer> CommandBufferPtr;
    typedef std::shared_ptr<class CommandPool> CommandPoolPtr;
    typedef std::shared_ptr<class DebugMarker> DebugMarkerPtr;
    typedef std::shared_ptr<class DebugReportCallback> DebugReportCallbackPtr;
    typedef std::shared_ptr<class DescriptorPool> DescriptorPoolPtr;
    typedef std::shared_ptr<class DescriptorSet> DescriptorSetPtr;
    typedef std::shared_ptr<class DescriptorSetLayout> DescriptorSetLayoutPtr;
    typedef std::shared_ptr<class Device> DevicePtr;
    typedef std::shared_ptr<class DeviceMemory> DeviceMemoryPtr;
    typedef std::shared_ptr<class Display> DisplayPtr;
    typedef std::shared_ptr<class DisplayMode> DisplayModePtr;
    typedef std::shared_ptr<class DisplaySurface> DisplaySurfacePtr;
    typedef std::shared_ptr<class DstTransferBuffer> DstTransferBufferPtr;
    typedef std::shared_ptr<class Event> EventPtr;
    typedef std::shared_ptr<class Fence> FencePtr;
    typedef std::shared_ptr<class Framebuffer> FramebufferPtr;
    typedef std::shared_ptr<class IAllocator> IAllocatorPtr;
    typedef std::shared_ptr<class Image> ImagePtr;
    typedef std::shared_ptr<class Image1D> Image1DPtr;
    typedef std::shared_ptr<class Image1DArray> Image1DArrayPtr;
    typedef std::shared_ptr<class Image2D> Image2DPtr;
    typedef std::shared_ptr<class Image2DArray> Image2DArrayPtr;
    typedef std::shared_ptr<class Image3D> Image3DPtr;
    typedef std::shared_ptr<class ImageCube> ImageCubePtr;
    typedef std::shared_ptr<class ImageView> ImageViewPtr;
    typedef std::shared_ptr<class IndexBuffer> IndexBufferPtr;
    typedef std::shared_ptr<class IndirectBuffer> IndirectBufferPtr;
    typedef std::shared_ptr<class Instance> InstancePtr;
    typedef std::shared_ptr<class Object> ObjectPtr;
    typedef std::shared_ptr<class PhysicalDevice> PhysicalDevicePtr;
    typedef std::shared_ptr<class Pipeline> PipelinePtr;
    typedef std::shared_ptr<class PipelineCache> PipelineCachePtr;
    typedef std::shared_ptr<class PipelineLayout> PipelineLayoutPtr;
    typedef std::shared_ptr<class QueryPool> QueryPoolPtr;
    typedef std::shared_ptr<class Queue> QueuePtr;
    typedef std::shared_ptr<class RenderPass> RenderPassPtr;
    typedef std::shared_ptr<class Sampler> SamplerPtr;
    typedef std::shared_ptr<class Semaphore> SemaphorePtr;
    typedef std::shared_ptr<class ShaderModule> ShaderModulePtr;
    typedef std::shared_ptr<class SrcTransferBuffer> SrcTransferBufferPtr;
    typedef std::shared_ptr<class StorageBuffer> StorageBufferPtr;
    typedef std::shared_ptr<class StorageTexelBuffer> StorageTexelBufferPtr;
    typedef std::shared_ptr<class Surface> SurfacePtr;
    typedef std::shared_ptr<class Swapchain> SwapchainPtr;
    typedef std::shared_ptr<class VertexBuffer> VertexBufferPtr;
    typedef std::shared_ptr<class UniformTexelBuffer> UniformTexelBufferPtr;

    template<class Block> using DynamicUniformBufferPtr = std::shared_ptr<class DynamicUniformBuffer<Block>>;
    template<class Block> using UniformBufferPtr = std::shared_ptr<class UniformBuffer<Block>>;
} // namespace magma
