#ifndef MATURITA_RENDERER_TETRAHEDRON_HPP
#define MATURITA_RENDERER_TETRAHEDRON_HPP

#include "Shape.hpp"

class Tetrahedron : public Shape
{

    public:
        Tetrahedron( const float t_xPos, const float t_yPos, const float t_xSize, const float t_ySize, const float t_zSize, const uint8_t t_color[3] );
        Tetrahedron();

        float m_xSize;
        float m_ySize;
        float m_zSize;

        // The shape ID of the shape
        const uint8_t m_shapeType{ 4U };

        virtual float circumscribedSphereRadius() override;
        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;


        Tetrahedron( const Tetrahedron &t_other ) : m_shapeType{ 1U }
        {
            Tetrahedron::m_xPos = t_other.m_xPos;
            Tetrahedron::m_yPos = t_other.m_yPos;
            Tetrahedron::m_zPos = t_other.m_zPos;
            Tetrahedron::m_xSize = t_other.m_xSize;
            Tetrahedron::m_ySize = t_other.m_ySize;
            Tetrahedron::m_zSize = t_other.m_zSize;
            Tetrahedron::m_color[0] = t_other.m_color[0];
            Tetrahedron::m_color[1] = t_other.m_color[1];
            Tetrahedron::m_color[2] = t_other.m_color[2];
        }

};


#endif //MATURITA_RENDERER_TETRAHEDRON_HPP
