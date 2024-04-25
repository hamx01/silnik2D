#include <utility>

#include "../headers/Circle.h"
#include "../headers/PrimitiveRenderer.h"

Circle::Circle(Point point, float Rr) {
    this->R = Rr;
    this->point = std::move(point);
}

void Circle::draw() {
    PrimitiveRenderer::drawCircle(point, R, sf::Color::White);
}

void Circle::draw(sf::Color color) {
    PrimitiveRenderer::drawCircle(point, R, color);
    if(isFilled) {
        PrimitiveRenderer::fillCircle(point, R, color);
    }
}

void Circle::moveLeft() {
    float speed = -10;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(point.getCoordinates().first + speed, point.getCoordinates().second);
}

void Circle::moveLeft(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first - speed;
    float new_y = point.getCoordinates().second;
    if (new_x - R < 0) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, -speed, 0);
    point.setCoordinates(new_x, new_y);
}

void Circle::moveRight() {
    float speed = 10;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(point.getCoordinates().first + speed, point.getCoordinates().second);
}

void Circle::moveRight(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first + speed;
    float new_y = point.getCoordinates().second;
    if (new_x + R > Engine::getWindowSize().first) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(new_x, new_y);
}

void Circle::moveUp() {
    float speed = -10;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(point.getCoordinates().first, point.getCoordinates().second + speed);
}

void Circle::moveUp(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first;
    float new_y = point.getCoordinates().second - speed;
    if (new_y - R < 0) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, 0, -speed);
    point.setCoordinates(new_x, new_y);
}

void Circle::moveDown() {
    float speed = 10;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(point.getCoordinates().first, point.getCoordinates().second + speed);
}

void Circle::moveDown(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first;
    float new_y = point.getCoordinates().second + speed;
    if (new_y + R > Engine::getWindowSize().second) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(new_x, new_y);
}

void Circle::increaseSize() {
    scaleSize(1.1f);
}

void Circle::increaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    scaleSize(1.1f + speed / 100.0f);
}

void Circle::decreaseSize() {
    scaleSize(0.9f);
}

void Circle::decreaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    scaleSize(0.9f - speed / 100.0f);
}

void Circle::scaleSize(float scaleFactor) {
    float newRadius = R * scaleFactor;
    float windowWidth = Engine::getWindowSize().first;
    float windowHeight = Engine::getWindowSize().second;

    if (newRadius > 0 &&
        point.getCoordinates().first + newRadius < windowWidth &&
        point.getCoordinates().second + newRadius < windowHeight &&
        point.getCoordinates().first - newRadius > 0 &&
        point.getCoordinates().second - newRadius > 0) {
        R = newRadius;
    } else {

    }
}

const Point &Circle::getPoint() const {
    return point;
}

float Circle::getR() const {
    return R;
}

void Circle::setCoordinates(float x, float y) {
    point.setCoordinates(x, y);
}

void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

void Circle::move(float x, float y) {
    PrimitiveRenderer::translateCircle(point, R, x, y);
}



