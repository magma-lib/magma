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
#include "../shared.h"

namespace magma
{
    namespace helpers
    {
        /* As variable length arrays are not part of C++1x standard, implement our own.
           Prevent scenarios with multiple allocation in cycles/inlined functions,
           as allocated stack memory freed only when function returns. */
        template<typename Type>
        class StackArray final
        {
        public:
            explicit StackArray(void *const stack, const size_t count):
                stack(static_cast<Type *>(stack)),
                count(static_cast<uint32_t>(count)), // Vulkan accepts uint32_t
                pos(0)
            {
                if (!std::is_pod<Type>())
                {
                    for (Type *p = begin(); p != end(); ++p)
                        new(p) Type();
                }
#           ifdef MAGMA_DEBUG
                bytesAllocated = sizeof(Type) * count;
#           endif // MAGMA_DEBUG
            }
            ~StackArray()
            {
                if (!std::is_pod<Type>())
                {
                    for (Type *p = begin(); p != end(); ++p)
                        p->~Type();
                }
                MAGMA_FREEA(stack);
            }
            // Support range-based loops
            Type *begin() { return stack; }
            const Type *begin() const { return stack; }
            Type *end() { return stack + count; }
            const Type *end() const { return stack + count; }
            uint32_t size() const { return count; }
            // This method allows to avoid additional indexing variable in range-based loops
            uint32_t put(const Type& elem)
            {
                MAGMA_ASSERT(stack);
                MAGMA_ASSERT(pos < count);
                stack[pos++] = elem;
                return pos;
            }
            // Do not store or pass stack pointer anywhere, use inside function scope only
            operator Type *() { return stack; }
            operator const Type *() const { return stack; }
            Type& operator[](int i)
            {
                MAGMA_ASSERT(stack);
                MAGMA_ASSERT(i < static_cast<int>(count));
                return stack[i];
            }
            const Type& operator[](int i) const
            {
                MAGMA_ASSERT(stack);
                MAGMA_ASSERT(i < static_cast<int>(count));
				return stack[i];
            }

        private:
            Type *const stack;
            uint32_t count, pos;
#       ifdef MAGMA_DEBUG
            size_t bytesAllocated;
#       endif // MAGMA_DEBUG
        };
    } // namespace helpers
} // namespace magma

// Macro to call alloca() in the stack frame of the variable declaration
#define MAGMA_STACK_ARRAY(Type, var, count)\
    MAGMA_ASSERT(sizeof(Type) * (count) < MAGMA_MAX_STACK_ALLOC);\
    magma::helpers::StackArray<Type> var(\
        (count) ? MAGMA_ALLOCA(sizeof(Type) * (count)) : nullptr, (count))
