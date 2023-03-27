#include <array>
#include <cmath>
#include <fstream>
#include <string>
#include <tuple>
#include <iostream>

#include "Renderer.hpp"
#include "../userInput/config/ConfigFile.hpp"
#include "Rotation.hpp"
#include "rendererMisc.hpp"
#include "../Shapes/Cuboid.hpp"
#include "../Shapes/Cylinder.hpp"
#include "../Shapes/Sphere.hpp"
#include "../Shapes/Tetrahedron.hpp"
#include "../miscFunctions.hpp"
#include "HitPoint.hpp"
#include "../debugMisc.hpp"

Renderer::Renderer( const float t_xPos, const float t_yPos, const float t_fov ) : m_camRot((t_xPos == 0.0F && t_yPos == 0.0F) ? 0.0F : std::atan2( -t_yPos, -t_xPos ), false )
{
    Renderer::m_xCamPos = t_xPos;
    Renderer::m_yCamPos = t_yPos;
    Renderer::m_camFov = t_fov;
}

void Renderer::addShape( const ShapeContainer &t_shapeContainer )
{
    Renderer::m_shapes.push_back( t_shapeContainer );
}

void Renderer::startRender( )
{
    extern ConfigFile g_ConfigFile;

    const auto l_resolution = std::any_cast<unsigned int>( g_ConfigFile.getConfigValue( "resolution" ));
    const float l_angleStep{ Renderer::m_camFov / static_cast<float>(l_resolution - 1U) };
    const auto l_ullRes = static_cast<unsigned long long>(l_resolution);


    for ( unsigned long long int l_i = 0ULL; l_i < l_ullRes; ++l_i )
    {
        const Rotation l_verticalAngle( -(static_cast<float>(l_i) * l_angleStep - Renderer::m_camFov / 2.0F), true );
        for ( unsigned long long int l_j = 0ULL; l_j < l_ullRes; ++l_j )
        {
            const Rotation l_horizontalAngle( -(static_cast<float>(l_j) * l_angleStep - Renderer::m_camFov / 2.0F), true );
            std::array<uint8_t, 3> l_pixel = rayCast( l_horizontalAngle, l_verticalAngle );
            for ( unsigned long long int l_k = 0ULL; l_k < 3ULL; ++l_k )
            {
                Renderer::m_rayCastBuffer[l_i][l_j][l_k] = l_pixel[l_k];
            }
        }
    }

    std::string l_fileName;
    std::cout << "Enter file name: ";
    std::cin >> l_fileName;
    l_fileName = parseFileName( l_fileName );
}

void Renderer::testRenderer( const float t_percentage, const bool t_printAll )
{
    extern ConfigFile g_ConfigFile;

    const auto l_resolution = std::any_cast<unsigned int>( g_ConfigFile.getConfigValue( "resolution" ));
    const float l_angleStep{ Renderer::m_camFov / static_cast<float>(l_resolution - 1U) };
    const auto l_ullRes = static_cast<unsigned long long>(l_resolution);

    const auto l_noRays = std::pow( l_resolution, 2 );

    for ( unsigned long long int l_i = 0ULL; l_i < l_ullRes; ++l_i )
    {
        const Rotation l_verticalAngle( -(static_cast<float>(l_i) * l_angleStep - Renderer::m_camFov / 2.0F), true );
        for ( unsigned long long int l_j = 0ULL; l_j < l_ullRes; ++l_j )
        {
            const Rotation l_horizontalAngle( -(static_cast<float>(l_j) * l_angleStep - Renderer::m_camFov / 2.0F), true );
            const auto [l_xPos, l_yPos, l_zPos] = testRayCast( l_horizontalAngle, l_verticalAngle );

            if ( static_cast<float>((static_cast<double>(l_i * l_ullRes + l_i)) / l_noRays * 100.0) >= t_percentage )
            {
                return;
            }

            if ( t_printAll || (l_i == static_cast<unsigned long long>(std::floor( l_resolution / 2U )) && l_j == static_cast<unsigned long long>(std::floor( l_resolution / 2U ))))
            {
                std::cout << "Pixel coords: [" << "I:" << l_i << " J: " << l_j << "]\n"
                          << "World coords: [X:" << l_xPos << " Y: " << l_yPos << " Z: " << l_zPos << "]\n"
                          << "Cam coords: [X:" << m_xCamPos << " Y: " << m_yCamPos << " Z: " << m_zCamPos << "]\n"
                          << "VA: " << l_verticalAngle.getDegrees( ) << "\t"
                          << "HA: " << l_horizontalAngle.getDegrees( ) << "\t"
                          << "CamRot: " << m_camRot.getDegrees( ) << "\t"
                          << std::endl << std::endl;
            }
        }
    }
}

std::array<uint8_t, 3U> Renderer::rayCast( const Rotation t_horizontalAngle, const Rotation t_verticalAngle )
{
    // Define global config
    extern ConfigFile g_ConfigFile;

    const float l_startX{ Renderer::m_xCamPos };
    const float l_startY{ Renderer::m_yCamPos };
    const float l_startZ{ Renderer::m_zCamPos };
    const auto l_endX{ l_startX + std::any_cast<float>( g_ConfigFile.getConfigValue( "areaWidth" )) * 2.0F * std::cos( Renderer::m_camRot.getRadians( ) + t_horizontalAngle.getRadians( )) };
    const auto l_endY{ l_startY + std::any_cast<float>( g_ConfigFile.getConfigValue( "areaHeight" )) * 2.0F * std::sin( Renderer::m_camRot.getRadians( ) + t_horizontalAngle.getRadians( )) };
    const auto l_endZ{ l_startZ + std::tan( t_verticalAngle.getRadians( )) };

    ShapeContainer l_nearestIntersectedShape;
    float l_nearestIntersectedDistance{ std::numeric_limits<float>::max( ) };

    for ( auto l_shape : Renderer::m_shapes )
    {
        const auto l_hitPoint{ testIntersection( l_shape, l_startX, l_startY, l_startZ, l_endX, l_endY, l_endZ ) };
        const auto l_intersected{ l_hitPoint.getHit( ) };
        throwCodeMessage( "Intersected: " + std::to_string( l_intersected ), __LINE__, __FILE__, __FUNCTION__ );

        if ( l_intersected )
        {
            const auto [l_shapeX, l_shapeY, l_shapeZ] = getPositionFromContainer( l_shape );
            const auto l_distance = distance( Renderer::m_xCamPos, Renderer::m_yCamPos, Renderer::m_zCamPos, l_shapeX, l_shapeY, l_startZ );

            const auto l_test{ l_nearestIntersectedDistance >= l_distance };
            const auto l_msg{ "Distance: " + std::to_string( l_distance ) + ", nearest: " + std::to_string( l_nearestIntersectedDistance ) + ", Bool: " + std::to_string( l_test ) };
            throwCodeMessage( l_msg, __LINE__, __FILE__, __FUNCTION__ );

            if ( l_nearestIntersectedDistance >= l_distance )
            {
                l_nearestIntersectedShape = l_shape;
                l_nearestIntersectedDistance = l_distance;
            }
        }
    }

    const auto l_temp = getColorFromShapeContainer( l_nearestIntersectedShape );
    std::cout << l_temp[0U] << l_temp[1U] << l_temp[2U] << "\n";

    std::array<uint8_t, 3U> l_color{ 140U, 250U, 255U };
    return l_color;
}

std::tuple<float, float, float> Renderer::testRayCast( const Rotation t_horizontalAngle, const Rotation t_verticalAngle )
{
    // Define global config
    extern ConfigFile g_ConfigFile;

    const auto l_startX{ Renderer::m_xCamPos };
    const auto l_startY{ Renderer::m_yCamPos };
    const auto l_startZ{ Renderer::m_zCamPos };
    const auto l_endX{ l_startX + std::any_cast<float>( g_ConfigFile.getConfigValue( "areaWidth" )) * 2.0F * std::cos( Renderer::m_camRot.getRadians( ) + t_horizontalAngle.getRadians( )) };
    const auto l_endY{ l_startY + std::any_cast<float>( g_ConfigFile.getConfigValue( "areaHeight" )) * 2.0F * std::sin( Renderer::m_camRot.getRadians( ) + t_horizontalAngle.getRadians( )) };
    const auto l_endZ{ l_startZ + std::tan( t_verticalAngle.getRadians( )) };

    return std::make_tuple( l_endX, l_endY, l_endZ );
}

void saveBitmap( const std::string &t_filename, const uint8_t *t_data, unsigned int t_width, unsigned int t_height )
{
    std::ofstream l_file( t_filename, std::ios::binary );

    // Bitmap file header
    uint8_t l_header[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    uint32_t l_fileSize = 54U + t_width * t_height * 3U;
    l_header[2] = static_cast<uint8_t>(l_fileSize);
    l_header[3] = static_cast<uint8_t>(l_fileSize >> 8);
    l_header[4] = static_cast<uint8_t>(l_fileSize >> 16);
    l_header[5] = static_cast<uint8_t>(l_fileSize >> 24);
    l_file.write( reinterpret_cast<char *>(l_header), sizeof(l_header));

    // Bitmap info header
    uint8_t l_infoHeader[40] = { 40, 0, 0, 0 };
    l_infoHeader[4] = static_cast<uint8_t>(t_width);
    l_infoHeader[5] = static_cast<uint8_t>(t_width >> 8);
    l_infoHeader[6] = static_cast<uint8_t>(t_width >> 16);
    l_infoHeader[7] = static_cast<uint8_t>(t_width >> 24);
    l_infoHeader[8] = static_cast<uint8_t>(t_height);
    l_infoHeader[9] = static_cast<uint8_t>(t_height >> 8);
    l_infoHeader[10] = static_cast<uint8_t>(t_height >> 16);
    l_infoHeader[11] = static_cast<uint8_t>(t_height >> 24);
    l_infoHeader[12] = 1;
    l_infoHeader[14] = 24;
    l_file.write( reinterpret_cast<char *>(l_infoHeader), sizeof(l_infoHeader));

    // Pixel data
    for ( unsigned int l_y = t_height - 1U; l_y >= 0U; --l_y )
    {
        for ( unsigned int l_x = 0U; l_x < t_width; ++l_x )
        {
            const uint8_t *pixel = t_data + (l_y * t_width + l_x) * 3;
            l_file.write( reinterpret_cast<const char *>(pixel), 3 );
        }
        // Padding
        uint8_t l_padding[] = { 0, 0, 0 };
        int l_paddingSize = (4 - (t_width * 3) % 4) % 4;
        l_file.write( reinterpret_cast<const char *>(l_padding), l_paddingSize );
    }

    l_file.close( );
}
