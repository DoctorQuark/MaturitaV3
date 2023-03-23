#include "Sphere.hpp"
#include <iostream>
#include <vector>

Sphere::Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t *t_color )
{
    Sphere::xPos = t_xPos;
    Sphere::yPos = t_yPos;
    Sphere::radius = t_radius;
    Sphere::color[0] = t_color[0];
    Sphere::color[1] = t_color[1];
    Sphere::color[2] = t_color[2];
}
