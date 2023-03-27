#include <tuple>
#include <limits>

#include "HitPoint.hpp"

HitPoint::HitPoint()
{
    HitPoint::m_xPos = - std::numeric_limits<float>::max();
    HitPoint::m_yPos = - std::numeric_limits<float>::max();
    HitPoint::m_zPos = - std::numeric_limits<float>::max();
    HitPoint::m_hit = false;
}

HitPoint::HitPoint( const float t_xPos, const float t_yPos, const float t_zPos )
{
    HitPoint::m_xPos = t_xPos;
    HitPoint::m_yPos = t_yPos;
    HitPoint::m_zPos = t_zPos;
    HitPoint::m_hit = true;
}

HitPoint::HitPoint( const bool t_hit, const float t_xPos, const float t_yPos, const float t_zPos )
{
    HitPoint::m_xPos = t_xPos;
    HitPoint::m_yPos = t_yPos;
    HitPoint::m_zPos = t_zPos;
    HitPoint::m_hit = t_hit;
}

HitPoint::HitPoint( const std::tuple<float, float, float> t_pos )
{
    const auto [l_xPos, l_yPos, l_zPos] = t_pos;

    HitPoint::m_xPos = l_xPos;
    HitPoint::m_yPos = l_yPos;
    HitPoint::m_zPos = l_zPos;
    HitPoint::m_hit = true;
}

HitPoint::HitPoint( const std::tuple<bool, float, float, float> t_hitPoint )
{
    const auto [l_hit, l_xPos, l_yPos, l_zPos] = t_hitPoint;

    HitPoint::m_xPos = l_xPos;
    HitPoint::m_yPos = l_yPos;
    HitPoint::m_zPos = l_zPos;
    HitPoint::m_hit = l_hit;
}

HitPoint::HitPoint( const HitPoint &t_hitPoint )
{
    HitPoint::m_xPos = t_hitPoint.m_xPos;
    HitPoint::m_yPos = t_hitPoint.m_yPos;
    HitPoint::m_zPos = t_hitPoint.m_zPos;
    HitPoint::m_hit = t_hitPoint.m_hit;
}

HitPoint::HitPoint( const bool t_hit )
{
    HitPoint::m_xPos = std::numeric_limits<float>::max();
    HitPoint::m_yPos = std::numeric_limits<float>::max();
    HitPoint::m_zPos = std::numeric_limits<float>::max();
    HitPoint::m_hit = t_hit;
}

void HitPoint::setHit( const bool t_hit )
{
    HitPoint::m_hit = t_hit;
}

bool HitPoint::getHit() const
{
    return HitPoint::m_hit;
}

void HitPoint::getXPos( const float t_xPos )
{
    HitPoint::m_xPos = t_xPos;
}

float HitPoint::setXPos() const
{
    return HitPoint::m_xPos;
}

void HitPoint::getYPos( const float t_yPos )
{
    HitPoint::m_yPos = t_yPos;
}

float HitPoint::setYPos() const
{
    return m_yPos;
}

void HitPoint::getZPos( const float t_zPos )
{
    HitPoint::m_zPos = t_zPos;
}

float HitPoint::setZPos() const
{
    return HitPoint::m_zPos;
}

void HitPoint::setPos( const std::tuple<float, float, float> t_pos )
{
    const auto [l_xPos, l_yPos, l_zPos] = t_pos;

    HitPoint::m_xPos = l_xPos;
    HitPoint::m_yPos = l_yPos;
    HitPoint::m_zPos = l_zPos;
}

auto HitPoint::getPos()
{
    return std::tuple<float, float, float>(HitPoint::m_xPos, HitPoint::m_yPos, HitPoint::m_zPos);
}

void HitPoint::setHitPoint( const std::tuple<bool, float, float, float> t_hitPoint )
{
    const auto [l_hit, l_xPos, l_yPos, l_zPos] = t_hitPoint;

    HitPoint::m_xPos = l_xPos;
    HitPoint::m_yPos = l_yPos;
    HitPoint::m_zPos = l_zPos;
    HitPoint::m_hit = l_hit;
}

auto HitPoint::getHitPoint()
{
    return std::tuple<bool, float, float, float>(HitPoint::m_hit, HitPoint::m_xPos, HitPoint::m_yPos, HitPoint::m_zPos);
}
