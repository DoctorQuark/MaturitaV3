#include "test.hpp"
#include "Renderer/Renderer.hpp"
#include "Shapes/Cuboid.hpp"
#include "Shapes/Cylinder.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Tetrahedron.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "miscFunctions.hpp"
#include "debugMisc.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <random>
#include <cstdint>

void test( )
{
    bool m_receivedCorrectInput{ false };
    char m_inputChar{ };

    std::cout << "\nSelect a test:" << std::endl;
    std::cout << "1 - test ray casting" << std::endl;
    std::cout << "2 - test ray casting #2" << std::endl;
    std::cout << "3 - test cam rotation" << std::endl;
    std::cout << "4 - test file name parser" << std::endl;
    std::cout << "5 - test file saving" << std::endl;
    std::cout << "6 - test image data to 1D array conversion" << std::endl;

    do
    {
        std::cin >> m_inputChar;

        switch ( m_inputChar )
        {
            case '1':
            {
                testRayCasting( );
                m_receivedCorrectInput = true;
                break;
            }
            case '2':
            {
                testRayCastingTwo( );
                m_receivedCorrectInput = true;
                break;
            }
            case '3':
            {
                testCamRotation( );
                m_receivedCorrectInput = true;
                break;
            }
            case '4':
            {
                testFilenameParser( );
                m_receivedCorrectInput = true;
                break;
            }
            case '5':
            {
                testFileSave( );
                m_receivedCorrectInput = true;
                break;
            }
            case '6':
            {
                testImageDataTo1DArray( );
                m_receivedCorrectInput = true;
                break;
            }
            default:
            {
                throwCodeWarning( "Invalid input!", __LINE__, __FILE__, __FUNCTION__ );
                break;
            }
        }
    }
    while ( !m_receivedCorrectInput );
}

void testRayCasting( )
{
    extern ConfigFile g_ConfigFile;

    const auto l_xSize = any_cast<const float>( g_ConfigFile.getConfigValue( "areaWidth" ));

    Renderer l_renderer( -l_xSize / 2.0F, 0.0F, 45.0F );
    l_renderer.testRenderer( );
}

void testRayCastingTwo( )
{
    extern ConfigFile g_ConfigFile;

    const float l_testedValues[9][2] = {
            { 1.0F,  1.0F },
            { 1.0F,  0.0F },
            { 1.0F,  -1.0F },
            { .0F,   1.0F },
            { 0.0F,  0.0F },
            { 0.0F,  -1.0F },
            { -1.0F, 1.0F },
            { -1.0F, 0.0F },
            { -1.0F, -1.0F }
    };

    std::cout << std::endl;

    for ( auto l_item : l_testedValues )
    {
        const float l_x = l_item[0];
        const float l_y = l_item[1];

        Renderer l_renderer( l_x, l_y, 45.0F );
        l_renderer.testRenderer( 100.0F, false );
    }
}

void testCamRotation( )
{
    const float l_testedValues[9][2] = {
            { 1.0F,  1.0F },
            { 1.0F,  0.0F },
            { 1.0F,  -1.0F },
            { 0.0F,  1.0F },
            { 0.0F,  0.0F },
            { 0.0F,  -1.0F },
            { -1.0F, 1.0F },
            { -1.0F, 0.0F },
            { -1.0F, -1.0F }
    };

    std::cout << "\nCamera rotation test results:" << std::endl;
    for ( auto l_item : l_testedValues )
    {
        const float l_x = l_item[0];
        const float l_y = l_item[1];

        Renderer l_cam( l_x, l_y, 45.0F );
        std::cout << "[" << l_x << "; " << l_y << "]   \t" << l_cam.m_camRot.getDegrees( ) << std::endl;
    }
}

void testFilenameParser( )
{
    const auto l_correctFileName{ "correctFilename" };
    const auto l_incorrectFileNameWithPath{ "incorrect/filename/with/path" };
    const auto l_fileNameWithCorrectButUnnecessaryButCorrectExtension{ "filenameWithUnnecessaryButCorrectExtension.bmp" };
    const auto l_filenameWithIncorrectExtension{ "filenameWithIncorrect.Extension" };
    const auto l_filenameWithPathAndCorrectExtension{ "filename/with/path/and/correct/extension.bmp" };
    const auto l_filenameWithPathAndIncorrectExtension{ "filename/with/path/and/incorrect.extension" };

    std::cout << std::endl;
    std::cout << "Filename parser test results: " << std::endl;
    std::cout << "Correct file name original: " << l_correctFileName << std::endl;
    std::cout << "Correct file name parsed: " << parseFileName( l_correctFileName ) << std::endl;
    std::cout << std::endl;
    std::cout << "Incorrect file name with path original: " << l_incorrectFileNameWithPath << std::endl;
    std::cout << "Incorrect file name with path parsed: " << parseFileName( l_incorrectFileNameWithPath ) << std::endl;
    std::cout << std::endl;
    std::cout << "File name with correct but unnecessary extension original: " << l_fileNameWithCorrectButUnnecessaryButCorrectExtension << std::endl;
    std::cout << "File name with correct but unnecessary extension parsed: " << parseFileName( l_fileNameWithCorrectButUnnecessaryButCorrectExtension ) << std::endl;
    std::cout << std::endl;
    std::cout << "File name with incorrect extension original: " << l_filenameWithIncorrectExtension << std::endl;
    std::cout << "File name with incorrect extension parsed: " << parseFileName( l_filenameWithIncorrectExtension ) << std::endl;
    std::cout << std::endl;
    std::cout << "File name with path and correct extension original: " << l_filenameWithPathAndCorrectExtension << std::endl;
    std::cout << "File name with path and correct extension parsed: " << parseFileName( l_filenameWithPathAndCorrectExtension ) << std::endl;
    std::cout << std::endl;
    std::cout << "File name with path and incorrect extension original: " << l_filenameWithPathAndIncorrectExtension << std::endl;
    std::cout << "File name with path and incorrect extension parsed: " << parseFileName( l_filenameWithPathAndIncorrectExtension ) << std::endl;
}

void testFileSave( )
{

}

void testImageDataTo1DArray( )
{
    extern ConfigFile g_ConfigFile;

    const auto l_resolution = static_cast<unsigned long long>(std::any_cast<unsigned int>( g_ConfigFile.getConfigValue( "resolution" )));

    unsigned long long l_i{ 0ULL };
    unsigned long long l_j{ 0ULL };
    unsigned long long l_k{ 0ULL };

    std::vector<std::vector<std::vector<uint8_t>>> l_imageData{ };

    std::random_device l_rd;
    std::mt19937 l_gen( l_rd( ));
    std::uniform_int_distribution<uint8_t> l_dis( 0U, 255U );

    std::cout << "resolution: " << std::to_string( l_resolution ) << std::endl;

    l_imageData.resize( l_resolution );
    for ( auto &l_row : l_imageData )
    {
        l_row.resize( l_resolution );

        /*for ( auto &l_pixels : l_row )
        {
            l_pixels.resize( 2ULL );
        }*/
    }

    for ( unsigned long long l_a = 0ULL; l_a < l_resolution; ++l_a )
    {
        for ( unsigned long long l_b = 0ULL; l_b < l_resolution; ++l_b )
        {
            for ( unsigned long long l_c = 0ULL; l_c < 3ULL; ++l_c )
            {
                l_imageData[l_a][l_b].push_back( l_dis( l_gen ));
            }
        }
    }

    const auto l_imageDataAs1DArray = imageDataTo1DArray( l_imageData );

    std::cout << "imageDataAs1DArray: " << sizeof(l_imageDataAs1DArray) / sizeof( uint8_t ) << std::endl;

    for ( const auto &l_item0 : l_imageData )
    {
        for ( const auto &l_item1 : l_item0 )
        {
            for ( const auto l_item2 : l_item1 )
            {
                const bool l_equality{ l_item2 == l_imageDataAs1DArray[l_i * l_resolution * 3ULL + l_j * 3ULL + l_k] };

                std::cout << "Test" << std::endl;
                std::cout << "Input array:" << std::to_string( static_cast<int>(l_item2))
                          << " Output array:" << std::to_string( static_cast<int>(l_imageDataAs1DArray[l_i * l_resolution * 3ULL + l_j * 3ULL + l_k]))
                          << " equality:" << (l_equality ? "true" : "false")
                          << std::endl;
                ++l_k;
            }
            ++l_j;
            l_k = 0ULL;
        }
        ++l_i;
        l_j = 0ULL;
    }
}
