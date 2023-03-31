#ifndef MATURITA_RENDERER_SPHERE_HPP
#define MATURITA_RENDERER_SPHERE_HPP

#include "Shape.hpp"

class Sphere : public Shape
{
    public:
        float m_radius;

        // The shape ID of the shape
        const uint8_t m_shapeType{ 3U };

        Sphere( const float t_xPos, const float t_yPos, const float t_radius, const uint8_t t_color[3] );
        Sphere();

        virtual float circumscribedSphereRadius() override;
        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        bool lineIntersection( const float t_lineX1, const float t_lineY1, const float t_lineZ1, const float t_lineX2, const float t_lineY2,
                               const float t_lineZ2 );

        Sphere( const Sphere &t_other ) : m_shapeType{ 1U }
        {
            Sphere::m_xPos = t_other.m_xPos;
            Sphere::m_yPos = t_other.m_yPos;
            Sphere::m_zPos = t_other.m_zPos;
            Sphere::m_radius = t_other.m_radius;
            Sphere::m_color[0] = t_other.m_color[0];
            Sphere::m_color[1] = t_other.m_color[1];
            Sphere::m_color[2] = t_other.m_color[2];
        }


};


#endif //MATURITA_RENDERER_SPHERE_HPP
