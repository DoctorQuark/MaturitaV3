#include "userInput/inputControl.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "userInput/config/configControl.hpp"
#include "miscFunctions.hpp"


ConfigFile GlobalConfig{ configure() };

int main()
{
    switch ( chooseAction())
    {
        case 1:
            break;
        case 2:
            showConfigMenu();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            throwError("Something is wrong, I can feel it!", __LINE__, __FILE__);
            break;
    }

    return 0;
}
