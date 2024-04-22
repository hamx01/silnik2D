//
// Created by asoli on 22.04.2024.
//

#ifndef SILNIK2D_SQUARE_H
#define SILNIK2D_SQUARE_H

#include "Figure.h"
#include "../Engine.h"

class Square : public Figure {
public:
    Square(Engine::Point p1, Engine::Point p2, Engine::Point p3, Engine::Point p4) {
        points = {p1, p2, p3, p4};
    }
    void draw() override;

    void draw(sf::Color color);
};

#endif //SILNIK2D_SQUARE_H