#include <iostream>
#include <sstream>
#include <tuple>

#include "run.hpp"
#include "Renderer/Renderer.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "miscFunctions.hpp"
#include "Shapes/Block.hpp"
#include "Shapes/Cylinder.hpp"
#include "Shapes/Shape.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Tetrahedron.hpp"

void run()
{
    // Define global config
    extern ConfigFile GlobalConfig;

    const auto m_xSize = any_cast<const float>(GlobalConfig.getConfigValue("areaWidth"));
    const auto m_ySize = any_cast<const float>(GlobalConfig.getConfigValue("areaHeight"));

    std::cout << "Place your camera: " << std::endl;
    float camXPos{ parseNumericInput("set position x: ", "Invalid input", -m_xSize / 2, m_xSize / 2) };
    float camYPos{ parseNumericInput("set position y: ", "Invalid input", -m_ySize / 2, m_ySize / 2) };
    float camFOV{ parseNumericInput("set field of view: ", "Invalid input", 0.0f, 360.0f) };

    // Make a cam
    Renderer cam(camXPos, camYPos, camFOV);

    const float m_minSize = std::min(m_xSize, m_ySize);
    const std::string m_msg{ "Place your objects\n"
                             "[1] for block\n"
                             "[2] for cylinder\n"
                             "[3] for Sphere\n"
                             "[4] for Tetrahedron\n"
                             "[5] to continue\n" };
    int shapeType{ parseNumericInput(m_msg, "Invalid input", 0, 6) };
    while ( shapeType != 5 )
    {
        // Add a shape into the scene
        switch ( shapeType )
        {
            case 1:
                cam.addShape(
                        Block(
                                parseNumericInput("set X position: ", "Invalid input", -m_xSize / 2, m_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -m_ySize / 2, m_ySize / 2),
                                parseNumericInput("set X size: ", "Invalid input", 0.0f, m_minSize),
                                parseNumericInput("set Y size: ", "Invalid input", 0.0f, m_minSize),
                                parseNumericInput("set Z size: ", "Invalid input", 0.0f, m_minSize),
                                parseColorInput()
                        ));
                break;
            case 2:
                cam.addShape(
                        Cylinder(
                                parseNumericInput("set X position: ", "Invalid input", -m_xSize / 2, m_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -m_ySize / 2, m_ySize / 2),
                                parseNumericInput("set radius: ", "Invalid input", 0.0f, m_minSize),
                                parseNumericInput("set height: ", "Invalid input", 0.0f, m_minSize),
                                parseColorInput()
                        ));
                break;
            case 3:
                cam.addShape(
                        Sphere(
                                parseNumericInput("set X position: ", "Invalid input", -m_xSize / 2, m_xSize / 2),
                                parseNumericInput("set Y position: ", "Invalid input", -m_ySize / 2, m_ySize / 2),
                                parseNumericInput("set radius: ", "Invalid input", 0.0f, m_minSize),
                                parseColorInput()
                        ));
                break;
            case 4:
                cam.addShape(Tetrahedron(
                        parseNumericInput("set X position: ", "Invalid input", -m_xSize / 2, m_xSize / 2),
                        parseNumericInput("set Y position: ", "Invalid input", -m_ySize / 2, m_ySize / 2),
                        parseNumericInput("set X size: ", "Invalid input", 0.0f, m_minSize),
                        parseNumericInput("set Y size: ", "Invalid input", 0.0f, m_minSize),
                        parseNumericInput("set Z size: ", "Invalid input", 0.0f, m_minSize),
                        parseColorInput()
                ));
                break;
            default:
                throwError("shapeType neodpovídá žádnému tvaru", __LINE__, __FILE__);
                break;
        }

        shapeType = parseNumericInput(m_msg, "Invalid input", 0, 6);
    }
}

int parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const int t_minValue, const int t_maxValue )
{
    int outputVar{ };

    std::cout << t_msg << std::endl;

    while ( true )
    {
        std::string input, test;
        std::cin >> input;
        std::istringstream ss(input);
        bool goodInt{ ss >> outputVar };
        bool goodStr{ ss >> test };
        if ( goodInt && !goodStr && outputVar > t_minValue && outputVar < t_maxValue ) break;
        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwError("progamátor něco podělal", __LINE__, __FILE__);
        }
        else
        {
            const std::string allowedRangeMsg{ "( range: " + std::to_string(t_minValue + 1) + " - " + std::to_string(t_maxValue - 1) + " )" };
            std::cout << t_errorMsg << " " << allowedRangeMsg << ": " << input << std::endl;
        }
    }

    return outputVar;
}

float parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const float t_minValue, const float t_maxValue )
{
    float outputVar{ };

    std::cout << t_msg << std::endl;

    while ( true )
    {
        std::string input, test;
        std::cin >> input;
        std::istringstream ss(input);
        bool goodInt{ ss >> outputVar };
        bool goodStr{ ss >> test };
        if ( goodInt && !goodStr && outputVar > t_minValue && outputVar < t_maxValue ) break;
        if ( t_minValue > t_maxValue )
        {
            std::cout << t_errorMsg << ": " << input << std::endl;
        }
        else if ( t_minValue == t_maxValue )
        {
            throwError("progamátor něco podělal", __LINE__, __FILE__);
        }
        else
        {
            const std::string allowedRangeMsg{ "( range: " + std::to_string(t_minValue + 0.000001f) + " - " + std::to_string(t_maxValue - 0.000001f) + " )" };
            std::cout << t_errorMsg << " " << allowedRangeMsg << ": " << input << std::endl;
        }
    }

    return outputVar;
}

uint8_t *parseColorInput()
{
    const std::string m_colorMsg{ "Choose color:\n"
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

    static uint8_t color[3];

    switch ( parseNumericInput(m_colorMsg, "Wrong input (range 1-11)", 0, 12))
    {
        case 1:
            color[0] = 255;
            color[1] = 0;
            color[2] = 0;
            break;
        case 2:
            color[0] = 0;
            color[1] = 255;
            color[2] = 0;
            break;
        case 3:
            color[0] = 0;
            color[1] = 0;
            color[2] = 255;
            break;
        case 4:
            color[0] = 255;
            color[1] = 255;
            color[2] = 0;
            break;
        case 5:
            color[0] = 255;
            color[1] = 0;
            color[2] = 255;
            break;
        case 6:
            color[0] = 0;
            color[1] = 255;
            color[2] = 255;
            break;
        case 7:
            color[0] = 255;
            color[1] = 255;
            color[2] = 255;
            break;
        case 8:
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            break;
        case 9:
            color[0] = 64;
            color[1] = 64;
            color[2] = 64;
            break;
        case 10:
            color[0] = 128;
            color[1] = 128;
            color[2] = 128;
            break;
        case 11:
            color[0] = 192;
            color[1] = 192;
            color[2] = 192;
            break;
        default:
            color[0] = 80;
            color[1] = 160;
            color[2] = 240;
            break;
    }

    return color;
}
