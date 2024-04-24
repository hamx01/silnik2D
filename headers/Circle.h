#ifndef SILNIK2D_CIRCLE_H
#define SILNIK2D_CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
private:
    float R{};
public:
    float getR() const;

private:
    Point point = Point(0, 0);
public:
    const Point &getPoint() const;

public:
    Circle() = default;

    Circle(Point point, float R);

    void draw() override;

    void draw(sf::Color color);
    void move(float x, float y) override;
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
    void setCoordinates(float x, float y);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SILNIK2D_CIRCLE_H
