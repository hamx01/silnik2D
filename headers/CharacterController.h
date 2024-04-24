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
    void moveUp(float speed);

    void moveDown();
    void moveDown(float speed);

    void moveLeft();
    void moveLeft(float speed);

    void moveRight();
    void moveRight(float speed);

    void flipLeft();

    void flipRight();




};

#endif //SILNIK2D_CHARACTERCONTROLLER_H
