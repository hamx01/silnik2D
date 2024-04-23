//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../headers/Mouse.h"

sf::Vector2i Mouse::getPosition() {
    return sf::Mouse::getPosition();
}

sf::Vector2i Mouse::getPosition(const sf::RenderWindow& relativeTo) {
    return sf::Mouse::getPosition(relativeTo);
}

bool Mouse::isButtonPressed(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}