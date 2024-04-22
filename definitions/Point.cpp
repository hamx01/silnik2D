//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../Engine.h"

std::pair<float, float> Engine::Point::getCoordinates() const {
    return std::make_pair(x, y);
}

void Engine::Point::setCoordinates(float new_x, float new_y) {
    this->x = new_x;
    this->y = new_y;
    shape.setPosition(new_x, new_y);
}

void Engine::Point::setColor(sf::Color color) {
    shape.setFillColor(color);
}

void Engine::Point::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}

Engine::Point::Point(float x, float y) {
    shape.setPosition(x, y);
    this->x = x;
    this->y = y;
    this->shape = sf::CircleShape(5.0f);
}

Engine::Point::Point(float x, float y, sf::Color color) {
    shape.setPosition(x, y);
    shape.setRadius(5.0f);
    shape.setFillColor(color);
    this->x = x;
    this->y = y;
}