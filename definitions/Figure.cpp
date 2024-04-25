#include "../headers/Figure.h"
#include "../headers/PrimitiveRenderer.h"

void Figure::moveLeft() {
    PrimitiveRenderer::translatePolygon(points, -10.0f, 0);
}

void Figure::moveLeft(float speed) {
    if(speed > 0) speed *= -1;
    if(speed < -100) speed = -100;
    PrimitiveRenderer::translatePolygon(points, speed, 0);
}

void Figure::moveRight() {
    PrimitiveRenderer::translatePolygon(points, 10.0f, 0);
}

void Figure::moveRight(float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::translatePolygon(points, speed, 0);
}

void Figure::moveDown() {
    PrimitiveRenderer::translatePolygon(points, 0, 10.0f);
}

void Figure::moveDown(float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::translatePolygon(points, 0, speed);
}

void Figure::moveUp() {
    PrimitiveRenderer::translatePolygon(points, 0, -10.0f);
}

void Figure::moveUp(float speed) {
    if(speed > 0) speed *= -1;
    if(speed < 100) speed = -100;
    PrimitiveRenderer::translatePolygon(points, 0, speed);
}

void Figure::rotateLeft(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, -15.0f, deltaTime);
}

void Figure::rotateLeft(float deltaTime, float speed) {
    if(speed > 0) speed *= -1;
    if(speed < 100) speed = -100;
    PrimitiveRenderer::rotatePolygon(points, speed, deltaTime);
}

void Figure::rotateRight(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, 15.0f, deltaTime);
}

void Figure::rotateRight(float deltaTime, float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::rotatePolygon(points, speed, deltaTime);
}

void Figure::increaseSize() {
    PrimitiveRenderer::scalePolygon(points, 1.1f);
}

void Figure::increaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    PrimitiveRenderer::scalePolygon(points, 1.1f + speed / 10.0f);
}

void Figure::decreaseSize() {
    PrimitiveRenderer::scalePolygon(points, 0.9f);
}

void Figure::decreaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    PrimitiveRenderer::scalePolygon(points, 0.9f - speed / 10.0f);
}

void Figure::fill() {
    isFilled = true;
}

void Figure::unfill() {
    isFilled = false;
}

const std::vector<Point> &Figure::getPoints() const {
    return points;
}
