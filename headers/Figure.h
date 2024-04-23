#ifndef SILNIK2D_FIGURE_H
#define SILNIK2D_FIGURE_H

#include <vector>
#include "../Engine.h"
#include "Point.h"

class Figure {
protected:
    bool isFilled{};
    bool withinBounds{};
    std::vector<Point> points;
public:
    Figure() {
        isFilled = false;
        withinBounds = true;
    }

    virtual void draw() = 0;
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();
    virtual void rotateLeft(float deltaTime);
    virtual void rotateRight(float deltaTime);
    virtual void increaseSize();
    virtual void decreaseSize();
    virtual void fill();
    virtual void unfill();
};


#endif //SILNIK2D_FIGURE_H
