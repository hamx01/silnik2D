#include "../headers/Square.h"
#include "../headers/PrimitiveRenderer.h"

void Square::draw() {
    PrimitiveRenderer::drawSquare(points, sf::Color::White);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, sf::Color::White);
    }
}

void Square::draw(sf::Color color) {
    PrimitiveRenderer::drawSquare(points, color);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, color);
    }
}
