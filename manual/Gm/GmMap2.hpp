#ifndef GMMAP2_HPP
#define GMMAP2_HPP

#include "CFastArray.hpp"

#include <cmath>
#include <cstdint>
#include <limits>

// Native GmMap2<T> stores cell size, origin, dimensions, a fallback value,
// and a row-major CFastArray in that order. The host CFastArray contains a
// 64-bit pointer, so this declaration preserves the semantics rather than
// claiming the original 0x28-byte enclosing layout.
template <typename T>
class GmMap2 {
public:
    float m_cellSizeX;
    float m_cellSizeY;
    float m_originX;
    float m_originY;
    uint32_t m_width;
    uint32_t m_height;
    T m_defaultValue;
    CFastArray<T> m_values;

    GmMap2()
        : m_cellSizeX(0.0f),
          m_cellSizeY(0.0f),
          m_originX(0.0f),
          m_originY(0.0f),
          m_width(0u),
          m_height(0u),
          m_defaultValue() {}

    void Init(
        float originX, float originY,
        float cellSizeX, float cellSizeY,
        uint32_t width, uint32_t height,
        const T& defaultValue) {
        m_originX = originX;
        m_originY = originY;
        m_cellSizeX = cellSizeX;
        m_cellSizeY = cellSizeY;
        m_width = width;
        m_height = height;
        m_defaultValue = defaultValue;

        const uint64_t count =
            static_cast<uint64_t>(width) * static_cast<uint64_t>(height);
        if (count > std::numeric_limits<uint32_t>::max()) {
            m_width = 0u;
            m_height = 0u;
            m_values.SetCount(0u);
            return;
        }
        m_values.SetCount(static_cast<uint32_t>(count));
        for (uint32_t index = 0u; index < m_values.GetCount(); ++index) {
            m_values[index] = defaultValue;
        }
    }

    bool IsInside(float x, float y) const {
        uint32_t cellX = 0u;
        uint32_t cellY = 0u;
        return GetCell(x, y, cellX, cellY);
    }

    const T& GetValue(float x, float y) const {
        uint32_t cellX = 0u;
        uint32_t cellY = 0u;
        if (!GetCell(x, y, cellX, cellY)) return m_defaultValue;
        return m_values[cellY * m_width + cellX];
    }

    void SetValue(uint32_t cellX, uint32_t cellY, const T& value) {
        if (cellX >= m_width || cellY >= m_height) return;
        m_values[cellY * m_width + cellX] = value;
    }

private:
    bool GetCell(
        float x, float y, uint32_t& cellX, uint32_t& cellY) const {
        if (m_cellSizeX == 0.0f || m_cellSizeY == 0.0f ||
            !std::isfinite(x) || !std::isfinite(y)) {
            return false;
        }

        // TmForeverFixed.exe 0x4FF950 and 0x4FFAC0 set x87 rounding to
        // truncate before FISTP, then compare the low 32-bit values as
        // unsigned integers. Keep that unusual negative-near-origin behavior.
        const double rawX =
            (static_cast<double>(x) - static_cast<double>(m_originX)) /
            static_cast<double>(m_cellSizeX);
        const double rawY =
            (static_cast<double>(y) - static_cast<double>(m_originY)) /
            static_cast<double>(m_cellSizeY);
        constexpr double kInt64Minimum = -9223372036854775808.0;
        constexpr double kInt64MaximumExclusive = 9223372036854775808.0;
        if (!std::isfinite(rawX) || !std::isfinite(rawY) ||
            rawX < kInt64Minimum || rawX >= kInt64MaximumExclusive ||
            rawY < kInt64Minimum || rawY >= kInt64MaximumExclusive) {
            return false;
        }

        // FISTP writes a signed 64-bit integer, while the function uses only
        // its low 32 bits for the unsigned dimension comparisons.
        cellX = static_cast<uint32_t>(static_cast<int64_t>(rawX));
        cellY = static_cast<uint32_t>(static_cast<int64_t>(rawY));
        return cellX < m_width && cellY < m_height;
    }
};

#endif // GMMAP2_HPP
