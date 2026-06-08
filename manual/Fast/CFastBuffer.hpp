#ifndef CFASTBUFFER_HPP
#define CFASTBUFFER_HPP

#include <cstdint>
#include <cstring>
#include "CClassicArchive.hpp"

template <typename T>
class CFastBuffer {
public:
    uint32_t m_count;
    T* m_data;
    uint32_t m_capacity;

    CFastBuffer() : m_count(0), m_data(nullptr), m_capacity(0) {}
    
    ~CFastBuffer() {
        if (m_data) delete[] reinterpret_cast<uint8_t*>(m_data);
    }

    void DeleteAll() { for(uint32_t i=0; i<m_count; ++i) { delete m_data[i]; } m_count = 0; }
    void ReplaceByLast(const T& val) { for (uint32_t i=0; i<m_count; ++i) { if (m_data[i] == val) { m_data[i] = m_data[m_count-1]; m_count--; return; } } }
    bool IsEmpty() const { return m_count == 0; }
    void RemoveAt(uint32_t index) { if (index < m_count) { m_data[index] = m_data[m_count-1]; m_count--; } }

    void SetSizeAtLeast(uint32_t reqCapacity) {
        if (reqCapacity > m_capacity) {
            uint32_t newCapacity = m_capacity + (m_capacity >> 1);
            if (reqCapacity > newCapacity) newCapacity = reqCapacity;
            T* newData = reinterpret_cast<T*>(new uint8_t[newCapacity * sizeof(T)]);
            if (m_count > 0 && m_data) std::memcpy(newData, m_data, m_count * sizeof(T));
            if (m_data) delete[] reinterpret_cast<uint8_t*>(m_data);
            m_data = newData;
            m_capacity = newCapacity;
        }
    }

    void Add(const T& item) {
        SetSizeAtLeast(m_count + 1);
        m_data[m_count++] = item;
    }

    void AllocSetCount(uint32_t newCount) {
        SetSizeAtLeast(newCount);
        m_count = newCount;
    }

    T& operator[](uint32_t index) { return m_data[index]; }
    const T& operator[](uint32_t index) const { return m_data[index]; }
    uint32_t GetCount() const { return m_count; }
};

template<typename T, typename TCat>
class CFastBufferCat : public CFastBuffer<T> {
public:
    uint32_t m_catData[6];
    void AddInCat(T item, TCat cat) { this->Add(item); }
    void ReplaceByLastInAll(T item) { this->ReplaceByLast(item); }
    int GetCountInCats(uint32_t mask, uint32_t flags) { return (int)this->m_count; }
    void ResetCat(uint32_t cat) {}
    void ChangeCatAt(uint32_t index, TCat oldCat, TCat newCat) {}
    T GetElemInCat(uint32_t index, TCat cat) { return this->m_data[index]; }
    int FindIndexInAll(T item) {
        for (uint32_t i = 0; i < this->m_count; ++i) if (this->m_data[i] == item) return (int)i;
        return -1;
    }
};

#endif
