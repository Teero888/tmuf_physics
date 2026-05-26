#ifndef CFASTBUFFER_HPP
#define CFASTBUFFER_HPP

#include <cstdint>
#include <cstring>
#include "CClassicArchive.hpp" // Required for ArchiveCountAndElems

template <typename T>
class CFastBuffer {
public:
    uint32_t m_count;    // Offset 0x0 (Ghidra thought this was vftable)
    T* m_data;           // Offset 0x4
    uint32_t m_capacity; // Offset 0x8

    CFastBuffer() : m_count(0), m_data(nullptr), m_capacity(0) {}
    ~CFastBuffer() {
        if (m_data) delete[] reinterpret_cast<uint8_t*>(m_data);
    }

    // Ensures the buffer can hold at least 'reqCapacity' elements
    void SetSizeAtLeast(uint32_t reqCapacity) {
        if (reqCapacity > m_capacity) {
            uint32_t newCapacity = m_capacity + (m_capacity >> 1); // Grow by 1.5x
            if (reqCapacity > newCapacity) {
                newCapacity = reqCapacity;
            }

            // Allocate raw memory to avoid calling default constructors immediately
            T* newData = reinterpret_cast<T*>(new uint8_t[newCapacity * sizeof(T)]);
            
            if (m_count > 0 && m_data) {
                std::memcpy(newData, m_data, m_count * sizeof(T));
            }

            if (m_data) {
                delete[] reinterpret_cast<uint8_t*>(m_data);
            }
            
            m_data = newData;
            m_capacity = newCapacity;
        }
    }

    // Appends an item to the end of the buffer
    void Add(const T& item) {
        SetSizeAtLeast(m_count + 1);
        m_data[m_count] = item;
        m_count++;
    }

    // Allocates space and forces the active count to the specified size
    void AllocSetCount(uint32_t newCount) {
        SetSizeAtLeast(newCount);
        m_count = newCount;
    }

    // Fills the current active elements with a specific value
    void FillWith(const T& value) {
        for (uint32_t i = 0; i < m_count; ++i) {
            m_data[i] = value;
        }
    }

    // Finds the index of a value starting *after* the given index
    uint32_t FindAfter(const T& value, uint32_t startIndex) const {
        for (uint32_t i = startIndex + 1; i < m_count; ++i) {
            if (m_data[i] == value) {
                return i;
            }
        }
        return 0xFFFFFFFF; // Equivalent to -1 / Not Found
    }

    // Fast O(1) removal: overwrites the target chunk with the elements from the very end
    void ReplaceByLastAt(uint32_t index, uint32_t countToRemove) {
        if (index >= m_count) return;

        // Clamp the removal count so we don't read past the end of the array
        uint32_t maxRemovable = m_count - index;
        if (countToRemove > maxRemovable) {
            countToRemove = maxRemovable;
        }

        uint32_t elementsToMove = countToRemove;
        
        // If the number of elements we are removing is greater than the number of 
        // elements residing at the end of the array, we only move what's available.
        uint32_t remainingAfterRemoval = m_count - (index + countToRemove);
        if (elementsToMove > remainingAfterRemoval) {
            elementsToMove = remainingAfterRemoval;
        }

        uint32_t sourceIndex = m_count - elementsToMove;
        
        if (elementsToMove > 0) {
            std::memmove(&m_data[index], &m_data[sourceIndex], elementsToMove * sizeof(T));
        }

        m_count -= countToRemove;
    }

    // Serialization hook
    void ArchiveCountAndElems(CClassicArchive& archive) {
        if (archive.m_isWriting) {
            uint32_t tempCount = m_count;
            archive.WriteNatural(&tempCount, 1, false);
            if (m_count > 0) {
                archive.WriteData(m_data, m_count * sizeof(T));
            }
        } else {
            uint32_t newCount = 0;
            archive.ReadNatural(&newCount, 1, false);
            
            // Engine safeguard against corrupted map files requesting massive memory
            if (newCount > 0x10000000) {
                // If there was an error hook here in the original (DAT_00d72e8c), it would fire
                newCount = 0;
            }
            
            AllocSetCount(newCount);
            if (m_count > 0) {
                archive.ReadData(m_data, m_count * sizeof(T));
            }
        }
    }

    // Useful overrides for a modern C++ environment to behave normally
    T& operator[](uint32_t index) { return m_data[index]; }
    const T& operator[](uint32_t index) const { return m_data[index]; }
    uint32_t GetCount() const { return m_count; }
};

#endif // CFASTBUFFER_HPP