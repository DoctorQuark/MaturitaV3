//
// Created by mrhap on 01.04.2023.
//

#ifndef MATURITA_RENDERER_HITPOINT_HPP
#define MATURITA_RENDERER_HITPOINT_HPP


#include <tuple>

class HitPoint
{
    private:
        bool m_hit;
        float m_xPos;
        float m_yPos;
        float m_zPos;
    public:

        HitPoint( );

        HitPoint( const float t_xPos, const float t_yPos, const float t_zPos );

        HitPoint( const bool t_hit, const float t_xPos, const float t_yPos, const float t_zPos );

        explicit HitPoint( const std::tuple<float, float, float> t_pos );

        explicit HitPoint( const std::tuple<bool, float, float, float> t_hitPoint );

        explicit HitPoint( const bool t_hit );

        HitPoint( const HitPoint &t_hitPoint );

        void setHit( const bool t_hit );

        bool getHit( ) const;

        void getXPos( const float t_xPos );

        float setXPos( ) const;

        void getYPos( const float t_yPos );

        float setYPos( ) const;

        void getZPos( const float t_zPos );

        float setZPos( ) const;

        void setPos( const std::tuple<float, float, float> t_pos );

        auto getPos( );

        void setHitPoint( const std::tuple<bool, float, float, float> t_hitPoint );

        auto getHitPoint( );
};


#endif //MATURITA_RENDERER_HITPOINT_HPP
