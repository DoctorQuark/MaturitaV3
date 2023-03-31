#include "Cuboid.hpp"
#include "Sphere.hpp"
#include <cmath>

Cuboid::Cuboid( const float t_xPos, const float t_yPos, const float t_sizeX, const float t_sizeY, const float t_sizeZ, const uint8_t t_color[3] ) : m_shapeType{ 1U }
{
    Cuboid::m_xPos = t_xPos;
    Cuboid::m_yPos = t_yPos;
    Cuboid::m_xSize = t_sizeX;
    Cuboid::m_ySize = t_sizeY;
    Cuboid::m_zSize = t_sizeZ;
    Cuboid::m_color[0] = t_color[0];
    Cuboid::m_color[1] = t_color[1];
    Cuboid::m_color[2] = t_color[2];
}

Cuboid::Cuboid() : m_shapeType{ 1U }
{

}

float Cuboid::circumscribedSphereRadius()
{
    return std::sqrt(m_xSize * m_xSize + m_ySize * m_ySize + m_zSize * m_zSize) * (1.0F / 2.0F);
}

ShapeContainer Cuboid::pack()
{
    return ShapeContainer(*this);
}

uint8_t Cuboid::shapeToShapeType()
{
    return Cuboid::m_shapeType;
}

bool Cuboid::lineIntersection( const float t_lx1, const float t_ly1, const float t_lz1, const float t_lx2,
                               const float t_ly2, const float t_lz2 )
{
    const auto t_x1 = Cuboid::m_xPos - Cuboid::m_xPos / 2.0F;
    const auto t_x2 = Cuboid::m_xPos + Cuboid::m_xPos / 2.0F;

    const auto t_y1 = Cuboid::m_yPos - Cuboid::m_yPos / 2.0F;
    const auto t_y2 = Cuboid::m_yPos + Cuboid::m_yPos / 2.0F;

    const auto t_z1 = Cuboid::m_zPos - Cuboid::m_zPos / 2.0F;
    const auto t_z2 = Cuboid::m_zPos + Cuboid::m_zPos / 2.0F;

    // calculate direction vector of line
    const auto l_dx = t_lx2 - t_lx1;
    const auto l_dy = t_ly2 - t_ly1;
    const auto l_dz = t_lz2 - t_lz1;

    // check for intersection with each face of the cuboid
    if ( l_dx != 0.0F )
    {
        // check for intersection with x = x1 and x = x2 planes
        const auto l_t1 = (t_x1 - t_lx1) / l_dx;
        if ( l_t1 >= 0.0F )
        {
            // calculate y and z coordinates of intersection point
            const auto l_y = t_ly1 + l_t1 * l_dy;
            const auto l_z = t_lz1 + l_t1 * l_dz;
            if ( l_y >= t_y1 && l_y <= t_y2 && l_z >= t_z1 && l_z <= t_z2 )
            {
                return true;
            }
        }
        const float l_t2 = (t_x2 - t_lx1) / l_dx;
        if ( l_t2 >= 0.0F )
        {
            // calculate y and z coordinates of intersection point
            const auto l_y = t_ly1 + l_t2 * l_dy;
            const auto l_z = t_lz1 + l_t2 * l_dz;
            if ( l_y >= t_y1 && l_y <= t_y2 && l_z >= t_z1 && l_z <= t_z2 )
            {
                return true;
            }
        }
    }

    if ( l_dy != 0.0F )
    {
        // check for intersection with y = y1 and y = y2 planes
        const auto l_t3 = (t_y1 - t_ly1) / l_dy;
        if ( l_t3 >= 0.0F )
        {
            // calculate x and z coordinates of intersection point
            const auto l_x = t_lx1 + l_t3 * l_dx;
            const auto l_z = t_lz1 + l_t3 * l_dz;
            if ( l_x >= t_x1 && l_x <= t_x2 && l_z >= t_z1 && l_z <= t_z2 )
            {
                return true;
            }
        }
        const float l_t4 = (t_y2 - t_ly1) / l_dy;
        if ( l_t4 >= 0.0F )
        {
            // calculate x and z coordinates of intersection point
            const auto l_x = t_lx1 + l_t4 * l_dx;
            const auto l_z = t_lz1 + l_t4 * l_dz;
            if ( l_x >= t_x1 && l_x <= t_x2 && l_z >= t_z1 && l_z <= t_z2 )
            {
                return true;
            }
        }
    }

    if ( l_dz != 0 )
    {
        // check for intersection with z = z1 and z = z2 planes
        const auto l_t5 = (t_z1 - t_lz1) / l_dz;
        if ( l_t5 >= 0.0F )
        {
            // calculate x and y coordinates of intersection point
            const auto l_x = t_lx1 + l_t5 * l_dx;
            const auto l_y = t_ly1 + l_t5 * l_dy;
            if ( l_x >= t_x1 && l_x <= t_x2 && l_y >= t_y1 && l_y <= t_y2 )
            {
                return true;
            }
        }
        const auto l_t6 = (t_z2 - t_lz1) / l_dz;
        if ( l_t6 >= 0.0F )
        {
            // calculate x and y coordinates of intersection point
            const auto l_x = t_lx1 + l_t6 * l_dx;
            const auto l_y = t_ly1 + l_t6 * l_dy;
            if ( l_x >= t_x1 && l_x <= t_x2 && l_y >= t_y1 && l_y <= t_y2 )
            {
                return true;
            }
        }
    }

    // no intersection found
    return false;
}
