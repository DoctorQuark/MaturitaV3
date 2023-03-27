#ifndef MATURITA_RENDERER_MISCFUNCTIONS_HPP
#define MATURITA_RENDERER_MISCFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

bool fileExists( const std::string &t_fileName );

unsigned stou( std::string const &t_str, size_t *t_idx = nullptr, int t_base = 10 );

std::string parseFileName( const std::string &t_fileName );

std::unique_ptr<uint8_t[]> imageDataTo1DArray( const std::vector<std::vector<std::vector<uint8_t>>> &t_imageData );

#endif //MATURITA_RENDERER_MISCFUNCTIONS_HPP
