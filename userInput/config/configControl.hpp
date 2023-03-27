#ifndef MATURITA_RENDERER_CONFIGCONTROL_HPP
#define MATURITA_RENDERER_CONFIGCONTROL_HPP

#include "ConfigFile.hpp"

#include <tuple>

ConfigFile configure();
std::tuple<std::string, std::string> parseConfigLine( std::string &t_line );
#endif //MATURITA_RENDERER_CONFIGCONTROL_HPP
