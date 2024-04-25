#ifndef SILNIK2D_TRIANGLE_H
#define SILNIK2D_TRIANGLE_H

#include <utility>

#include "Figure.h"
#include "../Engine.h"
//! @class Triangle
//! @brief Extends the Figure class to implement functionalities specific to triangles.
class Triangle : public Figure {
public:
//! @brief Constructs a triangle with three points.
//! @param p1 - First vertex of the triangle.
//! @param p2 - Second vertex of the triangle.
//! @param p3 - Third vertex of the triangle.
//! This constructor initializes the triangle with three given vertices, using std::move to optimize memory usage.
    Triangle(Point p1, Point p2, Point p3) {
        points = {std::move(p1), std::move(p2), std::move(p3)};
    }
//! @brief Draws the triangle using the default method defined by the Figure class.
//! This method will usually draw the triangle based on the current style and color settings of the graphics context.
    void draw() override;
//! @brief Draws the triangle with a specified color.
//! @param color - The color to draw the triangle.
//! This method sets the triangle's color before drawing. Useful for dynamic color changes.
    void draw(sf::Color color);
    //! @brief Draws the triangle to a render target with specific render states.
//! @param target - Render target to draw to.
//! @param states - Current render states.
//! This override allows the triangle to be drawn to specific SFML render targets, applying transformations and other render states.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SILNIK2D_TRIANGLE_H
