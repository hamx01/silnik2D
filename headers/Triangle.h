//
// Created by asoli on 22.04.2024.
//

#ifndef SILNIK2D_TRIANGLE_H
#define SILNIK2D_TRIANGLE_H

#include "Figure.h"
#include "../Engine.h"

class Triangle : public Figure {
public:
    Triangle(Engine::Point p1, Engine::Point p2, Engine::Point p3) {
        points = {p1, p2, p3};
    }
    void draw() override;
    void draw(sf::Color color);
};


#endif //SILNIK2D_TRIANGLE_H
