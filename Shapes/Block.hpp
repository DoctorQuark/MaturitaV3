#ifndef MATURITA_RENDERER_BLOCK_HPP
#define MATURITA_RENDERER_BLOCK_HPP

#include "Shape.hpp"

class Block : public Shape
{
    public:
        float sizeX;
        float sizeY;
        float sizeZ;

        Block( const float t_xPos, const float t_yPos, const float t_sizeX, const float t_sizeY, const float t_sizeZ, const uint8_t t_color[3] );
};


#endif //MATURITA_RENDERER_BLOCK_HPP
