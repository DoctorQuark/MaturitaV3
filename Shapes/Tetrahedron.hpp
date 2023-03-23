#ifndef MATURITA_RENDERER_TETRAHEDRON_HPP
#define MATURITA_RENDERER_TETRAHEDRON_HPP

#include "Shape.hpp"

class Tetrahedron : public Shape
{

    public:
        Tetrahedron( const float t_xPos, const float t_yPos, const float t_xSize, const float t_ySize, const float t_zSize, const uint8_t t_color[3] );

        float xSize;
        float ySize;
        float zSize;
};


#endif //MATURITA_RENDERER_TETRAHEDRON_HPP
