#ifndef CFASTARRAY_HPP
#define CFASTARRAY_HPP

#include "typedefs.h"
#include <utility>

// =================================================
// CFastArray Template Definition
// Represents a raw array of elements. Memory is managed
// via standard C++ new[] and delete[] which matches the 
// MSVC +4 byte offset CRT footprint seen in Ghidra.
// =================================================
template <typename T>
class CFastArray {
public:
    unsigned long m_count; // 0x00
    T* m_data;             // 0x04

    CFastArray() : m_count(0), m_data(nullptr) {}
    
    ~CFastArray() { 
        if (m_data) {
            delete[] m_data; 
        }
    }

    // =================================================
    // Function: SetCount
    // =================================================
    void SetCount(unsigned long newCount) {
        if (newCount == m_count) {
            return;
        }

        if (m_data == nullptr) {
            if (newCount != 0) {
                m_count = newCount;
                m_data = new T[newCount];
            }
        } 
        else if (newCount != 0) {
            if (m_count <= newCount) {
                AllocateMore(newCount);
            } else {
                AllocateLess(newCount);
            }
        } 
        else {
            delete[] m_data;
            m_data = nullptr;
            m_count = 0;
        }
    }

    // =================================================
    // Function: AllocateMore / AllocateLess
    // Reallocates the internal buffer and copies existing elements.
    // =================================================
    void AllocateMore(unsigned long newCount) {
        T* newData = new T[newCount];
        
        for (unsigned long i = 0; i < m_count; ++i) {
            newData[i] = std::move(m_data[i]);
        }
        
        delete[] m_data;
        m_data = newData;
        m_count = newCount;
    }

    void AllocateLess(unsigned long newCount) {
        T* newData = new T[newCount];
        
        for (unsigned long i = 0; i < newCount; ++i) {
            newData[i] = std::move(m_data[i]);
        }
        
        delete[] m_data;
        m_data = newData;
        m_count = newCount;
    }

    // =================================================
    // Function: AddTail
    // =================================================
    void AddTail(const T& elem) {
        if (m_count == 0) {
            SetCount(1);
            m_data[0] = elem;
        } else {
            AllocateMore(m_count + 1);
            m_data[m_count - 1] = elem;
        }
    }

    // =================================================
    // Function: InsertNewElemAt
    // Shifts elements right to open a slot, mimicking CFastBuffer.
    // =================================================
    T* InsertNewElemAt(unsigned long index) {
        SetCount(m_count + 1); // Expand array by 1

        // Shift elements to the right to make room
        for (unsigned long i = m_count - 1; i > index; --i) {
            m_data[i] = std::move(m_data[i - 1]);
        }
        
        return &m_data[index];
    }

    // =================================================
    // Function: InsertAt
    // =================================================
    void InsertAt(unsigned long index, const T& elem) {
        T* newSlot = InsertNewElemAt(index);
        *newSlot = elem;
    }

    // =================================================
    // Operator Overloads
    // =================================================
    inline unsigned long GetCount() const { return m_count; }

    inline T& operator[](unsigned long index) {
        return m_data[index];
    }
    
    inline const T& operator[](unsigned long index) const {
        return m_data[index];
    }
};

#endif // CFASTARRAY_HPP