#ifndef MATURITA_RENDERER_TETRAHEDRON_HPP
#define MATURITA_RENDERER_TETRAHEDRON_HPP

#include "Shape.hpp"

class Tetrahedron : public Shape
{

    public:
        Tetrahedron( const float t_xPos, const float t_yPos, const float t_xSize, const float t_ySize, const float t_zSize, const uint8_t t_color[3] );
        Tetrahedron( const Tetrahedron &t_other );
        Tetrahedron();

        float m_xSize;
        float m_ySize;
        float m_zSize;

        // The shape ID of the shape
        uint8_t m_shapeType{ 4U };

        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
};


#endif //MATURITA_RENDERER_TETRAHEDRON_HPP
