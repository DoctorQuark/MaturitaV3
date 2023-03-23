#include "Cylinder.hpp"

Cylinder::Cylinder( const float t_xPos, const float t_yPos, const float t_radius, const float t_height, const uint8_t t_color[3] )
{
    Cylinder::xPos = t_xPos;
    Cylinder::yPos = t_yPos;
    Cylinder::radius = t_radius;
    Cylinder::height = t_height;
    Cylinder::color[0] = t_color[0];
    Cylinder::color[1] = t_color[1];
    Cylinder::color[2] = t_color[2];

}
