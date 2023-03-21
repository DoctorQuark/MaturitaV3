#ifndef MATURITNA_CONFIGFILE_HPP
#define MATURITNA_CONFIGFILE_HPP

#include <iostream>
#include <string>

class ConfigFile
{
    public:
        ConfigFile();

        void setPath( const std::string& t_newPath );
        std::string getPath();

        void loadConfig();
        void storeNewConfig();
    private:
        std::string loadPath( const std::string& t_path );
        void createConfig();

        std::string path;
};


#endif //MATURITNA_CONFIGFILE_HPP
