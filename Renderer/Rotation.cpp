#include <cmath>

#include "Rotation.hpp"

float Rotation::getDegrees() const
{
    return Rotation::m_degrees;
}

void Rotation::setDegrees( const float t_newAngle )
{
    Rotation::m_degrees = t_newAngle;
    Rotation::m_radians = Rotation::m_degrees * float(M_PI / 180.0);
}

float Rotation::getRadians() const
{
    return Rotation::m_radians;
}

void Rotation::setRadians( const float t_newAngle )
{
    Rotation::m_degrees = t_newAngle * float(180.0 / M_PI);
    Rotation::m_radians = t_newAngle;
}

Rotation::Rotation( const float t_newAngle, const bool t_isDegrees = false )
{
    m_degrees = t_isDegrees ? t_newAngle : t_newAngle * float(180.0 / M_PI);
    m_radians = !t_isDegrees ? t_newAngle : t_newAngle * float(M_PI / 180.0);
}
