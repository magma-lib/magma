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
#include "handle.h"
#include "../misc/clearValue.h"

namespace magma
{
    struct ClearValue;
    class Device;
    class RenderPass;
    class Framebuffer;
    class QueryPool;
    class Event;
    class DescriptorSet;
    class PipelineLayout;
    class GraphicsPipeline;
    class ComputePipeline;
    class Buffer;
    class VertexBuffer;
    class IndexBuffer;

    // Methods order follows Vulkan API order
    class CommandBuffer : public Handle<VkCommandBuffer>
    {
    public:
        bool begin() noexcept;
        bool begin(
            std::shared_ptr<const RenderPass> renderPass, 
            uint32_t subpass, 
            std::shared_ptr<const Framebuffer> framebuffer,
            VkCommandBufferUsageFlags flags = 0) noexcept;
        bool end() noexcept;
        bool reset(bool releaseResources) noexcept;

        void bindPipeline(std::shared_ptr<const GraphicsPipeline> pipeline) noexcept;
        void bindPipeline(std::shared_ptr<const ComputePipeline> pipeline) noexcept;

        void setViewport(const VkViewport& viewport) noexcept;
        void setViewport(
            float x, float y, 
            float width, float height,
            float minDepth = 0.f, 
            float maxDepth = 1.f) noexcept;
        void setViewport(
            uint32_t x, uint32_t y, 
            uint32_t width, uint32_t height,
            float minDepth = 0.f, 
            float maxDepth = 1.f) noexcept;
        void setScissor(const VkRect2D& scissor) noexcept;
        void setScissor(
            int32_t x, int32_t y,
            uint32_t width, uint32_t height) noexcept;

        void setLineWidth(float lineWidth) noexcept;
        void setDepthBias(
            float depthBiasConstantFactor,
            float depthBiasClamp,
            float depthBiasSlopeFactor) noexcept;
        void setBlendConstants(const float blendConstants[4]) noexcept;
        void setDepthBounds(
            float minDepthBounds, 
            float maxDepthBounds) noexcept;
        void setStencilCompareMask(
            bool frontFace,
            bool backFace,
            uint32_t compareMask) noexcept;
        void setStencilWriteMask(
            bool frontFace,
            bool backFace,
            uint32_t writeMask) noexcept;
        void setStencilReference(
            bool frontFace,
            bool backFace,
            uint32_t reference) noexcept;

        void bindDescriptorSets(
            std::shared_ptr<const DescriptorSet> descriptorSet,
            std::shared_ptr<const PipelineLayout> pipelineLayout,
            VkPipelineBindPoint pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS) noexcept;
        void bindIndexBuffer(
            std::shared_ptr<const IndexBuffer> indexBuffer,
            VkDeviceSize offset = 0) noexcept;
        void bindVertexBuffer(
            uint32_t firstBinding,
            std::shared_ptr<const VertexBuffer> vertexBuffer,
            VkDeviceSize offset = 0) noexcept;
        void bindVertexBuffers(
            uint32_t firstBinding,
            const std::vector<std::shared_ptr<const VertexBuffer>>& vertexBuffers,
            const std::vector<VkDeviceSize>& offsets) noexcept;

        void draw(
            uint32_t vertexCount,
            uint32_t firstVertex) const noexcept;
        void drawInstanced(
            uint32_t vertexCount,
            uint32_t instanceCount,
            uint32_t firstVertex,
            uint32_t firstInstance) const noexcept;
        void drawIndexed(
            uint32_t indexCount,
            uint32_t firstIndex,
            int32_t vertexOffset) const noexcept;
        void drawIndexedInstanced(
            uint32_t indexCount,
            uint32_t instanceCount,
            uint32_t firstIndex,
            int32_t vertexOffset,
            uint32_t firstInstance) const noexcept;
        void drawIndirect(
            std::shared_ptr<const Buffer> buffer,
            VkDeviceSize offset,
            uint32_t drawCount,
            uint32_t stride) const noexcept;
        void drawIndexedIndirect(
            std::shared_ptr<const Buffer> buffer,
            VkDeviceSize offset,
            uint32_t drawCount,
            uint32_t stride) const noexcept;
        void dispatch(
            uint32_t x,
            uint32_t y,
            uint32_t z) const noexcept;
        void dispatchIndirect(
            std::shared_ptr<const Buffer> buffer,
            VkDeviceSize offset) const noexcept;

        void copyBuffer(
            std::shared_ptr<const Buffer> srcBuffer,
            std::shared_ptr<Buffer> dstBuffer,
            VkDeviceSize srcOffset = 0,
            VkDeviceSize dstOffset = 0,
            VkDeviceSize size = 0) const noexcept;
        void copyBuffer(
            std::shared_ptr<const Buffer> srcBuffer,
            std::shared_ptr<Buffer> dstBuffer,
            const VkBufferCopy& region) const noexcept;
        void copyBuffer(
            std::shared_ptr<const Buffer> srcBuffer,
            std::shared_ptr<Buffer> dstBuffer,
            const std::vector<VkBufferCopy>& regions) const noexcept;
        void copyImage() const noexcept; // TODO: implement
        void blitImage() const noexcept; // TODO: implement
        void copyBufferToImage() const noexcept; // TODO: implement
        void copyImageToBuffer() const noexcept; // TODO: implement
        void updateBuffer() const noexcept; // TODO: implement
        void fillBuffer() const noexcept; // TODO: implement
        void clearColorImage() const noexcept; // TODO: implement
        void clearDepthStencilImage() const noexcept; // TODO: implement
        void clearAttachments() const noexcept; // TODO: implement
        void resolveImage() const noexcept; // TODO: implement

        void setEvent(
            std::shared_ptr<const Event> event,
            VkPipelineStageFlags stageMask) noexcept; // TODO: implement
        void resetEvent(
            std::shared_ptr<Event> event,
            VkPipelineStageFlags stageMask) noexcept; // TODO: implement
        void waitEvents() noexcept; // TODO: implement
        void pipelineBarrier() noexcept; // TODO: implement
        void beginQuery(
            std::shared_ptr<QueryPool> queryPool,
            uint32_t queryIndex,
            bool precise) noexcept;
        void endQuery(
            std::shared_ptr<QueryPool> queryPool,
            uint32_t queryIndex) noexcept;
        void resetQueryPool(std::shared_ptr<QueryPool> queryPool) noexcept;
        void copyQueryResults(
            std::shared_ptr<const QueryPool> queryPool,
            std::shared_ptr<Buffer> buffer,
            bool wait,
            uint32_t firstQuery = 0,
            uint32_t queryCount = std::numeric_limits<uint32_t>::max(),
            VkDeviceSize dstOffset = 0,
            bool write64Bit = true) noexcept;
        void writeTimestamp() noexcept; // TODO: implement

        void pushConstants() noexcept; // TODO: implement

        void beginRenderPass(
            std::shared_ptr<const RenderPass> renderPass, 
            std::shared_ptr<const Framebuffer> framebuffer,
            VkSubpassContents contents = VK_SUBPASS_CONTENTS_INLINE) noexcept;
        void nextSubpass() noexcept; // TODO: implement
        void endRenderPass() noexcept;

        void executeCommands(const std::vector<std::shared_ptr<CommandBuffer>>& commandBuffers) noexcept;

        // EXT_debug_marker
        void beginDebugMarker(
            const char *name, 
            const float color[4]) noexcept;
        void endDebugMarker() noexcept;
        void insertDebugMarker(const char *name) noexcept;
        
        // Non-API utility methods
        void setClear(const ClearValue& value);
        void setClears(const std::vector<ClearValue>& values);

        void setRenderArea(const VkRect2D& rc) noexcept;
        void setRenderArea(
            int32_t x, int32_t y, 
            const VkExtent2D& extent) noexcept;
        void setRenderArea(
            int32_t x, int32_t y, 
            uint32_t width, uint32_t height) noexcept;

        void enableOcclusionQuery(
            bool enable, 
            VkQueryControlFlags queryFlags) noexcept;
        void queryPipelineStatistics(VkQueryPipelineStatisticFlags pipelineStatistics) noexcept;

    private:
        CommandBuffer(VkCommandBuffer handle, std::shared_ptr<const Device> device);
        friend class CommandPool;

    private:
        std::vector<ClearValue> clearValues;
        VkRect2D renderArea = {0};
        bool occlusionQueryEnable = false;
        VkQueryControlFlags queryFlags = 0;
        VkQueryPipelineStatisticFlags pipelineStatistics = 0;
    };
} // namespace magma

#include "commandBuffer.inl"
