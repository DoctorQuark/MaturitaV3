#ifndef MATURITA_RENDERER_RENDERER_HPP
#define MATURITA_RENDERER_RENDERER_HPP

#include <vector>
#include <any>
#include <cstdint>

class Renderer
{
    public:
        float xCamPos;
        float yCamPos;
        float CamFOV;
        float CamRot;

        Renderer( float t_xPos, float t_yPos, float t_fov );
        void addShape( const std::any &t_shape );
        void startRender();
        uint8_t *rayCast( float t_horizontalAngle, float t_verticalAngle );

    private:
        std::vector<std::any> shapes;
        uint8_t image[256][256][3];
};


#endif //MATURITA_RENDERER_RENDERER_HPP
