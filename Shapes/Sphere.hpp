#ifndef MATURITNA_SPHERE_HPP
#define MATURITNA_SPHERE_HPP

#include <iostream>
#include <vector>

#include "Shape.hpp"

class Sphere : public Shape
{
    public:
        float radius;
        Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t t_color[3] );
};


#endif //MATURITNA_SPHERE_HPP
