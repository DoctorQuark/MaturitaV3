#ifndef MATURITA_RENDERER_CYLINDER_HPP
#define MATURITA_RENDERER_CYLINDER_HPP

#include "Shape.hpp"

class Cylinder : public Shape
{
    public:
        float m_radius;
        float m_height;

        // The shape ID of the shape
        const uint8_t m_shapeType{ 2U };

        Cylinder( const float t_xPos, const float t_yPos, const float t_radius, const float t_height, const uint8_t t_color[3] );
        Cylinder();

        virtual float circumscribedSphereRadius() override;
        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        bool lineIntersection( float t_lineX1, float t_lineY1, float t_lineZ1, float t_lineX2, float t_lineY2, float t_lineZ2 );

        Cylinder( const Cylinder &t_other ) : m_shapeType{ 1U }
        {
            Cylinder::m_xPos = t_other.m_xPos;
            Cylinder::m_yPos = t_other.m_yPos;
            Cylinder::m_zPos = t_other.m_zPos;
            Cylinder::m_height = t_other.m_height;
            Cylinder::m_radius = t_other.m_radius;
            Cylinder::m_color[0] = t_other.m_color[0];
            Cylinder::m_color[1] = t_other.m_color[1];
            Cylinder::m_color[2] = t_other.m_color[2];
        }
};


#endif //MATURITA_RENDERER_CYLINDER_HPP
