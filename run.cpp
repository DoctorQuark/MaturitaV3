#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

#include "run.hpp"
#include "Renderer/Renderer.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "Shapes/Cuboid.hpp"
#include "Shapes/Cylinder.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Tetrahedron.hpp"
#include "debugMisc.hpp"

void run( )
{
    // Define global config
    extern ConfigFile g_ConfigFile;

    const auto l_xSize = any_cast<const float>( g_ConfigFile.getConfigValue( "areaWidth" ));
    const auto l_ySize = any_cast<const float>( g_ConfigFile.getConfigValue( "areaHeight" ));

    std::cout << "Place your camera: " << std::endl;
    float l_camXPos{ parseNumericInput( "set position x: ", "Invalid input", -l_xSize / 2.0F, l_xSize / 2.0F ) };
    float l_camYPos{ parseNumericInput( "set position y: ", "Invalid input", -l_ySize / 2.0F, l_ySize / 2.0F ) };
    float l_camFov{ parseNumericInput( "set field of view: ", "Invalid input", 0.0F, 360.0F ) };

    // Make a l_renderer
    Renderer l_renderer( l_camXPos, l_camYPos, l_camFov );

    const float l_minSize = std::min( l_xSize, l_ySize );
    const std::string l_msg{ "Place your objects\n"
                             "[1] for block\n"
                             "[2] for cylinder\n"
                             "[3] for Sphere\n"
                             "[4] for Tetrahedron\n"
                             "[5] to continue\n" };

    int l_shapeType{ parseNumericInput( l_msg, "Invalid input", 0, 6 ) };
    while ( l_shapeType != 5 )
    {
        // Add a shape into the scene
        switch ( l_shapeType )
        {
            case 1:
            {
                l_renderer.addShape(
                        Cuboid(
                                parseNumericInput( "set X position: ", "Invalid input", -l_xSize / 2.0F, l_xSize / 2.0F ),
                                parseNumericInput( "set Y position: ", "Invalid input", -l_ySize / 2.0F, l_ySize / 2.0F ),
                                parseNumericInput( "set X size: ", "Invalid input", 0.0F, l_minSize ),
                                parseNumericInput( "set Y size: ", "Invalid input", 0.0F, l_minSize ),
                                parseNumericInput( "set Z size: ", "Invalid input", 0.0F, l_minSize ),
                                parseColorInput( )
                              ).pack( ));
                break;
            }
            case 2:
            {
                l_renderer.addShape(
                        Cylinder(
                                parseNumericInput( "set X position: ", "Invalid input", -l_xSize / 2.0F, l_xSize / 2.0F ),
                                parseNumericInput( "set Y position: ", "Invalid input", -l_ySize / 2.0F, l_ySize / 2.0F ),
                                parseNumericInput( "set radius: ", "Invalid input", 0.0F, l_minSize ),
                                parseNumericInput( "set height: ", "Invalid input", 0.0F, l_minSize ),
                                parseColorInput( )
                                ).pack( ));
                break;
            }
            case 3:
            {
                l_renderer.addShape(
                        Sphere(
                                parseNumericInput( "set X position: ", "Invalid input", -l_xSize / 2.0F, l_xSize / 2.0F ),
                                parseNumericInput( "set Y position: ", "Invalid input", -l_ySize / 2.0F, l_ySize / 2.0F ),
                                parseNumericInput( "set radius: ", "Invalid input", 0.0F, l_minSize ),
                                parseColorInput( )
                              ).pack( ));
                break;
            }
            case 4:
            {
                l_renderer.addShape(
                        Tetrahedron(
                                parseNumericInput( "set X position: ", "Invalid input", -l_xSize / 2.0F, l_xSize / 2.0F ),
                                parseNumericInput( "set Y position: ", "Invalid input", -l_ySize / 2.0F, l_ySize / 2.0F ),
                                parseNumericInput( "set X size: ", "Invalid input", 0.0F, l_minSize ),
                                parseNumericInput( "set Y size: ", "Invalid input", 0.0F, l_minSize ),
                                parseNumericInput( "set Z size: ", "Invalid input", 0.0F, l_minSize ),
                                parseColorInput( )
                                   ).pack( ));
                break;
            }
            default:
            {
                throwCodeError( "l_shapeType neodpovídá žádnému tvaru", __LINE__, __FILE__, __FUNCTION__ );
            }
        }

        l_shapeType = parseNumericInput( l_msg, "Invalid input", 0, 6 );
    }


    l_renderer.startRender( );
}

int parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const int t_minValue, const int t_maxValue )
{
    int l_outputVar{ };

    std::cout << t_msg << std::endl;

    while ( true )
    {
        std::string l_input{ };
        std::string l_test{ };

        std::cin >> l_input;
        std::istringstream l_ss( l_input );

        bool l_goodInt{ l_ss >> l_outputVar };
        bool l_goodStr{ l_ss >> l_test };

        if ( l_goodInt && !l_goodStr && l_outputVar > t_minValue && l_outputVar < t_maxValue )
        {
            break;
        }

        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << l_input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwCodeError( "progamátor něco podělal", __LINE__, __FILE__, __FUNCTION__ );
        }
        else
        {
            const std::string l_allowedRangeMsg{ "( range: " + std::to_string( t_minValue + 1 ) + " - " + std::to_string( t_maxValue - 1 ) + " )" };
            std::cout << t_errorMsg << " " << l_allowedRangeMsg << ": " << l_input << std::endl;
        }
    }

    return l_outputVar;
}

float parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const float t_minValue, const float t_maxValue )
{
    float l_outputVar{ };

    std::cout << t_msg << std::endl;

    while ( true )
    {
        std::string l_input{ };
        std::string l_test{ };

        std::cin >> l_input;
        std::istringstream l_ss( l_input );

        bool l_goodInt{ l_ss >> l_outputVar };
        bool l_goodStr{ l_ss >> l_test };
        if ( l_goodInt && !l_goodStr && l_outputVar > t_minValue && l_outputVar < t_maxValue )
        {
            break;
        }
        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << l_input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwCodeError( "progamátor něco podělal", __LINE__, __FILE__, __FUNCTION__ );
        }
        else
        {
            const std::string l_allowedRangeMsg{ "( range: " + std::to_string( t_minValue + 0.000001F ) + " - " + std::to_string( t_maxValue - 0.000001F ) + " )" };
            std::cout << t_errorMsg << " " << l_allowedRangeMsg << ": " << l_input << std::endl;
        }
    }

    return l_outputVar;
}

uint8_t *parseColorInput( )
{
    const std::string l_colorMsg{ "Choose l_color:\n"
                                  "[1] for red\n"
                                  "[2] for green\n"
                                  "[3] for blue\n"
                                  "[4] for yellow\n"
                                  "[5] to purple\n"
                                  "[6] to cyan\n"
                                  "[7] to white\n"
                                  "[8] to black\n"
                                  "[9] to light gray\n"
                                  "[10] to gray\n"
                                  "[11] to dark gray\n" };

    static uint8_t l_color[3];

    switch ( parseNumericInput( l_colorMsg, "Wrong input (range 1-11)", 0, 12 ))
    {
        case 1:
        {
            l_color[0] = 255U;
            l_color[1] = 0U;
            l_color[2] = 0U;
            break;
        }
        case 2:
        {
            l_color[0] = 0U;
            l_color[1] = 255U;
            l_color[2] = 0U;
            break;
        }
        case 3:
        {
            l_color[0] = 0U;
            l_color[1] = 0U;
            l_color[2] = 255U;
            break;
        }
        case 4:
        {
            l_color[0] = 255U;
            l_color[1] = 255U;
            l_color[2] = 0U;
            break;
        }
        case 5:
        {
            l_color[0] = 255U;
            l_color[1] = 0U;
            l_color[2] = 255U;
            break;
        }
        case 6:
        {
            l_color[0] = 0U;
            l_color[1] = 255U;
            l_color[2] = 255U;
            break;
        }
        case 7:
        {
            l_color[0] = 255U;
            l_color[1] = 255U;
            l_color[2] = 255U;
            break;
        }
        case 8:
        {
            l_color[0] = 0U;
            l_color[1] = 0U;
            l_color[2] = 0U;
            break;
        }
        case 9:
        {
            l_color[0] = 64U;
            l_color[1] = 64U;
            l_color[2] = 64U;
            break;
        }
        case 10:
        {
            l_color[0] = 128U;
            l_color[1] = 128U;
            l_color[2] = 128U;
            break;
        }
        case 11:
        {
            l_color[0] = 192U;
            l_color[1] = 192U;
            l_color[2] = 192U;
            break;
        }
        default:
        {
            l_color[0] = 80U;
            l_color[1] = 160U;
            l_color[2] = 240U;
            break;
        }
    }

    return l_color;
}
