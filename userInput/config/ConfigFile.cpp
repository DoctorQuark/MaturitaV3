#include "ConfigFile.hpp"
#include "../../miscFunctions.hpp"

#include <iostream>
#include <string>
#include <fstream>

ConfigFile::ConfigFile()
{
    if ( fileExists(ConfigFile::m_defaultPath))
    {
        ConfigFile::path = ConfigFile::loadPath(ConfigFile::m_defaultPath);
    }
    else
    {
        throwError("Cannot open path file: " + ConfigFile::m_defaultPath, __LINE__, __FILE__);
    }
}

void ConfigFile::setPath( const std::string &t_newPath )
{
    ConfigFile::path = t_newPath;
}

std::string ConfigFile::getPath()
{
    return ConfigFile::path;
}

void ConfigFile::loadConfig()
{

}

void ConfigFile::storeNewConfig()
{

}

std::string ConfigFile::loadPath( const std::string &t_path )
{
    std::ifstream m_pathFile(t_path);

    std::string m_loadedPath;
    if ( m_pathFile.is_open())
    {
        if ( m_pathFile.good())
        {
            std::getline(m_pathFile, m_loadedPath);
            m_pathFile.close();
        }
    }
    else
    {
        throwError("Cannot open path file: " + t_path, __LINE__, __FILE__);
    }

    return m_loadedPath;
}

void ConfigFile::createConfig()
{

}
