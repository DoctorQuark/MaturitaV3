#include "inputControl.hpp"

#include <iostream>

int chooseAction()
{
    bool m_receivedCorrectInput{ false };
    char m_inputChar{ };

    std::cout << "[R]un" << std::endl;
    std::cout << "[C]onfigure" << std::endl;
    std::cout << "[B]enchmark" << std::endl;
    std::cout << "[T]est" << std::endl;
    std::cout << "[Q]uit!" << std::endl;

    std::cin >> m_inputChar;

    do
    {
        switch ( m_inputChar )
        {

            case 'R':
            case 'r':
                m_receivedCorrectInput = true;
                std::cout << "R";
                return 1;
            case 'C':
            case 'c':
                m_receivedCorrectInput = true;
                std::cout << "C";
                return 2;
            case 'B':
            case 'b':
                m_receivedCorrectInput = true;
                std::cout << "B";
                return 3;
            case 'T':
            case 't':
                m_receivedCorrectInput = true;
                std::cout << "T";
                return 4;
            case 'Q':
            case 'q':
                m_receivedCorrectInput = true;
                std::cout << "Q";
                return 5;
            default:
                break;

        }
    }
    while ( !m_receivedCorrectInput );

    return  -1;
}
