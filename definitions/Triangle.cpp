#include "../headers/Triangle.h"
#include "../headers/PrimitiveRenderer.h"

void Triangle::draw() {
    PrimitiveRenderer::drawTriangle(points, sf::Color::White);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, sf::Color::White);
    }
}

void Triangle::draw(sf::Color color) {
    PrimitiveRenderer::drawTriangle(points, color);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, color);
    }
}
