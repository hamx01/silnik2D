#ifndef SILNIK2D_FIGURE_H
#define SILNIK2D_FIGURE_H

#include <vector>
#include "../Engine.h"
#include "Point.h"

class Figure : public sf::Drawable, public sf::Transformable {
protected:
    bool isFilled{};
    bool withinBounds{};
    std::vector<Point> points;
public:
    const vector<Point> &getPoints() const;

public:
    Figure() {
        isFilled = false;
        withinBounds = true;
    }

    virtual void draw() = 0;
    virtual void moveLeft();
    virtual void moveLeft(float speed);
    virtual void moveRight();
    virtual void moveRight(float speed);
    virtual void moveUp();
    virtual void moveUp(float speed);
    virtual void moveDown();
    virtual void moveDown(float speed);
    virtual void rotateLeft(float deltaTime);
    virtual void rotateLeft(float deltaTime, float speed);
    virtual void rotateRight(float deltaTime);
    virtual void rotateRight(float deltaTime, float speed);
    virtual void increaseSize();
    virtual void increaseSize(float speed);
    virtual void decreaseSize();
    virtual void decreaseSize(float speed);
    virtual void fill();
    virtual void unfill();

};


#endif //SILNIK2D_FIGURE_H
