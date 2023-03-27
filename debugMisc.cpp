#include "debugMisc.hpp"
#include <string>

[[maybe_unused]] [[noreturn]] void throwCodeError( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName )
{
    throw std::runtime_error( "ERROR" + t_errorMessage + " (In file [" + t_filePath + "] on line number " + std::to_string( t_lineNum ) + " in function " + t_functionName + ")\n" );
}

[[maybe_unused]] void throwCodeWarning( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName )
{
    std::cerr << "WARNING: " << t_errorMessage << " (In file [" << t_filePath << "] on line number " << std::to_string( t_lineNum ) << " in function " << t_functionName << ")" << std::endl;
}

[[maybe_unused]] void throwCodeMessage( const std::string &t_errorMessage, const int t_lineNum, const std::string &t_filePath, const std::string &t_functionName )
{
    std::cout << "INFO: " << t_errorMessage << " (In file [" << t_filePath << "] on line number " << std::to_string( t_lineNum ) << " in function " << t_functionName << ")" << std::endl;
}
