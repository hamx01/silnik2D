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
    void moveLeft(float speed) override;
    void moveRight() override;
    void moveRight(float speed) override;
    void moveUp() override;
    void moveUp(float speed) override;
    void moveDown() override;
    void moveDown(float speed) override;
    void increaseSize() override;
    void increaseSize(float speed) override;
    void decreaseSize() override;
    void decreaseSize(float speed) override;
    void scaleSize(float scaleFactor);
};

#endif //SILNIK2D_CIRCLE_H
