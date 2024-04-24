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
    PrimitiveRenderer::translateCircle(point, R, -10, 0);
}

void Circle::moveLeft(float speed) {
    if(speed > 0) speed *= -1;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
}

void Circle::moveRight() {
    PrimitiveRenderer::translateCircle(point, R, 10, 0);
}

void Circle::moveRight(float speed) {
    if(speed < 0) speed *= -1;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
}

void Circle::moveUp() {
    PrimitiveRenderer::translateCircle(point, R, 0, -10);
}

void Circle::moveUp(float speed) {
    if(speed > 0) speed *= -1;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
}

void Circle::moveDown() {
    PrimitiveRenderer::translateCircle(point, R, 0, 10);
}

void Circle::moveDown(float speed) {
    if(speed < 0) speed *= -1;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
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



