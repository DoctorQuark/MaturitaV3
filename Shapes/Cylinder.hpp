#ifndef MATURITA_RENDERER_CYLINDER_HPP
#define MATURITA_RENDERER_CYLINDER_HPP

#include "Shape.hpp"

class Cylinder : public Shape
{
    public:
        float m_radius;
        float m_height;

        // The shape ID of the shape
        uint8_t m_shapeType;

        Cylinder( const float t_xPos, const float t_yPos, const float t_radius, const float t_height, const uint8_t t_color[3] );
        Cylinder( const Cylinder &t_other );
        Cylinder();

        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        bool lineIntersection( float t_lineX1, float t_lineY1, float t_lineZ1, float t_lineX2, float t_lineY2, float t_lineZ2 );
};


#endif //MATURITA_RENDERER_CYLINDER_HPP
