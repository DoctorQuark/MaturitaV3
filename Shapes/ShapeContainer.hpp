#ifndef MATURITA_RENDERER_SHAPECONTAINER_HPP
#define MATURITA_RENDERER_SHAPECONTAINER_HPP

class Cuboid;

class Cylinder;

class Sphere;

class Tetrahedron;

#include <any>
#include <cstdint>
#include <variant>

class ShapeContainer
{
    public:
        std::any m_shape;
        uint8_t m_shapeType;

        ShapeContainer( const std::any &t_shape );
        ShapeContainer();
        std::variant<Cuboid, Cylinder, Sphere, Tetrahedron> unpack();

    private:
        static uint8_t shapeToShapeType( const std::any &t_shape );
};


#endif //MATURITA_RENDERER_SHAPECONTAINER_HPP
