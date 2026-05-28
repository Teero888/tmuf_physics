#include "GmVector3.hpp"

template <typename T>
void GmVector3<T>::Clamp(const GmVector3<T>& min, const GmVector3<T>& max) {
    // Clamp X (Offset 0x0)
    if (this->x < min.x) {
        this->x = min.x;
    } 
    else if (max.x < this->x) {
        this->x = max.x;
    }

    // Clamp Y (Offset 0x4)
    if (this->y < min.y) {
        this->y = min.y;
    } 
    else if (max.y < this->y) {
        this->y = max.y;
    }

    // Clamp Z (Offset 0x8)
    if (this->z < min.z) {
        this->z = min.z;
    } 
    else if (max.z < this->z) {
        this->z = max.z;
    }
}
