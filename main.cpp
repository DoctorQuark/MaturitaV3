#include "userInput/inputControl.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "userInput/config/configControl.hpp"
#include "miscFunctions.hpp"


ConfigFile GlobalConfig{ Configure() };

int main()
{
    switch ( chooseAction())
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
            throwError("Something is wrong, I can feel it!", __LINE__);
            break;
    }

    return 0;
}
