#include "ConfigFile.hpp"
#include "../../miscFunctions.hpp"
#include "configControl.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

ConfigFile::ConfigFile()
{
    if ( !fileExists(ConfigFile::m_path))
    {
        ConfigFile::createConfig();
    }
}

void ConfigFile::setPath( const std::string &t_newPath )
{
    ConfigFile::m_path = t_newPath;
}

std::string ConfigFile::getPath()
{
    return ConfigFile::m_path;
}

void ConfigFile::loadConfig()
{
    if ( fileExists(m_path))
    {
        std::ifstream t_file(m_path);
        std::string t_line;

        while ( getline(t_file, t_line))
        {
            std::tuple<std::string, std::string> m_parsedLine = parseConfigLine(t_line);

            setConfig(m_parsedLine);
        }
    }

}

std::tuple<std::string, std::string> ConfigFile::getConfig( const std::string &t_key )
{
    std::tuple<std::string, std::string> m_output;

    if ( t_key == "outputFolder" )
    {
        m_output = std::make_tuple(t_key, ConfigFile::m_configFileData.outputFolder);
    }
    else if ( t_key == "areaWidth" )
    {
        m_output = std::make_tuple(t_key, std::to_string(ConfigFile::m_configFileData.areaWidth));
    }
    else if ( t_key == "areaHeight" )
    {
        m_output = std::make_tuple(t_key, std::to_string(ConfigFile::m_configFileData.areaHeight));
    }
    else if ( t_key == "resolution" )
    {
        m_output = std::make_tuple(t_key, std::to_string(ConfigFile::m_configFileData.resolution));
    }
    else if ( t_key == "rayBounces" )
    {
        m_output = std::make_tuple(t_key, std::to_string(ConfigFile::m_configFileData.rayBounces));
    }

    return m_output;
}

std::any ConfigFile::getConfigValue( const std::string &t_key )
{
    std::any m_output;

    if ( t_key == "outputFolder" )
    {
        m_output = ConfigFile::m_configFileData.outputFolder;
    }
    else if ( t_key == "areaWidth" )
    {
        m_output = ConfigFile::m_configFileData.areaWidth;
    }
    else if ( t_key == "areaHeight" )
    {
        m_output = ConfigFile::m_configFileData.areaHeight;
    }
    else if ( t_key == "resolution" )
    {
        m_output = ConfigFile::m_configFileData.resolution;
    }
    else if ( t_key == "rayBounces" )
    {
        m_output = ConfigFile::m_configFileData.rayBounces;
    }

    return m_output;
}

void ConfigFile::setConfig( const std::tuple<std::string, std::string> &t_value )
{
    const auto [m_key, m_value] = t_value;

    if ( m_key == "outputFolder" )
    {
        ConfigFile::m_configFileData.outputFolder = m_value;
    }
    else if ( m_key == "areaWidth" )
    {
        ConfigFile::m_configFileData.areaWidth = std::stof(m_value);
    }
    else if ( m_key == "areaHeight" )
    {
        ConfigFile::m_configFileData.areaHeight = std::stof(m_value);
    }
    else if ( m_key == "resolution" )
    {
        ConfigFile::m_configFileData.resolution = std::stoi(m_value);
    }
    else if ( m_key == "rayBounces" )
    {
        ConfigFile::m_configFileData.rayBounces = std::stoi(m_value);
    }
}

void ConfigFile::storeNewConfig()
{

}

void ConfigFile::createConfig()
{
    std::ofstream m_configFile(m_path);

    m_configFile << "outputFolder=\".\"" << std::endl;
    m_configFile << "areaWidth=256.0" << std::endl;
    m_configFile << "areaHeight=256.0" << std::endl;
    m_configFile << "resolution=256" << std::endl;
    m_configFile << "rayBounces=1" << std::endl;
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
        }
    }
    else
    {
        throwError("Cannot open m_path file: " + t_path, __LINE__, __FILE__);
    }

    m_pathFile.close();
    return m_loadedPath;
}
