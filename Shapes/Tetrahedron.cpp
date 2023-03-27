/*
 * Velikost tetrahedru je definována pomocí výšek, hodnoty velikostí tušíž je musím vynásobit 2/3 abych dostal vzálenost vrcholu od středu.
 */

#include "Tetrahedron.hpp"
#include "Cylinder.hpp"

Tetrahedron::Tetrahedron( const float t_xPos, const float t_yPos, const float t_xSize, const float t_ySize, const float t_zSize, const uint8_t t_color[3] )
{
    Tetrahedron::m_xPos = t_xPos;
    Tetrahedron::m_yPos = t_yPos;
    Tetrahedron::m_xSize = t_xSize;
    Tetrahedron::m_ySize = t_ySize;
    Tetrahedron::m_zSize = t_zSize;
    Tetrahedron::m_color[0] = t_color[0];
    Tetrahedron::m_color[1] = t_color[1];
    Tetrahedron::m_color[2] = t_color[2];
    Tetrahedron::m_shapeType = 4U;
}

Tetrahedron::Tetrahedron( const Tetrahedron &t_other )
{
    Tetrahedron::m_xPos = t_other.m_xPos;
    Tetrahedron::m_yPos = t_other.m_yPos;
    Tetrahedron::m_zPos = t_other.m_zPos;
    Tetrahedron::m_xSize = t_other.m_xSize;
    Tetrahedron::m_ySize = t_other.m_ySize;
    Tetrahedron::m_zSize = t_other.m_zSize;
    Tetrahedron::m_color[0] = t_other.m_color[0];
    Tetrahedron::m_color[1] = t_other.m_color[1];
    Tetrahedron::m_color[2] = t_other.m_color[2];
    Tetrahedron::m_shapeType = t_other.m_shapeType;
}

Tetrahedron::Tetrahedron()
{
    Tetrahedron::m_shapeType = 4U;
}

ShapeContainer Tetrahedron::pack()
{
    return ShapeContainer(*this);
}

uint8_t Tetrahedron::shapeToShapeType()
{
    return Tetrahedron::m_shapeType;
}

/*
bool Tetrahedron::isLineIntersectingTetrahedron( float t_lineX1, float t_lineY1, float t_lineZ1, float t_lineX2, float t_lineY2, float t_lineZ2 )
{
    const auto t_tetraX1 = Tetrahedron::m_xPos + Tetrahedron::m_zSize * (2.0F / 3.0F);
    const auto t_tetraY1 = Tetrahedron::m_yPos + Tetrahedron::m_zSize * (2.0F / 3.0F);
    const auto t_tetraZ1 = Tetrahedron::m_zPos + Tetrahedron::m_zSize * (2.0F / 3.0F);

    const auto t_tetraX2 = Tetrahedron::m_xPos + Tetrahedron::m_zSize / 3.0F + ;

    // Calculate the normal vector of the plane formed by the first three points of the tetrahedron
    auto l_a1 = t_tetraX2 - t_tetraX1;
    auto l_b1 = t_tetraY2 - t_tetraY1;
    auto l_c1 = t_tetraZ2 - t_tetraZ1;
    auto l_a2 = t_tetraX3 - t_tetraX1;
    auto l_b2 = t_tetraY3 - t_tetraY1;
    auto l_c2 = t_tetraZ3 - t_tetraZ1;
    auto l_nx = l_b1 * l_c2 - l_b2 * l_c1;
    auto l_ny = l_a2 * l_c1 - l_a1 * l_c2;
    auto l_nz = l_a1 * l_b2 - l_b1 * l_a2;

    // Calculate the distance from the fourth point of the tetrahedron to the plane
    auto l_d = -(l_nx * t_tetraX1 + l_ny * t_tetraY1 + l_nz * t_tetraZ1);
    auto l_dist = (l_nx * t_tetraX4 + l_ny * t_tetraY4 + l_nz * t_tetraZ4 + l_d) / std::sqrt(std::pow(l_nx, 2) + std::pow(l_ny, 2) + std::pow(l_nz, 2));

    // Check if the line intersects the plane
    auto l_denom = (l_nx * (t_lineX2 - t_lineX1) + l_ny * (t_lineY2 - t_lineY1) + l_nz * (t_lineZ2 - t_lineZ1));
    if ( l_denom == 0.0f )
    {
        return false; // Line is parallel to the plane
    }
    auto l_u = -(l_nx * t_lineX1 + l_ny * t_lineY1 + l_nz * t_lineZ1 + l_d) / l_denom;
    if ( l_u < 0.0f || l_u > 1.0f )
    {
        return false; // Line segment does not intersect the plane
    }

    // Calculate the intersection point
    auto l_xi = t_lineX1 + (t_lineX2 - t_lineX1) * l_u;
    auto l_yi = t_lineY1 + (t_lineY2 - t_lineY1) * l_u;
    auto l_zi = t_lineZ1 + (t_lineZ2 - t_lineZ1) * l_u;

    // Check if the intersection point is inside the tetrahedron
    // This can be done by checking if the point is on the same side of all four faces of the tetrahedron
    bool isInsideTetrahedron = true;

    // Face 123
    if (((l_xi - t_tetraX3) * (l_yi - t_tetraY3) - (l_xi - t_tetraX2) * (l_yi - t_tetraY3)) *
        ((t_tetraX4 - t_tetraX3) * (t_tetraY4 - t_tetraY3) - (t_tetraX4 - t_tetraX2) * (t_tetraY4 - t_tetraY3)) < 0 )
        isInsideTetrahedron = false;

    // Face 134
    if (((l_xi - t_tetraX3) * (l_yi - t_tetraY3) - (l_xi - t_tetraX1) * (l_yi - t_tetraY3)) *
        ((t_tetraX4 - t_tetraX3) * (t_tetraY4 - t_tetraY3) - (t_tetraX4 - t_tetraX1) * (t_tetraY4 - t_tetraY3)) < 0 )
        isInsideTetrahedron = false;

    // Face 234
    if (((l_xi - t_tetraX3) * (l_yi - t_tetraY3) - (l_xi - t_tetraX2) * (l_yi - t_tetraY3)) *
        ((t_tetraX4 - t_tetraX3) * (t_tetraY4 - t_tetraY3) - (t_tetraX4 - t_tetraX2) * (t_tetraY4 - t_tetraY3)) < 0 )
        isInsideTetrahedron = false;

    return isInsideTetrahedron;
}
*/
