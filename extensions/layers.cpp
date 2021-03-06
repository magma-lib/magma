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
#include "layers.h"
#include "../core/constexprHash.h"

namespace magma
{
Layers::Layers(const std::vector<VkLayerProperties>& properties)
{
    for (const auto& property : properties)
    {
        layers.emplace(property.layerName, property);
        hashes.emplace(core::hashString(property.layerName));
    }
}

bool Layers::hasLayer(const char *name) const noexcept
{
    static const std::string prefix(MAGMA_LAYER_PREFIX);
    const std::size_t hash = core::hashString((prefix + name).c_str());
    return hasLayer(hash);
}

void Layers::forEach(std::function<void(const VkLayerProperties&)> fn) const noexcept
{
    for (const auto& layer : layers)
        fn(layer.second);
}
} // namespace magma
