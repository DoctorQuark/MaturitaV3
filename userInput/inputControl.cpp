#include "inputControl.hpp"
#include "config/ConfigFile.hpp"
#include "../miscFunctions.hpp"

#include <iostream>
#include <tuple>

extern ConfigFile g_GlobalConfig;

int chooseAction()
{
    bool m_receivedCorrectInput{ false };
    char m_inputChar{ };

    std::cout << "[R]un" << std::endl;
    std::cout << "[C]onfigure" << std::endl;
    std::cout << "[B]enchmark" << std::endl;
    std::cout << "[T]est" << std::endl;
    std::cout << "[Q]uit!" << std::endl;

    do
    {
        std::cin >> m_inputChar;

        switch ( m_inputChar )
        {

            case 'E':
            case 'e':
            {
                m_receivedCorrectInput = true;
                return 0;
            }
            case 'R':
            case 'r':
            {
                m_receivedCorrectInput = true;
                return 1;
            }
            case 'C':
            case 'c':
            {
                m_receivedCorrectInput = true;
                return 2;
            }
            case 'B':
            case 'b':
            {
                m_receivedCorrectInput = true;
                return 3;
            }
            case 'T':
            case 't':
            {
                m_receivedCorrectInput = true;
                return 4;
            }
            case 'Q':
            case 'q':
            {
                m_receivedCorrectInput = true;
                return 5;
            }
            default:
            {
                throwWarning("Invalid input!", __LINE__, __FILE__);
                break;
            }

        }
    } while ( !m_receivedCorrectInput );

    return -1;
}

void showConfigMenu()
{
    const auto [m_keyOutputFolder, m_valueOutputFolder] = g_GlobalConfig.getConfig("outputFolder");
    const auto [m_keyAreaWidth, m_valueAreaWidth] = g_GlobalConfig.getConfig("areaWidth");
    const auto [m_keyAreaHeight, m_valueAreaHeight] = g_GlobalConfig.getConfig("areaHeight");
    const auto [m_keyResolution, m_valueResolution] = g_GlobalConfig.getConfig("resolution");
    const auto [m_keyRayBounces, m_valueRayBounces] = g_GlobalConfig.getConfig("rayBounces");

    std::cout << "(A)   " << m_valueOutputFolder << ": " << m_keyOutputFolder << std::endl;
    std::cout << "(B)   " << m_valueAreaWidth << ": " << m_keyAreaWidth << std::endl;
    std::cout << "(C)   " << m_valueAreaHeight << ": " << m_keyAreaHeight << std::endl;
    std::cout << "(D)   " << m_keyResolution << ": " << m_valueResolution << std::endl;
    std::cout << "(E)   " << m_keyRayBounces << ": " << m_valueRayBounces << std::endl;

}
