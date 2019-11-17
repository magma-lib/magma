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
#include "pch.h"
#pragma hdrstop
#include "layers.h"

namespace magma
{
Layers::Layers(const std::vector<VkLayerProperties>& properties)
{
    for (const auto& property : properties)
        layers.emplace(property.layerName, property.specVersion);
}

bool Layers::hasLayer(const char *name) const noexcept
{
    static const std::string prefix("VK_LAYER_");
    std::map<std::string, uint32_t>::const_iterator it;
    if (strstr(name, prefix.c_str()))
        it = layers.find(name);
    else
        it = layers.find(prefix + name);
    return it != layers.end();
}
} // namespace magma