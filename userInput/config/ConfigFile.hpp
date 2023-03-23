#ifndef MATURITNA_CONFIGFILE_HPP
#define MATURITNA_CONFIGFILE_HPP

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
        struct ConfigFileData
        {
            std::string outputFolder;
            float areaWidth;
            float areaHeight;
            int resolution;
            int rayBounces;
        };

        void createConfig();
        std::string loadPath( const std::string &t_path );

        ConfigFileData m_configFileData;
        std::string m_path = "../run/debug/config";
};


#endif //MATURITNA_CONFIGFILE_HPP
