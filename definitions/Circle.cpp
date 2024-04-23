//
// Created by asoli on 23.04.2024.
//

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

void Circle::moveRight() {
    PrimitiveRenderer::translateCircle(point, R, 10, 0);
}

void Circle::moveUp() {
    PrimitiveRenderer::translateCircle(point, R, 0, -10);
}

void Circle::moveDown() {
    PrimitiveRenderer::translateCircle(point, R, 0, 10);
}

void Circle::increaseSize() {
    scaleSize(1.1f);
}

void Circle::decreaseSize() {
    scaleSize(0.9f);
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
        std::cerr << "Scaling would cause the circle to exceed the window boundaries." << std::endl;
    }
}



