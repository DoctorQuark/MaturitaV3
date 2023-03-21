#ifndef MATURITNA_MISCFUNCTIONS_HPP
#define MATURITNA_MISCFUNCTIONS_HPP

#include <iostream>

bool fileExists( const std::string &t_fileName );
void throwError( const std::string &t_errorMessage, int t_lineNum );

#endif //MATURITNA_MISCFUNCTIONS_HPP
