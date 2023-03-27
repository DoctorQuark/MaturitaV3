#ifndef MATURITA_RENDERER_SPHERE_HPP
#define MATURITA_RENDERER_SPHERE_HPP

#include "Shape.hpp"
#include "../Renderer/HitPoint.hpp"

class Sphere : public Shape
{
    public:
        float m_radius;

        // The shape ID of the shape
        uint8_t m_shapeType;

        Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t t_color[3] );
        Sphere( const Sphere &t_other );
        Sphere();

        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        //bool lineIntersection( const float t_lineX1, const float t_lineY1, const float t_lineZ1, const float t_lineX2, const float t_lineY2, const float t_lineZ2 );
        HitPoint lineIntersection( const float t_xStartPos, const float t_yStartPos, const float t_zStartPos, const float t_xEndPos, const float t_yEndPos, const float t_zEndPos );
};


#endif //MATURITA_RENDERER_SPHERE_HPP
