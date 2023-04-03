#ifndef MATURITA_RENDERER_SHAPE_HPP
#define MATURITA_RENDERER_SHAPE_HPP

#include "ShapeContainer.hpp"

#include <cstdint>
#include <algorithm>
#include <cmath>
#include <tuple>

// Shape class
class Shape
{
    public:
        // x and y position of the shape
        float m_xPos{ 0 };
        float m_yPos{ 0 };
        float m_zPos{ 2 };
        // Color of the shape
        uint8_t m_color[3] = { 64, 128, 196 };

        // Get the shape container
        virtual ShapeContainer pack() = 0;
        // Returns the shape type for this shape.
        virtual uint8_t shapeToShapeType() = 0;

        // Destructor
        virtual ~Shape() = default;
};


#endif //MATURITA_RENDERER_SHAPE_HPP
