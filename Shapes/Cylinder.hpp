#ifndef MATURITA_RENDERER_CYLINDER_HPP
#define MATURITA_RENDERER_CYLINDER_HPP

#include "Shape.hpp"

class Cylinder : public Shape
{
    public:
        Cylinder( const float t_xPos, const float t_yPos, const float t_radius, const float t_height, const uint8_t t_color[3] );

        float radius;
        float height;
};


#endif //MATURITA_RENDERER_CYLINDER_HPP
