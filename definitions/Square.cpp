//
// Created by asoli on 22.04.2024.
//

#include "../headers/Square.h"

void Square::draw() {
    Engine::PrimitiveRenderer::drawSquare(points, sf::Color::White);
}

void Square::draw(sf::Color color) {
    Engine::PrimitiveRenderer::drawSquare(points, color);
}
