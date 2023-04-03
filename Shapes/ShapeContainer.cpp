#include "ShapeContainer.hpp"
#include "../miscFunctions.hpp"
#include "Cuboid.hpp"
#include "Cylinder.hpp"
#include "Sphere.hpp"
#include "Tetrahedron.hpp"
#include "../debugMisc.hpp"

#include <any>
#include <string>

ShapeContainer::ShapeContainer( const std::any t_shape )
{
    ShapeContainer::m_shape = t_shape;
    const auto l_shapeType = shapeToShapeType( t_shape );
    const auto l_msgType{ "Shape type is " + std::to_string( l_shapeType ) };
    throwCodeMessage( l_msgType, __LINE__, __FILE__, __FUNCTION__ );
    ShapeContainer::m_shapeType = l_shapeType;
}

ShapeContainer::ShapeContainer( )
{
    ShapeContainer::m_shapeType = 0U;
}

std::variant<Cuboid, Cylinder, Sphere, Tetrahedron> ShapeContainer::unpack( )
{
    //throwCodeMessage("ShapeContainer.unpack(): Shape type is " + std::to_string(m_shapeType), __LINE__, __FILE__);

    switch ( ShapeContainer::m_shapeType )
    {
        case 1:
        {
            //throwCodeWarning("ShapeContainer::unpack(): Trying to unpack a shape of type Cuboid.", __LINE__, __FILE__);
            return std::any_cast<Cuboid>( m_shape );
        }
        case 2:
        {
            //throwCodeWarning("ShapeContainer::unpack(): Trying to unpack a shape of type Cylinder.", __LINE__, __FILE__);
            return std::any_cast<Cylinder>( m_shape );
        }
        case 3:
        {
            //throwCodeWarning("ShapeContainer::unpack(): Trying to unpack a shape of type Sphere.", __LINE__, __FILE__);
            return std::any_cast<Sphere>( m_shape );
        }
        case 4:
        {
            //throwCodeWarning("ShapeContainer::unpack(): Trying to unpack a shape of type Tetrahedron.", __LINE__, __FILE__);
            return std::any_cast<Tetrahedron>( m_shape );
        }
        default:
        {
            const auto l_temp = m_shape.type( ).name( );
            std::string l_msg = "ShapeContainer::unpack: invalid shape type. Shape type:  ";
            throwCodeError( l_msg + l_temp, __LINE__, __FILE__, __FUNCTION__ );
        }
    }
}

uint8_t ShapeContainer::shapeToShapeType( const std::any &t_shape )
{
    if ( t_shape.type( ) == typeid( Cuboid ))
    {
        return std::any_cast<Cuboid>( t_shape ).m_shapeType;
    }
    else if ( t_shape.type( ) == typeid( Cylinder ))
    {
        return std::any_cast<Cylinder>( t_shape ).m_shapeType;
    }
    else if ( t_shape.type( ) == typeid( Sphere ))
    {
        return std::any_cast<Sphere>( t_shape ).m_shapeType;
    }
    else if ( t_shape.type( ) == typeid( Tetrahedron ))
    {
        return std::any_cast<Tetrahedron>( t_shape ).m_shapeType;
    }
    else
    {
        return 0U;
    }
}
