#include "configControl.hpp"
#include "ConfigFile.hpp"

ConfigFile Configure()
{
    ConfigFile m_configFile;
    m_configFile.loadConfig();

    return m_configFile;
}
