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
        const uint8_t m_shapeType;

        Cuboid( const float t_xPos, const float t_yPos, const float t_sizeX, const float t_sizeY, const float t_sizeZ, const uint8_t t_color[3] );
        Cuboid();

        virtual float circumscribedSphereRadius() override;
        virtual ShapeContainer pack() override;
        virtual uint8_t shapeToShapeType() override;
        bool lineIntersection( const float t_lx1, const float t_ly1, const float t_lz1, const float t_lx2, const float t_ly2, const float t_lz2 );


        Cuboid( const Cuboid &other )
                : Shape(other), m_xSize(other.m_xSize), m_ySize(other.m_ySize), m_zSize(other.m_zSize), m_shapeType(other.m_shapeType)
        {
            m_xSize = other.m_xSize;
            m_ySize = other.m_ySize;
            m_zSize = other.m_zSize;
            m_color[0] = other.m_color[0];
            m_color[1] = other.m_color[1];
            m_color[2] = other.m_color[2];
        }
};


#endif //MATURITA_RENDERER_CUBOID_HPP
