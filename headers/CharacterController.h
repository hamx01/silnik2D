//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_CHARACTERCONTROLLER_H
#define SILNIK2D_CHARACTERCONTROLLER_H

#include <SFML/Graphics.hpp>

class CharacterController {
private:
    sf::Sprite& characterSprite;

public:
    CharacterController(sf::Sprite& characterSprite) : characterSprite(characterSprite) {}

    void move(float deltaX, float deltaY) {
        characterSprite.move(deltaX, deltaY);
    }
};

#endif //SILNIK2D_CHARACTERCONTROLLER_H
