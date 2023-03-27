#include "errorHandling.hpp"

#include <iostream>

[[maybe_unused]] [[noreturn]] void throwError( const std::string &t_errorMessage )
{
    throw std::runtime_error( "\nERROR: " + t_errorMessage );
}

[[maybe_unused]] void throwWarning( const std::string &t_errorMessage )
{
    std::cerr << std::endl << "WARNING: " << t_errorMessage << std::endl;
}

[[maybe_unused]] void throwMessage( const std::string &t_errorMessage )
{
    std::cout << std::endl << "INFO: " << t_errorMessage << std::endl;
}
