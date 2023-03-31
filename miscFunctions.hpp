#ifndef MATURITA_RENDERER_MISCFUNCTIONS_HPP
#define MATURITA_RENDERER_MISCFUNCTIONS_HPP

#include <iostream>

bool fileExists( const std::string &t_fileName );
[[noreturn]] void throwError( const std::string &t_errorMessage, int t_lineNum, const std::string &t_filePath );
void throwWarning( const std::string &t_errorMessage, int t_lineNum, const std::string &t_filePath );
unsigned stou( std::string const &str, size_t *idx = 0, int base = 10 );

#endif //MATURITA_RENDERER_MISCFUNCTIONS_HPP
