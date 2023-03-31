#include "miscFunctions.hpp"

#include <iostream>
#include <fstream>
#include <limits>

bool fileExists( const std::string &t_fileName )
{
    std::ifstream l_PathFile(t_fileName);
    return l_PathFile.is_open() && l_PathFile.good();
}

void throwError( const std::string &t_errorMessage, int t_lineNum, const std::string &t_filePath )
{
    std::cerr << "ERROR: " << t_errorMessage << " (In file [" << t_filePath << "] on line number " << t_lineNum << ")" << std::endl;
    throw std::runtime_error(t_errorMessage + " " + std::to_string(t_lineNum));
}

void throwWarning( const std::string &t_errorMessage, int t_lineNum, const std::string &t_filePath )
{
    std::cerr << "ERROR: " << t_errorMessage << " (In file [" << t_filePath << "] on line number " << t_lineNum << ")" << std::endl;
}

unsigned stou( std::string const &str, size_t *idx, int base )
{
    unsigned long result = std::stoul(str, idx, base);
    if ( result > std::numeric_limits<unsigned>::max())
    {
        throw std::out_of_range("stou");
    }
    return result;
}
