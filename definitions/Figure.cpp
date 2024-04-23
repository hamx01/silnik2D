#include "../headers/Figure.h"
#include "../headers/PrimitiveRenderer.h"

void Figure::moveLeft() {
    PrimitiveRenderer::translatePolygon(points, -10.0f, 0);
}

void Figure::moveRight() {
    PrimitiveRenderer::translatePolygon(points, 10.0f, 0);
}

void Figure::moveDown() {
    PrimitiveRenderer::translatePolygon(points, 0, 10.0f);
}

void Figure::moveUp() {
    PrimitiveRenderer::translatePolygon(points, 0, -10.0f);
}

void Figure::rotateLeft(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, -15.0f, deltaTime);
}

void Figure::rotateRight(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, 15.0f, deltaTime);
}

void Figure::increaseSize() {
    PrimitiveRenderer::scalePolygon(points, 1.1f);
}

void Figure::decreaseSize() {
    PrimitiveRenderer::scalePolygon(points, 0.9f);
}

void Figure::fill() {
    isFilled = true;
}

void Figure::unfill() {
    isFilled = false;
}
