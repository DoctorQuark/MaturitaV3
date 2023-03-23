#ifndef MATURITA_RENDERER_RUN_HPP
#define MATURITA_RENDERER_RUN_HPP

void run();

int parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const int t_minValue = 0, const int t_maxValue = -1 );
float parseNumericInput( const std::string &t_msg, const std::string &t_errorMsg, const float t_minValue = 0, const float t_maxValue = -1 );
uint8_t *parseColorInput();

#endif //MATURITA_RENDERER_RUN_HPP
