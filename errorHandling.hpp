//
// Created by mrhap on 01.04.2023.
//

#ifndef MATURITA_RENDERER_ERRORHANDLING_HPP
#define MATURITA_RENDERER_ERRORHANDLING_HPP

#include <iostream>

[[maybe_unused]] [[noreturn]] void throwError( const std::string &t_errorMessage );
[[maybe_unused]] void throwWarning( const std::string &t_errorMessage );
[[maybe_unused]] void throwMessage( const std::string &t_errorMessage );

#endif //MATURITA_RENDERER_ERRORHANDLING_HPP
