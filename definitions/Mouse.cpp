//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../Engine.h"

sf::Vector2i Engine::Mouse::getPosition() {
    return sf::Mouse::getPosition();
}

sf::Vector2i Engine::Mouse::getPosition(const sf::RenderWindow& relativeTo) {
    return sf::Mouse::getPosition(relativeTo);
}

bool Engine::Mouse::isButtonPressed(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}