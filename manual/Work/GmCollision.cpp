#include "GmCollision.hpp"

// =================================================
// Function: GmCollision::Neg
// =================================================
void GmCollision::Neg()
{
    m_vec2.x = -m_vec2.x;
    m_vec2.y = -m_vec2.y;
    m_vec2.z = -m_vec2.z;

    unsigned short temp = m_id1;
    m_id1 = m_id2;
    m_id2 = temp;

    m_vec1.x = -m_vec1.x;
    m_vec1.y = -m_vec1.y;
    m_vec1.z = -m_vec1.z;

    m_vec4.x = -m_vec4.x;
    m_vec4.y = -m_vec4.y;
    m_vec4.z = -m_vec4.z;
}