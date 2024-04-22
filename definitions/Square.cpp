#include "../headers/Square.h"

void Square::draw() {
    Engine::PrimitiveRenderer::drawSquare(points, sf::Color::White);
    if(isFilled) {
        Engine::PrimitiveRenderer::fillSquare(points, sf::Color::White);
    }
}

void Square::draw(sf::Color color) {
    Engine::PrimitiveRenderer::drawSquare(points, color);
    if(isFilled) {
        Engine::PrimitiveRenderer::fillSquare(points, color);
    }
}
