#include <chrono>
#include <iostream>
#include "../copyMemory.h"
#include "../zeroMemory.h"

constexpr size_t BUFFER_SIZE = 1024 * 1024 * 16; // 16M
constexpr int NUM_ITERATIONS = 100;

class ScopedProfiler
{
    typedef std::chrono::high_resolution_clock HiResClock;

public:
    ScopedProfiler(const char *message):
        begin(HiResClock::now())
    {
        std::cout << std::endl << message << std::endl;
    }
    ~ScopedProfiler()
    {
        const HiResClock::time_point end = HiResClock::now();
        const std::chrono::microseconds mcs = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        const float ms = static_cast<float>(mcs.count()) / 1000.0f;
        std::cout << "Elapsed time: " << ms << "ms." << std::endl;
    }

private:
    HiResClock::time_point begin;
};

bool checkBuffer(void *buffer, char value)
{
    char *c = (char *)buffer;
    for (size_t i = 0; i < BUFFER_SIZE; ++i)
    {
        if (*c++ != value)
            return false;
    }
    return true;
}

int main()
{
#ifndef _M_AMD64
    std::cout << "Not a x64 build, quit." << std::endl;
    return 0;
#endif
    // Allocate buffers
    void *srcBuffer0 = _mm_malloc(BUFFER_SIZE, 16);
    void *dstBuffer0 = _mm_malloc(BUFFER_SIZE, 16);
    void *srcBuffer1 = _mm_malloc(BUFFER_SIZE, 16);
    void *dstBuffer1 = _mm_malloc(BUFFER_SIZE, 16);
    // Values to be copied
    memset(srcBuffer0, 0x7F, BUFFER_SIZE);
    memset(srcBuffer1, 0x7F, BUFFER_SIZE);
    // Warmup
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        // 1) Test std::memcpy()
        ScopedProfiler prof("Run std::memcpy() performance test.");
        for (int i = 0; i < NUM_ITERATIONS; ++i)
            std::memcpy(dstBuffer0, srcBuffer0, BUFFER_SIZE);
    }
    {
        // 2) Test our copy function
        ScopedProfiler prof("Run magma::copyMemory() performance test.");
        for (int i = 0; i < NUM_ITERATIONS; ++i)
            magma::copyMemory(dstBuffer1, srcBuffer1, BUFFER_SIZE);
    }
    // Test copy correctness
    if (checkBuffer(dstBuffer1, 0x7F))
        std::cout << "Memory copy Ok" << std::endl;
    else
        std::cout << "Memory copy invalid!" << std::endl;
    {
        // 3) Test std::memset()
        ScopedProfiler prof("Run std::memset() performance test.");
        for (int i = 0; i < NUM_ITERATIONS; ++i)
            std::memset(dstBuffer0, 0, BUFFER_SIZE);
    }
    {
        // 4) Test our zero function
        ScopedProfiler prof("Run magma::zeroMemory() performance test.");
        for (int i = 0; i < NUM_ITERATIONS; ++i)
            magma::zeroMemory(dstBuffer1, BUFFER_SIZE);
    }
    // Test zero correctness
    if (checkBuffer(dstBuffer1, 0))
        std::cout << "Memory zero Ok" << std::endl;
    else
        std::cout << "Memory zero invalid!" << std::endl;
    _mm_free(dstBuffer1);
    _mm_free(srcBuffer1);
    _mm_free(dstBuffer0);
    _mm_free(srcBuffer0);
    return 0;
}
