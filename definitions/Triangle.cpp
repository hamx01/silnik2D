#include "../headers/Triangle.h"

void Triangle::draw() {
    Engine::PrimitiveRenderer::drawTriangle(points, sf::Color::White);
    if(isFilled) {
        Engine::PrimitiveRenderer::fillSquare(points, sf::Color::White);
    }
}

void Triangle::draw(sf::Color color) {
    Engine::PrimitiveRenderer::drawTriangle(points, color);
    if(isFilled) {
        Engine::PrimitiveRenderer::fillSquare(points, color);
    }
}
