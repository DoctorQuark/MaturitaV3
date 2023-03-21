#include "userInput/inputControl.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "userInput/config/configControl.hpp"


ConfigFile GlobalConfig{ Configure() };

int main()
{
    switch ( chooseAction() )
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            std::cerr << "Something is wrong, I can feel it! (Main.cpp, line " << __LINE__ << ")" << std::endl;
            break;
    }

    return 0;
}
