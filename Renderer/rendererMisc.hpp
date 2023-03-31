#ifndef MATURITA_RENDERER_RENDERERMISC_HPP
#define MATURITA_RENDERER_RENDERERMISC_HPP

#include <tuple>
#include <cmath>

#include "../Shapes/ShapeContainer.hpp"

std::tuple<float, float, float>
closestPointOnLine( float t_linePoint1X, float t_linePoint1Y, float t_linePoint1Z, float t_linePoint2X, float t_linePoint2Y, float t_linePoint2Z, float t_pointX, float t_pointY, float t_pointZ );
float shortestDistance3D( const float t_testedPointX, const float t_testedPointY, const float t_testedPointZ, const float t_startPointX, const float t_startPointY, const float t_startPointZ, const float t_endpointX,
                          const float t_endpointY, const float t_endpointZ );
bool testIntersection( ShapeContainer &t_container, const float t_xStartPos, const float t_yStartPos, const float t_zStartPos, const float t_xEndPos, const float t_yEndPos, const float t_zEndPos );
std::array<uint8_t, 3> getColorFromShapeContainer( ShapeContainer t_container );
float distance( float t_x1, float t_y1, float t_z1, float t_x2, float t_y2, float t_z2 );
std::tuple<float, float, float> getPositionFromContainer( ShapeContainer &t_container );

#endif //MATURITA_RENDERER_RENDERERMISC_HPP
