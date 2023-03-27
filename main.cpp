#include "userInput/inputControl.hpp"
#include "userInput/config/ConfigFile.hpp"
#include "userInput/config/configControl.hpp"
#include "debugMisc.hpp"
#include "run.hpp"
#include "test.hpp"

ConfigFile g_ConfigFile{ configure( ) };

int main( )
{
    switch ( chooseAction( ))
    {
        case 1:
        {
            run( );
            break;
        }
        case 2:
        {
            showConfigMenu( );
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            test( );
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            throwCodeError( "Something is wrong, I can feel it!", __LINE__, __FILE__, __FUNCTION__ );
        }
    }

    return 0;
}
