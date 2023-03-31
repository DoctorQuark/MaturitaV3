#include "Cylinder.hpp"

Cylinder::Cylinder( const float t_xPos, const float t_yPos, const float t_radius, const float t_height, const uint8_t t_color[3] )
{
    Cylinder::m_xPos = t_xPos;
    Cylinder::m_yPos = t_yPos;
    Cylinder::m_radius = t_radius;
    Cylinder::m_height = t_height;
    Cylinder::m_color[0] = t_color[0];
    Cylinder::m_color[1] = t_color[1];
    Cylinder::m_color[2] = t_color[2];
}

Cylinder::Cylinder()
{

}

float Cylinder::circumscribedSphereRadius()
{
    return float(std::sqrt(std::pow(Cylinder::m_radius, 2) + (std::pow(0.5f * Cylinder::m_height, 2))));
}

ShapeContainer Cylinder::pack()
{
    return ShapeContainer(this);
}

uint8_t Cylinder::shapeToShapeType()
{
    return Cylinder::m_shapeType;
}

bool Cylinder::lineIntersection( float t_lineX1, float t_lineY1, float t_lineZ1,
                                 float t_lineX2, float t_lineY2, float t_lineZ2 )
{
    const auto l_dx = t_lineX2 - t_lineX1;
    const auto l_dy = t_lineY2 - t_lineY1;
    const auto l_dz = t_lineZ2 - t_lineZ1;
    const auto l_a = static_cast<float>(std::pow(l_dx, 2) + std::pow(l_dy, 2));
    const auto l_b = 2 * (l_dx * (t_lineX1 - Cylinder::m_xPos) + l_dy * (t_lineY1 - Cylinder::m_yPos));
    const auto l_c = static_cast<float>(std::pow(t_lineX1 - Cylinder::m_xPos, 2) + std::pow(t_lineY1 - Cylinder::m_yPos, 2) - std::pow(Cylinder::m_radius, 2));
    const auto l_discriminant = static_cast<float>(std::pow(l_b, 2) - 4.0 * static_cast<double>(l_a) * static_cast<double>(l_c));

    if ( l_discriminant < 0.0F )
    {
        return false;
    }

    const auto l_t1 = (-l_b + std::sqrt(l_discriminant)) / (2 * l_a);
    const auto l_t2 = (-l_b - std::sqrt(l_discriminant)) / (2 * l_a);
    const auto l_z1 = t_lineZ1 + l_t1 * l_dz;
    const auto l_z2 = t_lineZ1 + l_t2 * l_dz;
    const auto l_halfHeight = Cylinder::m_height / 2;

    return (l_z1 >= Cylinder::m_zPos - l_halfHeight && l_z1 <= Cylinder::m_zPos + l_halfHeight) || (l_z2 >= Cylinder::m_zPos - l_halfHeight && l_z2 <= Cylinder::m_zPos + l_halfHeight);
}
