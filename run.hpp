#ifndef MATURITA_RENDERER_RUN_HPP
#define MATURITA_RENDERER_RUN_HPP

#include <cstdint>

void run( );

int parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const int t_minValue = 0, const int t_maxValue = -1 );

float parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const float t_minValue = 0.0F, const float t_maxValue = -1.0F );

uint8_t *parseColorInput( );

#endif // MATURITA_RENDERER_RUN_HPP
