#include "ShapeContainer.hpp"
#include "../miscFunctions.hpp"
#include "Cuboid.hpp"
#include "Cylinder.hpp"
#include "Sphere.hpp"
#include "Tetrahedron.hpp"

#include <any>
#include <string>

ShapeContainer::ShapeContainer( const std::any &t_shape )
{
    ShapeContainer::m_shape = t_shape;
    ShapeContainer::m_shapeType = shapeToShapeType(t_shape);
}

ShapeContainer::ShapeContainer()
{

}

std::variant<Cuboid, Cylinder, Sphere, Tetrahedron> ShapeContainer::unpack()
{
    if ( m_shapeType == 1 )
    {
        return std::any_cast<Cuboid>(m_shape);
    }
    else if ( m_shapeType == 2 )
    {
        return std::any_cast<Cylinder>(m_shape);
    }
    else if ( m_shapeType == 3 )
    {
        return std::any_cast<Sphere>(m_shape);
    }
    else if ( m_shapeType == 4 )
    {
        return std::any_cast<Tetrahedron>(m_shape);
    }
    else
    {
        const auto l_temp = m_shape.type().name();
        std::string l_msg = "ShapeContainer::unpack: invalid shape type ";
        throwError(l_msg + l_temp, __LINE__, __FILE__);
    }
}

uint8_t ShapeContainer::shapeToShapeType( const std::any &t_shape )
{
    if ( t_shape.type() == typeid(Cuboid))
    {
        return std::any_cast<Cuboid>(t_shape).m_shapeType;
    }
    else if ( t_shape.type() == typeid(Cylinder))
    {
        return std::any_cast<Cylinder>(t_shape).m_shapeType;
    }
    else if ( t_shape.type() == typeid(Sphere))
    {
        return std::any_cast<Sphere>(t_shape).m_shapeType;
    }
    else if ( t_shape.type() == typeid(Tetrahedron))
    {
        return std::any_cast<Tetrahedron>(t_shape).m_shapeType;
    }
    else
    {
        return 0U;
    }
}
