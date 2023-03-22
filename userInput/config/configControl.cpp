#include "configControl.hpp"
#include "ConfigFile.hpp"
#include "../../miscFunctions.hpp"

#include <vector>
#include <tuple>

ConfigFile configure()
{
    ConfigFile m_configFile;
    m_configFile.loadConfig();

    return m_configFile;
}

std::tuple<std::string, std::string> parseConfigLine( std::string &t_line )
{
    std::string m_key;
    std::string m_value;
    unsigned divisionIndex{ 0 };

    for ( char c : t_line )
    {
        if ( c == '=' ) break;
        divisionIndex++;
    }

    m_key = t_line.substr(0, divisionIndex);
    m_value = t_line.substr(divisionIndex + 1, t_line.length() - divisionIndex);

    // trim the spaces from the beginning and end
    m_key.erase(m_key.begin(), std::find_if(m_key.begin(), m_key.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    m_key.erase(std::find_if(m_key.rbegin(), m_key.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), m_key.end());
    m_value.erase(m_value.begin(), std::find_if(m_value.begin(), m_value.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    m_value.erase(std::find_if(m_value.rbegin(), m_value.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), m_value.end());

    std::tuple<std::string, std::string> m_tuple(m_key, m_value);
    return m_tuple;
}
