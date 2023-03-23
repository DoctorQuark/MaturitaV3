#include "Renderer.hpp"
#include "../userInput/config/ConfigFile.hpp"

#include <cmath>
#include <iostream>

Renderer::Renderer( const float t_xPos, const float t_yPos, const float t_fov )
{
    Renderer::xCamPos = t_xPos;
    Renderer::yCamPos = t_yPos;
    Renderer::CamFOV = t_fov;
    Renderer::CamRot = std::atan2(t_yPos, t_xPos) * float(180.0 / M_PI) * -1.0f;
    std::cout << CamRot << std::endl;
}

void Renderer::addShape( const std::any &t_shape )
{
    Renderer::shapes.push_back(t_shape);
}

void Renderer::startRender()
{
    const float angleStep{ Renderer::CamFOV / 256.0f };

    for ( int m_i = 0; m_i < 256; ++m_i )
    {
        const float m_horizontalAngle = float(m_i) * angleStep;
        for ( int m_j = 0; m_j < 256; ++m_j )
        {
            const float m_verticalAngle = float(m_j) * angleStep;
            uint8_t *pixel = rayCast(m_horizontalAngle, m_verticalAngle);
            for ( int m_k = 0; m_k < 3; ++m_k )
            {
                Renderer::image[m_i][m_j][m_k] = pixel[m_k];
            }
        }
    }
}

uint8_t *Renderer::rayCast( const float t_horizontalAngle, const float t_verticalAngle )
{
    // Point inside a sphere
    // (x-cx) ^2 + (y-cy) ^2 + (z-cz) ^ 2 < r^2

    // Closest point on a line to a  ([x/y]0 - tested point,[x/y]1 - startpoint,[x/y]2 - endpoint)
    //  x = x1 + t(x2 - x1)
    //  y = y1 + t(y2 - y1)
    // t = [(x0 - x1)(x2 - x1) + (y0 - y1)(y2 - y1)] / [(x2 - x1)^2 + (y2 - y1)^2]

    // Define global config
    extern ConfigFile GlobalConfig;

    const float m_startX{ Renderer::xCamPos };
    const float m_startY{ Renderer::yCamPos };
    const float m_endX{ Renderer::xCamPos + std::any_cast<float>(GlobalConfig.getConfigValue("areaWidth")) };
    const float m_endY{ Renderer::yCamPos + std::any_cast<float>(GlobalConfig.getConfigValue("areaHeight")) };

    return nullptr;
}
