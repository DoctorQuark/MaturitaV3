#include "Block.hpp"

Block::Block( const float t_xPos, const float t_yPos, const float t_sizeX, const float t_sizeY, const float t_sizeZ, const uint8_t t_color[3] )
{
    Block::xPos = t_xPos;
    Block::yPos = t_yPos;
    Block::sizeX = t_sizeX;
    Block::sizeY = t_sizeY;
    Block::sizeZ = t_sizeZ;
    Block::color[0] = t_color[0];
    Block::color[1] = t_color[1];
    Block::color[2] = t_color[2];
}
