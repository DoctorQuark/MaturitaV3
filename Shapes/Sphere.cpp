#include "Sphere.hpp"

Sphere::Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t *t_color )
{
    Sphere::m_xPos = t_xPos;
    Sphere::m_yPos = t_yPos;
    Sphere::m_radius = t_radius;
    Sphere::m_color[0] = t_color[0];
    Sphere::m_color[1] = t_color[1];
    Sphere::m_color[2] = t_color[2];
    Sphere::m_shapeType = 3U;
}

Sphere::Sphere( const Sphere &t_other )
{
    Sphere::m_xPos = t_other.m_xPos;
    Sphere::m_yPos = t_other.m_yPos;
    Sphere::m_zPos = t_other.m_zPos;
    Sphere::m_radius = t_other.m_radius;
    Sphere::m_color[0] = t_other.m_color[0];
    Sphere::m_color[1] = t_other.m_color[1];
    Sphere::m_color[2] = t_other.m_color[2];
    Sphere::m_shapeType = t_other.m_shapeType;
}

Sphere::Sphere()
{
    Sphere::m_shapeType = 3U;
}

ShapeContainer Sphere::pack()
{
    return ShapeContainer(*this);
}

uint8_t Sphere::shapeToShapeType()
{
    return Sphere::m_shapeType;
}

/*
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
*/

HitPoint Sphere::lineIntersection( const float t_xStartPos, const float t_yStartPos, const float t_zStartPos, const float t_xEndPos, const float t_yEndPos, const float t_zEndPos )
{
    // Calculate the direction vector of the line
    const float l_xDir = t_xEndPos - t_xStartPos;
    const float l_yDir = t_yEndPos - t_yStartPos;
    const float l_zDir = t_zEndPos - t_zStartPos;

    // Calculate the coefficients of the quadratic equation
    const float l_a = l_xDir * l_xDir + l_yDir * l_yDir + l_zDir * l_zDir;
    const float l_b = 2.0F * (l_xDir * (t_xStartPos - Sphere::m_xPos) + l_yDir * (t_yStartPos - Sphere::m_yPos) + l_zDir * (t_zStartPos - Sphere::m_zPos));
    const float l_c = (t_xStartPos - Sphere::m_xPos) * (t_xStartPos - Sphere::m_xPos) +
                      (t_yStartPos - Sphere::m_yPos) * (t_yStartPos - Sphere::m_yPos) +
                      (t_zStartPos - Sphere::m_zPos) * (t_zStartPos - Sphere::m_zPos) -
                      Sphere::m_radius * Sphere::m_radius;

    // Calculate the discriminant
    const float l_discriminant = l_b * l_b - 4 * l_a * l_c;

    // Check if the line intersects the sphere
    if ( l_discriminant < 0.0F )
    {
        return HitPoint();
    }

    // Calculate the first intersection point
    const float l_t = (- l_b - std::sqrt(l_discriminant)) / (2 * l_a);
    return HitPoint(t_xStartPos + l_t * l_xDir,
                    t_yStartPos + l_t * l_yDir,
                    t_zStartPos + l_t * l_zDir);
}
