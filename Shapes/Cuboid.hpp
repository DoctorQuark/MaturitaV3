#ifndef MATURITA_RENDERER_CUBOID_HPP
#define MATURITA_RENDERER_CUBOID_HPP

#include "Shape.hpp"

class Cuboid : public Shape
{
    public:
        float m_xSize;
        float m_ySize;
        float m_zSize;

        // The shape ID of the shape
        uint8_t m_shapeType;

        Cuboid( const float t_xPos, const float t_yPos, const float t_sizeX, const float t_sizeY, const float t_sizeZ, const uint8_t t_color[3] );
        Cuboid( const Cuboid &t_other );
        Cuboid();

        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        bool lineIntersection( const float t_lx1, const float t_ly1, const float t_lz1, const float t_lx2, const float t_ly2, const float t_lz2 );
};


#endif //MATURITA_RENDERER_CUBOID_HPP
