#ifndef MATURITNA_CONFIGCONTROL_HPP
#define MATURITNA_CONFIGCONTROL_HPP

#include "ConfigFile.hpp"

#include <tuple>

ConfigFile configure();
std::tuple<std::string, std::string> parseConfigLine( std::string &t_line );
#endif //MATURITNA_CONFIGCONTROL_HPP
