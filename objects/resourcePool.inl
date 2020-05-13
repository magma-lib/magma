namespace magma
{
template<typename Type>
inline void ResourcePool::Pool<Type>::registerResource(const Type *resource) noexcept
{
    try {
        resources.insert(resource);
    } catch (...) {}
}

template<typename Type>
inline void ResourcePool::Pool<Type>::unregisterResource(const Type *resource) noexcept
{
    try {
        auto it = resources.find(resource);
        MAGMA_ASSERT(it != resources.end());
        if (it != resources.end())
            resources.erase(it);
    } catch (...) {}
}

template<typename Type>
inline uint32_t ResourcePool::Pool<Type>::count() const noexcept
{
    return static_cast<uint32_t>(resources.size());
}

template<typename Type>
template<typename ChildType>
void ResourcePool::Pool<Type>::forEach(const std::function<void(const ChildType *resource)>& fn) const noexcept
{
    for (const Type *resource : resources)
    {
        const ChildType *child = dynamic_cast<const ChildType *>(resource);
        if (child)
            fn(child);
    }
}

#ifdef MAGMA_X64
#define MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(Type, pool)\
template<>\
inline ResourcePool::Pool<Type>& ResourcePool::getPool<Type>() noexcept\
{\
    return pool;\
}

// Core types
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkSemaphore>, semaphores);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkFence>, fences);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDeviceMemory>, deviceMemories);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkBuffer>, buffers);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkImage>, images);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkEvent>, events);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkQueryPool>, queryPools);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkBufferView>, bufferViews);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkImageView>, imageViews);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkShaderModule>, shaderModules);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkPipelineCache>, pipelineCaches);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkPipelineLayout>, pipelineLayouts);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkRenderPass>, renderPasses);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkPipeline>, pipelines);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDescriptorSetLayout>, descriptorSetLayouts);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkSampler>, samplers);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDescriptorPool>, descriptorPools);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDescriptorSet>, descriptorSets);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkFramebuffer>, framebuffers);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkCommandPool>, commandPools);
// Non-core types
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkSurfaceKHR>, surfaces);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkSwapchainKHR>, swapchains);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDisplayKHR>, displays);
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkDebugReportCallbackEXT>, debugReportCallbacks);
#ifdef VK_NV_ray_tracing
MAGMA_RESOURCE_POOL_IMPLEMENT_ACCESSOR(NonDispatchable<VkAccelerationStructureNV>, accelerationStructures);
#endif
#endif // MAGMA_X64
} // namespace magma