#include <string>
#include <tuple>
#include <variant>
#include <array>

#include "hitPoint.hpp"
#include "rendererMisc.hpp"
#include "../Shapes/Cuboid.hpp"
#include "../Shapes/Cylinder.hpp"
#include "../Shapes/Sphere.hpp"
#include "../Shapes/Tetrahedron.hpp"
#include "../debugMisc.hpp"

// nearest point on a line
std::tuple<float, float, float>
closestPointOnLine( const float t_linePoint1X, const float t_linePoint1Y, const float t_linePoint1Z, const float t_linePoint2X, const float t_linePoint2Y, const float t_linePoint2Z, const float t_pointX,
                    const float t_pointY, const float t_pointZ
                  )
{
    const float l_lineVectorX = t_linePoint2X - t_linePoint1X;
    const float l_lineVectorY = t_linePoint2Y - t_linePoint1Y;
    const float l_lineVectorZ = t_linePoint2Z - t_linePoint1Z;
    const float l_pointVectorX = t_pointX - t_linePoint1X;
    const float l_pointVectorY = t_pointY - t_linePoint1Y;
    const float l_pointVectorZ = t_pointZ - t_linePoint1Z;
    const float l_lineVectorLength = std::sqrt( l_lineVectorX * l_lineVectorX + l_lineVectorY * l_lineVectorY + l_lineVectorZ * l_lineVectorZ );
    const float l_unitLineVectorX = l_lineVectorX / l_lineVectorLength;
    const float l_unitLineVectorY = l_lineVectorY / l_lineVectorLength;
    const float l_unitLineVectorZ = l_lineVectorZ / l_lineVectorLength;
    const float l_t = l_unitLineVectorX * l_pointVectorX + l_unitLineVectorY * l_pointVectorY + l_unitLineVectorZ * l_pointVectorZ;
    const std::tuple<float, float, float> l_closestPoint( t_linePoint1X + l_unitLineVectorX * l_t, t_linePoint1Y + l_unitLineVectorY * l_t, t_linePoint1Z + l_unitLineVectorZ * l_t );
    return l_closestPoint;
}

// shortest distance between a point and a line
float shortestDistance3D( const float t_testedPointX, const float t_testedPointY, const float t_testedPointZ, const float t_startPointX, const float t_startPointY, const float t_startPointZ, const float t_endpointX,
                          const float t_endpointY, const float t_endpointZ
                        )
{
    // Define the vector AB
    const auto l_aBx = t_endpointX - t_startPointX;
    const auto l_aBy = t_endpointY - t_startPointY;
    const auto l_aBz = t_endpointZ - t_startPointZ;


    // Define the vector AP
    const auto l_aPx = t_testedPointX - t_startPointX;
    const auto l_aPy = t_testedPointY - t_startPointY;
    const auto l_aPz = t_testedPointZ - t_startPointZ;

    // Calculate the projection of AP onto AB
    const auto l_proj = (l_aPx * l_aBx + l_aPy * l_aBy + l_aPz * l_aBz) / (l_aBx * l_aBx + l_aBy * l_aBy + l_aBz * l_aBz);

    // Calculate the closest point on the line AB to the point P
    const auto l_closestPointX = t_startPointX + l_proj * l_aBx;
    const auto l_closestPointY = t_startPointY + l_proj * l_aBy;
    const auto l_closestPointZ = t_startPointZ + l_proj * l_aBz;

    // Calculate the distance between the point P and the closest point on the line AB
    const auto l_distance = std::sqrt((t_testedPointX - l_closestPointX) * (t_testedPointX - l_closestPointX)
                                      + (t_testedPointY - l_closestPointY) * (t_testedPointY - l_closestPointY)
                                      + (t_testedPointZ - l_closestPointZ) * (t_testedPointZ - l_closestPointZ));

    return l_distance;
}

HitPoint testIntersection( ShapeContainer &t_container, const float t_xStartPos, const float t_yStartPos, const float t_zStartPos, const float t_xEndPos, const float t_yEndPos, const float t_zEndPos )
{
    const auto l_testedShape = t_container.unpack( );

    switch ( t_container.m_shapeType )
    {
        case 1:
        {
            Cuboid l_shape = std::get<Cuboid>( l_testedShape );
            //throwCodeMessage("Testing intersection for shape: " + std::to_string(l_shape.m_shapeType), __LINE__, __FILE__);
            //return l_shape.lineIntersection(t_xStartPos, t_yStartPos, t_zStartPos, t_xEndPos, t_yEndPos, t_zEndPos);
            return HitPoint( );
        }
        case 2:
        {
            Cylinder l_shape = std::get<Cylinder>( l_testedShape );
            //throwCodeMessage("Testing intersection for shape: " + std::to_string(l_shape.m_shapeType), __LINE__, __FILE__);
            //return l_shape.lineIntersection(t_xStartPos, t_yStartPos, t_zStartPos, t_xEndPos, t_yEndPos, t_zEndPos);
            return HitPoint( );
        }
        case 3:
        {
            Sphere l_shape = std::get<Sphere>( l_testedShape );
            //throwCodeMessage("Testing intersection for shape: " + std::to_string(l_shape.m_shapeType), __LINE__, __FILE__);
            return l_shape.lineIntersection( t_xStartPos, t_yStartPos, t_zStartPos, t_xEndPos, t_yEndPos, t_zEndPos );
        }
        case 4:
        {
            Tetrahedron l_shape = std::get<Tetrahedron>( l_testedShape );
            //throwCodeMessage("Testing intersection for shape: " + std::to_string(l_shape.m_shapeType), __LINE__, __FILE__);
            return HitPoint( );
        }
        default:
        {
            throwCodeError( std::string( "Unknown shape type: " ) + std::to_string( t_container.m_shapeType ), __LINE__, __FILE__, __FUNCTION__ );
        }
    }
}

std::array<uint8_t, 3U> getColorFromShapeContainer( ShapeContainer t_container )
{
    const auto l_testedShape = t_container.unpack( );

    switch ( t_container.m_shapeType )
    {
        case 1:
        {
            Cuboid l_shape = std::get<Cuboid>( l_testedShape );
            std::array<uint8_t, 3U> l_color{ };
            l_color[0U] = l_shape.m_color[0];
            l_color[1U] = l_shape.m_color[1];
            l_color[2U] = l_shape.m_color[2];
            return l_color;
        }
        case 2:
        {
            Cylinder l_shape = std::get<Cylinder>( l_testedShape );
            std::array<uint8_t, 3U> l_color{ };
            l_color[0U] = l_shape.m_color[0];
            l_color[1U] = l_shape.m_color[1];
            l_color[2U] = l_shape.m_color[2];
            return l_color;
        }
        case 3:
        {
            Sphere l_shape = std::get<Sphere>( l_testedShape );
            std::array<uint8_t, 3U> l_color{ };
            l_color[0U] = l_shape.m_color[0];
            l_color[1U] = l_shape.m_color[1];
            l_color[2U] = l_shape.m_color[2];
            return l_color;
        }
        case 4:
        {
            Tetrahedron l_shape = std::get<Tetrahedron>( l_testedShape );
            std::array<uint8_t, 3U> l_color{ };
            l_color[0U] = l_shape.m_color[0];
            l_color[1U] = l_shape.m_color[1];
            l_color[2U] = l_shape.m_color[2];
            return l_color;
        }
        default:
        {
            std::array<uint8_t, 3U> l_color{ };
            l_color[0U] = 90U;
            l_color[1U] = 60U;
            l_color[2U] = 30U;
            return l_color;
        }
    }
}

float distance( float t_x1, float t_y1, float t_z1, float t_x2, float t_y2, float t_z2 )
{
    float l_dx = t_x2 - t_x1;
    float l_dy = t_y2 - t_y1;
    float l_dz = t_z2 - t_z1;
    return static_cast<float>(std::sqrt( std::pow( l_dx, 2 ) + std::pow( l_dy, 2 ) + std::pow( l_dz, 2 )));
}

std::tuple<float, float, float> getPositionFromContainer( ShapeContainer &t_container )
{
    const auto l_testedShape = t_container.unpack( );

    switch ( t_container.m_shapeType )
    {
        case 1:
        {
            Cuboid l_shape = std::get<Cuboid>( l_testedShape );
            return std::make_tuple( l_shape.m_xPos, l_shape.m_yPos, l_shape.m_zPos );
        }
        case 2:
        {
            Cylinder l_shape = std::get<Cylinder>( l_testedShape );
            return std::make_tuple( l_shape.m_xPos, l_shape.m_yPos, l_shape.m_zPos );
        }
        case 3:
        {
            Sphere l_shape = std::get<Sphere>( l_testedShape );
            return std::make_tuple( l_shape.m_xPos, l_shape.m_yPos, l_shape.m_zPos );
        }
        case 4:
        {
            Tetrahedron l_shape = std::get<Tetrahedron>( l_testedShape );
            return std::make_tuple( l_shape.m_xPos, l_shape.m_yPos, l_shape.m_zPos );
        }
        default:
        {
            return std::make_tuple( -1, -1, -1 );
        }
    }
}
