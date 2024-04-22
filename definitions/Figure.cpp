#include "../headers/Figure.h"
#include "../Engine.h"

void Figure::moveLeft() {
    Engine::PrimitiveRenderer::translatePolygon(points, -10.0f, 0);
}

void Figure::moveRight() {
    Engine::PrimitiveRenderer::translatePolygon(points, 10.0f, 0);
}

void Figure::moveDown() {
    Engine::PrimitiveRenderer::translatePolygon(points, 0, 10.0f);
}

void Figure::moveUp() {
    Engine::PrimitiveRenderer::translatePolygon(points, 0, -10.0f);
}

void Figure::rotateLeft(float deltaTime) {
    Engine::PrimitiveRenderer::rotatePolygon(points, -15.0f, deltaTime);
}

void Figure::rotateRight(float deltaTime) {
    Engine::PrimitiveRenderer::rotatePolygon(points, 15.0f, deltaTime);
}

void Figure::increaseSize() {
    Engine::PrimitiveRenderer::scalePolygon(points, 1.1f);
}

void Figure::decreaseSize() {
    Engine::PrimitiveRenderer::scalePolygon(points, 0.9f);
}

void Figure::fill() {
    isFilled = true;
}

void Figure::unfill() {
    isFilled = false;
}
