//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_CHARACTERCONTROLLER_H
#define SILNIK2D_CHARACTERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "AnimatedCharacter.h"

class CharacterController {
private:
    sf::Sprite& characterSprite;
    AnimatedCharacter& character;
public:
    CharacterController(sf::Sprite &characterSprite, AnimatedCharacter &character);

    void move(float deltaX, float deltaY);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void flipLeft();

    void flipRight();
};

#endif //SILNIK2D_CHARACTERCONTROLLER_H
