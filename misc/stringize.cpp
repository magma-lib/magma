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
#include "stringize.h"

#ifdef MAGMA_DEBUG

namespace magma
{
const char *stringize(VkFormat param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_UNDEFINED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R4G4_UNORM_PACK8);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R4G4B4A4_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B4G4R4A4_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R5G6B5_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B5G6R5_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R5G5B5A1_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B5G5R5A1_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A1R5G5B5_UNORM_PACK16);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R8G8B8A8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8A8_SRGB);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_UNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_SNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_USCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_SSCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_UINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_SINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A8B8G8R8_SRGB_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_UNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_SNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_USCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_SSCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_UINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2R10G10B10_SINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_UNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_SNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_USCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_SSCALED_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_UINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_A2B10G10R10_SINT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_SNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_USCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_SSCALED);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R16G16B16A16_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32A32_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32A32_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R32G32B32A32_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64A64_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64A64_SINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R64G64B64A64_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B10G11R11_UFLOAT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_D16_UNORM);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_X8_D24_UNORM_PACK32);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_D32_SFLOAT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_S8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_D16_UNORM_S8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_D24_UNORM_S8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_D32_SFLOAT_S8_UINT);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC1_RGB_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC1_RGB_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC1_RGBA_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC1_RGBA_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC2_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC2_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC3_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC3_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC4_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC4_SNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC5_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC5_SNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC6H_UFLOAT_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC6H_SFLOAT_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC7_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_BC7_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_EAC_R11_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_EAC_R11_SNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_EAC_R11G11_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_EAC_R11G11_SNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_4x4_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_4x4_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_5x4_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_5x4_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_5x5_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_5x5_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_6x5_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_6x5_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_6x6_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_6x6_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x5_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x5_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x6_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x6_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x8_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_8x8_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x5_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x5_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x6_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x6_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x8_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x8_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x10_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_10x10_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_12x10_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_12x10_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_12x12_UNORM_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_ASTC_12x12_SRGB_BLOCK);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8B8G8R8_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B8G8R8G8_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R10X6_UNORM_PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R12X4_UNORM_PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16B16G16R16_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_B16G16R16G16_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR);
    MAGMA_STRINGIZE_FIELD(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkImageType param) 
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_TYPE_1D);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_TYPE_2D);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_TYPE_3D);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkImageTiling param) 
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_TILING_OPTIMAL);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_TILING_LINEAR);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkPhysicalDeviceType param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_PHYSICAL_DEVICE_TYPE_OTHER);
    MAGMA_STRINGIZE_FIELD(VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU);
    MAGMA_STRINGIZE_FIELD(VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU);
    MAGMA_STRINGIZE_FIELD(VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU);
    MAGMA_STRINGIZE_FIELD(VK_PHYSICAL_DEVICE_TYPE_CPU);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkQueryType param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_QUERY_TYPE_OCCLUSION);
    MAGMA_STRINGIZE_FIELD(VK_QUERY_TYPE_PIPELINE_STATISTICS);
    MAGMA_STRINGIZE_FIELD(VK_QUERY_TYPE_TIMESTAMP);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkPipelineStageFlagBits param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_VERTEX_INPUT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_VERTEX_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_TRANSFER_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_HOST_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
    MAGMA_STRINGIZE_FIELD(VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkImageUsageFlagBits param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_TRANSFER_DST_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_SAMPLED_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_STORAGE_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT);
    MAGMA_STRINGIZE_FIELD(VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkSurfaceTransformFlagBitsKHR param) 
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR);
    }; return MAGMA_UNKNOWN;
}

const char *stringize(VkCompositeAlphaFlagBitsKHR param)
{
    switch (param) {
    MAGMA_STRINGIZE_FIELD(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR);
    MAGMA_STRINGIZE_FIELD(VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR);
    }; return MAGMA_UNKNOWN;
}
} // namespace magma

#endif // MAGMA_DEBUG