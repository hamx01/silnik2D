#ifndef SILNIK2D_SQUARE_H
#define SILNIK2D_SQUARE_H

#include <utility>

#include "Figure.h"
#include "../Engine.h"

class Square : public Figure {
public:
    Square(Point p1, Point p2, Point p3, Point p4) {
        points = {std::move(p1), std::move(p2), std::move(p3), std::move(p4)};
    }

    void draw() override;

    void draw(sf::Color color);
};

#endif //SILNIK2D_SQUARE_H
