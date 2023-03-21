#include "ConfigFile.hpp"

#include <iostream>
#include <string>
#include <fstream>

ConfigFile::ConfigFile()
{
    ConfigFile::path = ConfigFile::loadPath();
}

void ConfigFile::setPath( const std::string& t_newPath )
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

std::string ConfigFile::loadPath( const std::string& t_path )
{
    std::ifstream m_pathFile(t_path );

    std::string m_loadedPath;
    if (m_pathFile.is_open() )
    {
        if ( m_pathFile.good() )
        {
            std::getline(m_pathFile, m_loadedPath);
            m_pathFile.close();
        }
    }
    else
    {
        std::cerr << "Cannot open path file: " << t_path << " (ConfigFile.cpp, line " << __LINE__ << ")" << std::endl;
    }

    return m_loadedPath;
}

void ConfigFile::createConfig()
{

}
