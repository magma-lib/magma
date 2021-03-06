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
#include "pch.h"
#pragma hdrstop
#include "format.h"

namespace magma
{
std::size_t Format::blockCompressedSize() const noexcept
{
    switch (format)
    {
    // https://en.wikipedia.org/wiki/S3_Texture_Compression
    // DXT1c
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
    // DXT1a
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        // Stores 16 input pixels in 64 bits of output,
        // consisting of two 16-bit RGB 5:6:5 color values
        // and a 4x4 two-bit lookup table.
        return 64/8;
    // DXT2, DXT3
    case VK_FORMAT_BC2_UNORM_BLOCK:
    case VK_FORMAT_BC2_SRGB_BLOCK:
        // Stores 16 input pixels in 128 bits of output,
        // consisting of 64 bits of alpha channel data
        // (4 bits for each pixel) followed by 64 bits of color data.
        return 128/8;
    // DXT4, DXT5
    case VK_FORMAT_BC3_UNORM_BLOCK:
    case VK_FORMAT_BC3_SRGB_BLOCK:
        // Stores 16 input pixels in 128 bits of output,
        // consisting of 64 bits of alpha channel data
        // (two 8 bit alpha values and a 4x4 3 bit lookup table)
        // followed by 64 bits of color data.
        return 128/8;
    // https://en.wikipedia.org/wiki/3Dc
    // ATI1
    case VK_FORMAT_BC4_UNORM_BLOCK:
    case VK_FORMAT_BC4_SNORM_BLOCK:
        // Assuming a 4x4 texture using the largest data format possible,
        // this compression technique reduces the memory required from
        // 16 bytes to 8 bytes.
        return 64/8;
    // ATI2
    case VK_FORMAT_BC5_UNORM_BLOCK:
    case VK_FORMAT_BC5_SNORM_BLOCK:
        // Total storage is 128 bits per 4x4 block once both
        // source components are factored in. In an uncompressed
        // scheme with similar 8-bit precision, the source data
        // is 32 8-bit values for the same area, occupying 256 bits.
        // The algorithm therefore produces a 2:1 compression ratio.
        return 128/8;
    // https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc6h-format
    case VK_FORMAT_BC6H_UFLOAT_BLOCK:
    case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        // BC6H uses a fixed block size of 16 bytes (128 bits)
        // and a fixed tile size of 4x4 texels.
        return 128/8;
    // https://docs.microsoft.com/en-us/windows/win32/direct3d11/bc7-format
    case VK_FORMAT_BC7_UNORM_BLOCK:
    case VK_FORMAT_BC7_SRGB_BLOCK:
        // BC7 uses a fixed block size of 16 bytes (128 bits)
        // and a fixed tile size of 4x4 texels.
        return 128/8;
    default:
        return 0;
    }
}

std::pair<int, int> Format::blockFootprint() const noexcept
{
    switch (format)
    {
    case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
    case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        return std::make_pair(4, 4);
    case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
    case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        return std::make_pair(5, 4);
    case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
    case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        return std::make_pair(5, 5);
    case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
    case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        return std::make_pair(6, 5);
    case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
    case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        return std::make_pair(6, 6);
    case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
    case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        return std::make_pair(8, 5);
    case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
    case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        return std::make_pair(8, 6);
    case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
    case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        return std::make_pair(8, 8);
    case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
    case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        return std::make_pair(10, 5);
    case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
    case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        return std::make_pair(10, 6);
    case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
    case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        return std::make_pair(10, 8);
    case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
    case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        return std::make_pair(10, 10);
    case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
    case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        return std::make_pair(12, 10);
    case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
    case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
        return std::make_pair(12, 12);
    default:
        return std::make_pair(0, 0);
    };
}
} // namespace magma
