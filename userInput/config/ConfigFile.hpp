#ifndef MATURITA_RENDERER_CONFIGFILE_HPP
#define MATURITA_RENDERER_CONFIGFILE_HPP

#include <iostream>
#include <string>
#include <any>

class ConfigFile
{
    public:
        ConfigFile();

        void setPath( const std::string &t_newPath );
        std::string getPath();

        void loadConfig();
        std::tuple<std::string, std::string> getConfig( const std::string &t_key );
        std::any getConfigValue( const std::string &t_key );
        void setConfig( const std::tuple<std::string, std::string> &t_value );

        void storeNewConfig();
    private:
        struct configFileData
        {
            std::string s_outputFolder;
            float s_areaWidth;
            float s_areaHeight;
            unsigned int s_resolution;
            unsigned int s_rayBounces;
        };

        void createConfig();
        std::string loadPath( const std::string &t_path );
        [[maybe_unused]] [[noreturn]] static void throwConfigurationError( const std::string &t_errorMessage );
        [[maybe_unused]] static void throwConfigurationWarning( const std::string &t_errorMessage );
        [[maybe_unused]] static void throwConfigurationMessage( const std::string &t_errorMessage );

        configFileData m_configFileData;
        std::string m_path = "../test/renderer.conf";
};


#endif //MATURITA_RENDERER_CONFIGFILE_HPP
