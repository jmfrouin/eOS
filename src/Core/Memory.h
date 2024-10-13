//
// Created by Jean-Michel Frouin on 13/10/2024.
//

#ifndef EOS_MEMORY_H
#define EOS_MEMORY_H

#include <cstdlib>
#include <cstring>

namespace Core {

    /**
     * @class CMemory
     * @brief A utility class for memory operations.
     */
    class CMemory {
    public:
        /**
         * @brief Compares two memory buffers.
         * @param buf1 Pointer to the first buffer.
         * @param buf2 Pointer to the second buffer.
         * @param size Number of bytes to compare.
         * @return An integer less than, equal to, or greater than zero if the first buffer is found,
         * respectively, to be less than, to match, or be greater than the second buffer.
         */
        static int Compare(void *buf1, const void *buf2, unsigned int size) { return ::memcmp(buf1, buf2, size); }

        /**
         * @brief Copies memory from source to destination.
         * @param dst Pointer to the destination buffer.
         * @param src Pointer to the source buffer.
         * @param size Number of bytes to copy.
         * @return Pointer to the destination buffer.
         */
        static void *Copy(void *dst, const void *src, unsigned int size) { return ::memcpy(dst, src, size); }

        /**
         * @brief Moves memory from source to destination.
         * @param dst Pointer to the destination buffer.
         * @param src Pointer to the source buffer.
         * @param size Number of bytes to move.
         * @return Pointer to the destination buffer.
         */
        static void *Move(void *dst, const void *src, unsigned int size) { return ::memmove(dst, src, size); }

        /**
         * @brief Sets a block of memory to a specified value.
         * @param dst Pointer to the memory block.
         * @param value Value to set.
         * @param size Number of bytes to set.
         */
        static void Set(void *dst, int value, unsigned int size) { ::memset(dst, value, size); }

        /**
         * @brief Allocates a block of memory.
         * @param size Number of bytes to allocate.
         * @return Pointer to the allocated memory.
         */
        static void *Malloc(unsigned int size) { return ::malloc(size); }

        /**
         * @brief Reallocates a block of memory.
         * @param pointer Pointer to the previously allocated memory.
         * @param size New size in bytes.
         * @return Pointer to the reallocated memory.
         */
        static void *Realloc(void *pointer, unsigned int size) { return ::realloc(pointer, size); }

        /**
         * @brief Frees a block of memory.
         * @param pointer Pointer to the memory to free.
         */
        static void Free(void *pointer) { ::free(pointer); }
    };
}

#endif //EOS_MEMORY_H