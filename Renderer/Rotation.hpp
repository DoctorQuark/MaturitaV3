#ifndef MATURITA_RENDERER_ROTATION_HPP
#define MATURITA_RENDERER_ROTATION_HPP


class Rotation
{
    public:
        [[nodiscard]] float getDegrees() const;
        void setDegrees( const float t_newAngle );

        [[nodiscard]] float getRadians() const;
        void setRadians( const float t_newAngle );

        Rotation( const float t_newAngle, const bool t_isDegrees );

    private:
        float m_degrees;
        float m_radians;
};


#endif //MATURITA_RENDERER_ROTATION_HPP
