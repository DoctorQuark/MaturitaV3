#include "miscFunctions.hpp"
#include "errorHandling.hpp"
#include "userInput/config/ConfigFile.hpp"

#include <fstream>
#include <limits>
#include <string>

bool fileExists( const std::string &t_fileName )
{
    std::ifstream l_pathFile( t_fileName );
    return l_pathFile.is_open( ) && l_pathFile.good( );
}

unsigned stou( std::string const &t_str, size_t *t_idx, int t_base )
{
    unsigned long l_result = std::stoul( t_str, t_idx, t_base );
    if ( l_result > std::numeric_limits<unsigned>::max( ))
    {
        throw std::out_of_range( "stou" );
    }
    return l_result;
}

std::string parseFileName( const std::string &t_fileName )
{
    extern ConfigFile g_ConfigFile;

    std::string l_output;

    const auto l_configLocation = g_ConfigFile.getPath( );
    const std::string l_extension{ ".bmp" };
    const unsigned long long l_fileNameLength = t_fileName.size( );

    unsigned long long l_dotPosition{ std::numeric_limits<unsigned long long>::max( ) };

    bool l_isPath{ false };
    bool l_hasExtension{ false };
    bool l_hasCorrectExtension{ false };

    for ( auto l_char : t_fileName )
    {
        switch ( l_char )
        {
            case '\\':
            {
                [[fallthrough]];
            }
            case '/':
            {
                [[fallthrough]];
            }
            case ':':
            {
                l_isPath = true;
                break;
            }
            case '.':
            {
                l_hasExtension = true;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    if ( l_isPath )
    {
        throwWarning( "Specifying a path in the file name is not recommended\nTo place output in different folder use outputFolder option in: [" + l_configLocation + "]" );
    }

    if ( l_hasExtension )
    {
        for ( unsigned long long l_i = l_fileNameLength - 1ULL; l_i < l_fileNameLength; --l_i )
        {
            if ( t_fileName[l_i] == '.' )
            {
                l_dotPosition = l_i;
                break;
            }
        }

        if ( t_fileName[l_dotPosition + 1ULL] == 'b' ||
             t_fileName[l_dotPosition + 1ULL] == 'B' )
        {
            if ( t_fileName[l_dotPosition + 2ULL] == 'm' ||
                 t_fileName[l_dotPosition + 2ULL] == 'M' )
            {
                if ( t_fileName[l_dotPosition + 3ULL] == 'p' ||
                     t_fileName[l_dotPosition + 3ULL] == 'P' )
                {
                    if ( l_dotPosition + 4ULL == l_fileNameLength )
                    {
                        l_hasCorrectExtension = true;
                    }
                }
            }
        }
    }

    if ( l_hasExtension && !l_hasCorrectExtension )
    {
        throwWarning( "Incorrect file extension detected\nIgnoring incorrect extension!" );
        l_output = t_fileName.substr( 0ULL, l_dotPosition ) + l_extension;
    }
    else if ( l_hasExtension && l_hasCorrectExtension )
    {
        throwMessage( "Correct file extension detected!\nIt is unnecessary to specify the file extension, the program adds it itself." );

        l_output = t_fileName;
    }
    else if ( !l_hasExtension )
    {
        l_output = t_fileName + l_extension;
    }
    else
    {

    }

    return l_output;
}

std::unique_ptr<uint8_t[]> imageDataTo1DArray( const std::vector<std::vector<std::vector<uint8_t>>> &t_imageData )
{
    const auto l_resolution{ t_imageData.size( ) };
    const auto l_arraySize{ l_resolution * l_resolution * t_imageData[0ULL][0ULL].size( ) };

    auto l_i{ 0ULL };
    auto l_j{ 0ULL };
    auto l_k{ 0ULL };
    std::unique_ptr<uint8_t[]> l_returnData( new uint8_t[l_arraySize] );

    std::cout << "imageDataAs1DArray: " << sizeof(l_returnData) / sizeof( uint8_t ) << std::endl;
    std::cout << "Size of l_returnData: " << sizeof(l_returnData) << " Size of uint8_t: " << sizeof( uint8_t ) << std::endl;
    std::cout << "resolution: " << l_resolution << std::endl;
    std::cout << "arraySize: " << l_arraySize << std::endl;

    for ( const auto &l_item0 : t_imageData )
    {
        for ( const auto &l_item1 : l_item0 )
        {
            for ( const auto l_item2 : l_item1 )
            {
                l_returnData[l_i * l_resolution * 3ULL + l_j * 3ULL + l_k] = l_item2;
                ++l_k;
            }
            ++l_j;
            l_k = 0ULL;
        }
        ++l_i;
        l_j = 0ULL;
    }
}
