#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

#include "ConfigFile.hpp"
#include "../../miscFunctions.hpp"
#include "configControl.hpp"
#include "../../debugMisc.hpp"

ConfigFile::ConfigFile( )
{
    if ( !fileExists( ConfigFile::m_path ))
    {
        std::cout << "Config File does not exist!\nCreating default config file." << std::endl;
        ConfigFile::createConfig( );
    }
    else
    {
        std::cout << "Config File found!" << std::endl;
    }
}

void ConfigFile::setPath( const std::string &t_newPath )
{
    ConfigFile::m_path = t_newPath;
}

std::string ConfigFile::getPath( )
{
    return ConfigFile::m_path;
}

void ConfigFile::loadConfig( )
{
    if ( fileExists( m_path ))
    {
        std::ifstream l_file( m_path );
        std::string l_line;

        while ( getline( l_file, l_line ))
        {
            std::tuple<std::string, std::string> l_configLine = parseConfigLine( l_line );

            setConfig( l_configLine );
        }
    }
    std::cout << "Config File Loaded!" << std::endl;
}

std::tuple<std::string, std::string> ConfigFile::getConfig( const std::string &t_key )
{
    std::tuple<std::string, std::string> l_output;

    if ( t_key == "outputFolder" )
    {
        l_output = std::make_tuple( t_key, ConfigFile::m_configFileData.s_outputFolder );
    }
    else if ( t_key == "areaWidth" )
    {
        l_output = std::make_tuple( t_key, std::to_string( ConfigFile::m_configFileData.s_areaWidth ));
    }
    else if ( t_key == "areaHeight" )
    {
        l_output = std::make_tuple( t_key, std::to_string( ConfigFile::m_configFileData.s_areaHeight ));
    }
    else if ( t_key == "resolution" )
    {
        l_output = std::make_tuple( t_key, std::to_string( ConfigFile::m_configFileData.s_resolution ));
    }
    else if ( t_key == "rayBounces" )
    {
        l_output = std::make_tuple( t_key, std::to_string( ConfigFile::m_configFileData.s_rayBounces ));
    }

    return l_output;
}

std::any ConfigFile::getConfigValue( const std::string &t_key )
{
    std::any l_output;

    if ( t_key == "outputFolder" )
    {
        l_output = ConfigFile::m_configFileData.s_outputFolder;
    }
    else if ( t_key == "areaWidth" )
    {
        l_output = ConfigFile::m_configFileData.s_areaWidth;
    }
    else if ( t_key == "areaHeight" )
    {
        l_output = ConfigFile::m_configFileData.s_areaHeight;
    }
    else if ( t_key == "resolution" )
    {
        l_output = ConfigFile::m_configFileData.s_resolution;
    }
    else if ( t_key == "rayBounces" )
    {
        l_output = ConfigFile::m_configFileData.s_rayBounces;
    }

    return l_output;
}

void ConfigFile::setConfig( const std::tuple<std::string, std::string> &t_value )
{
    const auto [l_key, l_value] = t_value;

    if ( l_key == "outputFolder" )
    {
        ConfigFile::m_configFileData.s_outputFolder = l_value;
    }
    else if ( l_key == "areaWidth" )
    {
        ConfigFile::m_configFileData.s_areaWidth = std::stof( l_value );
    }
    else if ( l_key == "areaHeight" )
    {
        ConfigFile::m_configFileData.s_areaHeight = std::stof( l_value );
    }
    else if ( l_key == "resolution" )
    {
        ConfigFile::m_configFileData.s_resolution = stou( l_value );
    }
    else if ( l_key == "rayBounces" )
    {
        ConfigFile::m_configFileData.s_rayBounces = stou( l_value );
    }
}

void ConfigFile::storeNewConfig( )
{

}

void ConfigFile::createConfig( )
{
    std::cout << "Creating config file..." << std::endl;
    std::ofstream l_configFile( m_path );

    l_configFile << "outputFolder=\".\"" << std::endl;
    l_configFile << "areaWidth=256.0" << std::endl;
    l_configFile << "areaHeight=256.0" << std::endl;
    l_configFile << "resolution=256" << std::endl;
    l_configFile << "rayBounces=0" << std::endl;

    std::cout << "Creating config Created!" << std::endl;
}

std::string ConfigFile::loadPath( const std::string &t_path )
{
    std::ifstream l_pathFile( t_path );

    std::string l_loadedPath;
    if ( l_pathFile.is_open( ))
    {
        if ( l_pathFile.good( ))
        {
            std::getline( l_pathFile, l_loadedPath );
        }
    }
    else
    {
        throwCodeError( "Cannot open m_path file: " + t_path, __LINE__, __FILE__, __FUNCTION__ );
    }

    l_pathFile.close( );
    return l_loadedPath;
}

[[maybe_unused]] [[noreturn]] void ConfigFile::throwConfigurationError( const std::string &t_errorMessage )
{
    throw std::runtime_error( "CONFIGURATION ERROR: " + t_errorMessage );
}

[[maybe_unused]] void ConfigFile::throwConfigurationWarning( const std::string &t_errorMessage )
{
    std::cerr << "CONFIGURATION ERROR: " << t_errorMessage << std::endl;
}

[[maybe_unused]] void ConfigFile::throwConfigurationMessage( const std::string &t_errorMessage )
{
    std::cerr << "CONFIGURATION INFO: " << t_errorMessage << std::endl;
}
