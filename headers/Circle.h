//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_CIRCLE_H
#define SILNIK2D_CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
private:
    float R;
    Point point = Point(0, 0);
public:
    Circle(Point point, float R);

    void draw() override;

    void draw(sf::Color color);

    void moveLeft() override;
    void moveRight() override;
    void moveUp() override;
    void moveDown() override;
    void increaseSize() override;
    void decreaseSize() override;
    void scaleSize(float scaleFactor);
};

#endif //SILNIK2D_CIRCLE_H
