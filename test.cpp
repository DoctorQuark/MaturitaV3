#include "test.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Rotation.hpp"
#include "Shapes/Cuboid.hpp"
#include "Shapes/Cylinder.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Tetrahedron.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "miscFunctions.hpp"
#include "Renderer/Rotation.hpp"

#include <cmath>
#include <initializer_list>
#include <cmath>

void test()
{
    bool m_receivedCorrectInput{ false };
    char m_inputChar{ };

    std::cout << "\nSelect a test:" << std::endl;
    std::cout << "1 - test ray casting" << std::endl;
    std::cout << "2 - test ray casting #2" << std::endl;
    std::cout << "3 - test cam rotation" << std::endl;

    do
    {
        std::cin >> m_inputChar;

        switch ( m_inputChar )
        {
            case '1':
                testRayCasting();
                m_receivedCorrectInput = true;
                break;
            case '2':
                testRayCastingTwo();
                m_receivedCorrectInput = true;
                break;
            case '3':
                testCamRotation();
                m_receivedCorrectInput = true;
                break;
            default:
                throwWarning("Invalid input!", __LINE__, __FILE__);
                break;
        }
    } while ( !m_receivedCorrectInput );
}

void testRayCasting()
{
    extern ConfigFile g_GlobalConfig;

    const auto l_xSize = any_cast<const float>(g_GlobalConfig.getConfigValue("areaWidth"));

    Renderer l_renderer(-l_xSize / 2.0F, 0.0F, 45.0F);
    l_renderer.testRenderer();
}

void testRayCastingTwo()
{
    extern ConfigFile g_GlobalConfig;

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

        Renderer l_renderer(l_x, l_y, 45.0F);
        l_renderer.testRenderer(100.0F, false);
    }
}

void testCamRotation()
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

        Renderer l_cam(l_x, l_y, 45.0F);
        std::cout << "[" << l_x << "; " << l_y << "]   \t" << l_cam.m_camRot.getDegrees() << std::endl;
    }
}
