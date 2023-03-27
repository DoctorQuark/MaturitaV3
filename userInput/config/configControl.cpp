#include "configControl.hpp"
#include "ConfigFile.hpp"
#include "../../miscFunctions.hpp"

#include <vector>
#include <tuple>

ConfigFile configure()
{
    ConfigFile l_configFile;
    l_configFile.loadConfig();

    return l_configFile;
}

std::tuple<std::string, std::string> parseConfigLine( std::string &t_line )
{
    std::string l_key;
    std::string l_value;
    unsigned l_divisionIndex{ 0U };

    for ( char l_c : t_line )
    {
        if ( l_c == '=' )
        {
            break;
        }
        l_divisionIndex++;
    }

    l_key = t_line.substr(0U, l_divisionIndex);
    l_value = t_line.substr(l_divisionIndex + 1ULL, t_line.length() - l_divisionIndex);

    // trim the spaces from the beginning and end
    ( void ) l_key.erase(l_key.begin(), std::find_if(l_key.begin(), l_key.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    ( void ) l_key.erase(std::find_if(l_key.rbegin(), l_key.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), l_key.end());
    ( void ) l_value.erase(l_value.begin(), std::find_if(l_value.begin(), l_value.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    ( void ) l_value.erase(std::find_if(l_value.rbegin(), l_value.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), l_value.end());

    std::tuple<std::string, std::string> l_tuple(l_key, l_value);
    return l_tuple;
}
