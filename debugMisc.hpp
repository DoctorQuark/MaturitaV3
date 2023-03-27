//
// Created by mrhap on 02.04.2023.
//

#ifndef MATURITA_RENDERER_DEBUGMISC_HPP
#define MATURITA_RENDERER_DEBUGMISC_HPP

#include <iostream>

[[maybe_unused]] [[noreturn]] void throwCodeError( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName );

[[maybe_unused]] void throwCodeWarning( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName );

[[maybe_unused]] void throwCodeMessage( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName );

#endif //MATURITA_RENDERER_DEBUGMISC_HPP
