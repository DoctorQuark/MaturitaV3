#ifndef MATURITA_RENDERER_RENDERER_HPP
#define MATURITA_RENDERER_RENDERER_HPP

#include <vector>
#include <any>
#include <cstdint>
#include <array>
#include <string>

#include "Rotation.hpp"
#include "../Shapes/ShapeContainer.hpp"

class Renderer
{
    public:
        float m_xCamPos;
        float m_yCamPos;
        float m_zCamPos{ 2 };
        float m_camFov;
        Rotation m_camRot;

        Renderer( float t_xPos, float t_yPos, float t_fov );
        void addShape( const ShapeContainer &t_shapeContainer );
        void startRender();
        void testRenderer( const float t_percentage = 100.0F, const bool t_print = true );
        std::array<uint8_t, 3> rayCast( const Rotation t_horizontalAngle, const Rotation t_verticalAngle );
        std::tuple<float, float, float> testRayCast( const Rotation t_horizontalAngle, const Rotation t_verticalAngle );
        void saveBitmap( const std::string &t_filename, const uint8_t *t_data, unsigned int t_width, unsigned int t_height );

    private:
        std::vector<ShapeContainer> m_shapes;
        std::vector<std::vector<std::vector<uint8_t>>> m_rayCastBuffer;
};


#endif //MATURITA_RENDERER_RENDERER_HPP
