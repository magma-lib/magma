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

#define MAGMA_EXTENSION_PREFIX "VK_"

namespace magma
{
    /* For each extensions name we calculate its hash in compile-time.
       When instance or device extensions are enumerated, their hashes added to hash map,
       which allows fast lookup of extensions in ctor-initializer. */

    class Extensions
    {
    public:
        bool hasExtension(const char *name) const noexcept;
        void forEach(std::function<void(const std::string& /* extensionName */, uint32_t /* specVersion */)> fn) const noexcept;

    protected:
        Extensions(const std::vector<VkExtensionProperties>&);
        bool hasExtension(std::size_t hash) const noexcept
            { return hashes.find(hash) != hashes.end(); }

    private:
        std::map<std::string, uint32_t> extensions;
        std::unordered_set<std::size_t> hashes;
    };
} // namespace magma
