#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

#include "run.hpp"
#include "Renderer/Renderer.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "miscFunctions.hpp"
#include "Shapes/Cuboid.hpp"
#include "Shapes/Cylinder.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Tetrahedron.hpp"

void run()
{
    // Define global config
    extern ConfigFile g_GlobalConfig;

    const auto l_xSize = any_cast<const float>(g_GlobalConfig.getConfigValue("areaWidth"));
    const auto l_ySize = any_cast<const float>(g_GlobalConfig.getConfigValue("areaHeight"));

    std::cout << "Place your camera: " << std::endl;
    float l_camXPos{ parseNumericInput("set position x: ", "Invalid input", -l_xSize / 2, l_xSize / 2) };
    float l_camYPos{ parseNumericInput("set position y: ", "Invalid input", -l_ySize / 2, l_ySize / 2) };
    float l_camFov{ parseNumericInput("set field of view: ", "Invalid input", 0.0f, 360.0f) };

    // Make a l_renderer
    Renderer l_renderer(l_camXPos, l_camYPos, l_camFov);

    const float l_minSize = std::min(l_xSize, l_ySize);
    const std::string l_msg{ "Place your objects\n"
                             "[1] for block\n"
                             "[2] for cylinder\n"
                             "[3] for Sphere\n"
                             "[4] for Tetrahedron\n"
                             "[5] to continue\n" };

    int l_shapeType{ parseNumericInput(l_msg, "Invalid input", 0, 6) };
    while ( l_shapeType != 5 )
    {
        // Add a shape into the scene
        switch ( l_shapeType )
        {
            case 1:
                l_renderer.addShape(
                        Cuboid(
                                parseNumericInput("set X position: ", "Invalid input", -l_xSize / 2, l_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -l_ySize / 2, l_ySize / 2),
                                parseNumericInput("set X size: ", "Invalid input", 0.0f, l_minSize),
                                parseNumericInput("set Y size: ", "Invalid input", 0.0f, l_minSize),
                                parseNumericInput("set Z size: ", "Invalid input", 0.0f, l_minSize),
                                parseColorInput()
                        ).pack());
                break;
            case 2:
                l_renderer.addShape(
                        Cylinder(
                                parseNumericInput("set X position: ", "Invalid input", -l_xSize / 2, l_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -l_ySize / 2, l_ySize / 2),
                                parseNumericInput("set radius: ", "Invalid input", 0.0f, l_minSize),
                                parseNumericInput("set height: ", "Invalid input", 0.0f, l_minSize),
                                parseColorInput()
                        ).pack());
                break;
            case 3:
                l_renderer.addShape(
                        Sphere(
                                parseNumericInput("set X position: ", "Invalid input", -l_xSize / 2, l_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -l_ySize / 2, l_ySize / 2),
                                parseNumericInput("set radius: ", "Invalid input", 0.0f, l_minSize),
                                parseColorInput()
                        ).pack());
                break;
            case 4:
                l_renderer.addShape(Tetrahedron(
                        parseNumericInput("set X position: ", "Invalid input", -l_xSize / 2, l_xSize / 2),
                        parseNumericInput("set Y position: ", "Invalid input", -l_ySize / 2, l_ySize / 2),
                        parseNumericInput("set X size: ", "Invalid input", 0.0f, l_minSize),
                        parseNumericInput("set Y size: ", "Invalid input", 0.0f, l_minSize),
                        parseNumericInput("set Z size: ", "Invalid input", 0.0f, l_minSize),
                        parseColorInput()
                ).pack());
                break;
            default:
                throwError("l_shapeType neodpovídá žádnému tvaru", __LINE__, __FILE__);
                break;
        }

        l_shapeType = parseNumericInput(l_msg, "Invalid input", 0, 6);
    }


    l_renderer.startRender();
}

int parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const int t_minValue, const int t_maxValue )
{
    int l_outputVar{ };

    std::cout << t_msg << std::endl;

    while ( true )
    {
        std::string l_input, test;
        std::cin >> l_input;
        std::istringstream ss(l_input);
        bool l_goodInt{ ss >> l_outputVar };
        bool l_goodStr{ ss >> test };
        if ( l_goodInt && !l_goodStr && l_outputVar > t_minValue && l_outputVar < t_maxValue ) break;
        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << l_input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwError("progamátor něco podělal", __LINE__, __FILE__);
        }
        else
        {
            const std::string l_allowedRangeMsg{ "( range: " + std::to_string(t_minValue + 1) + " - " + std::to_string(t_maxValue - 1) + " )" };
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
        std::string l_input, test;
        std::cin >> l_input;
        std::istringstream ss(l_input);
        bool l_goodInt{ ss >> l_outputVar };
        bool l_goodStr{ ss >> test };
        if ( l_goodInt && !l_goodStr && l_outputVar > t_minValue && l_outputVar < t_maxValue ) break;
        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << l_input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwError("progamátor něco podělal", __LINE__, __FILE__);
        }
        else
        {
            const std::string l_allowedRangeMsg{ "( range: " + std::to_string(t_minValue + 0.000001f) + " - " + std::to_string(t_maxValue - 0.000001f) + " )" };
            std::cout << t_errorMsg << " " << l_allowedRangeMsg << ": " << l_input << std::endl;
        }
    }

    return l_outputVar;
}

uint8_t *parseColorInput()
{
    const std::string l_ColorMsg{ "Choose l_color:\n"
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

    switch ( parseNumericInput(l_ColorMsg, "Wrong input (range 1-11)", 0, 12))
    {
        case 1:
            l_color[0] = 255;
            l_color[1] = 0;
            l_color[2] = 0;
            break;
        case 2:
            l_color[0] = 0;
            l_color[1] = 255;
            l_color[2] = 0;
            break;
        case 3:
            l_color[0] = 0;
            l_color[1] = 0;
            l_color[2] = 255;
            break;
        case 4:
            l_color[0] = 255;
            l_color[1] = 255;
            l_color[2] = 0;
            break;
        case 5:
            l_color[0] = 255;
            l_color[1] = 0;
            l_color[2] = 255;
            break;
        case 6:
            l_color[0] = 0;
            l_color[1] = 255;
            l_color[2] = 255;
            break;
        case 7:
            l_color[0] = 255;
            l_color[1] = 255;
            l_color[2] = 255;
            break;
        case 8:
            l_color[0] = 0;
            l_color[1] = 0;
            l_color[2] = 0;
            break;
        case 9:
            l_color[0] = 64;
            l_color[1] = 64;
            l_color[2] = 64;
            break;
        case 10:
            l_color[0] = 128;
            l_color[1] = 128;
            l_color[2] = 128;
            break;
        case 11:
            l_color[0] = 192;
            l_color[1] = 192;
            l_color[2] = 192;
            break;
        default:
            l_color[0] = 80;
            l_color[1] = 160;
            l_color[2] = 240;
            break;
    }

    return l_color;
}
