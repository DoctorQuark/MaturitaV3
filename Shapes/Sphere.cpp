#include "Sphere.hpp"

Sphere::Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t *t_color )
{
    Sphere::m_xPos = t_xPos;
    Sphere::m_yPos = t_yPos;
    Sphere::m_radius = t_radius;
    Sphere::m_color[0] = t_color[0];
    Sphere::m_color[1] = t_color[1];
    Sphere::m_color[2] = t_color[2];
}

Sphere::Sphere()
{

}

float Sphere::circumscribedSphereRadius()
{
    return Sphere::m_radius;
}

ShapeContainer Sphere::pack()
{
    return ShapeContainer(*this);
}

uint8_t Sphere::shapeToShapeType()
{
    return Sphere::m_shapeType;
}

bool Sphere::lineIntersection( const float t_lineX1, const float t_lineY1, const float t_lineZ1, const float t_lineX2, const float t_lineY2,
                               const float t_lineZ2 )
{
    // Calculate the squared distance between the sphere center and the line
    const auto l_a = t_lineX2 - t_lineX1;
    const auto l_b = t_lineY2 - t_lineY1;
    const auto l_c = t_lineZ2 - t_lineZ1;
    const auto l_m = (Sphere::m_xPos - t_lineX1) * l_a + (Sphere::m_yPos - t_lineY1) * l_b + (Sphere::m_zPos - t_lineZ1) * l_c;
    const auto l_n = static_cast<float>(std::pow(l_a, 2) + std::pow(l_b, 2) + std::pow(l_c, 2));
    const auto l_p = l_m / l_n;
    const auto l_q = static_cast<float>(std::pow(Sphere::m_xPos - (t_lineX1 + l_p * l_a), 2) + std::pow(Sphere::m_yPos - (t_lineY1 + l_p * l_b), 2) + std::pow(Sphere::m_zPos - (t_lineZ1 + l_p * l_c), 2));

    // Check if the squared distance is less than or equal to the squared radius of the sphere
    return (l_q <= static_cast<float>(std::pow(Sphere::m_radius, 2)));
}
