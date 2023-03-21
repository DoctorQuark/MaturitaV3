#include "miscFunctions.hpp"

#include <iostream>
#include <fstream>

bool fileExists( const std::string &t_fileName )
{
    std::ifstream m_pathFile(t_fileName);
    return m_pathFile.is_open() && m_pathFile.good();
}

void throwError( const std::string &t_errorMessage, int t_lineNum )
{
    std::cerr << "ERROR: " << t_errorMessage << " " << t_lineNum << std::endl;
    throw std::runtime_error(t_errorMessage + " " + std::to_string(t_lineNum));
}
