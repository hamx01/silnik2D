#ifndef SILNIK2D_TRIANGLE_H
#define SILNIK2D_TRIANGLE_H

#include <utility>

#include "Figure.h"
#include "../Engine.h"

class Triangle : public Figure {
public:
    Triangle(Point p1, Point p2, Point p3) {
        points = {std::move(p1), std::move(p2), std::move(p3)};
    }
    void draw() override;
    void draw(sf::Color color);
};


#endif //SILNIK2D_TRIANGLE_H
