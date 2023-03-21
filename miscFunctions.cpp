#include "miscFunctions.hpp"

#include <iostream>
#include <fstream>

inline bool fileExists(const std::string& t_fileName)
{
    std::ifstream m_pathFile( t_fileName );
    return m_pathFile.is_open() && m_pathFile.good();
}
