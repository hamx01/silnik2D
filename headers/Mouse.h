//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_MOUSE_H
#define SILNIK2D_MOUSE_H

#include "SFML/Graphics.hpp"

class Mouse {
public:
    static sf::Vector2i getPosition();

    static sf::Vector2i getPosition(const sf::RenderWindow &relativeTo);

    static bool isButtonPressed(sf::Mouse::Button button);
};

#endif //SILNIK2D_MOUSE_H
