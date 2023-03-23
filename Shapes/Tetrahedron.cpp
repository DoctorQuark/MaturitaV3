#include "Tetrahedron.hpp"

Tetrahedron::Tetrahedron( const float t_xPos, const float t_yPos, const float t_xSize, const float t_ySize, const float t_zSize, const uint8_t t_color[3] )
{
    Tetrahedron::xPos = t_xPos;
    Tetrahedron::yPos = t_yPos;
    Tetrahedron::xSize = t_xSize;
    Tetrahedron::ySize = t_ySize;
    Tetrahedron::zSize = t_zSize;
    Tetrahedron::color[0] = t_color[0];
    Tetrahedron::color[1] = t_color[1];
    Tetrahedron::color[2] = t_color[2];
}
