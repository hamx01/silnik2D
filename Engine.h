//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/AnimatedCharacter.h"
#include "headers/CharacterController.h"

class Engine {
public:
    static void start();

    static void engineLoop();

    static std::pair<float, float> getWindowSize();

    static sf::RenderWindow& getWindow();

private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
    static sf::Sprite bitmapSprite;
    static std::vector<sf::Sprite> sprites;
    static sf::Vector2f prevMousePos;
};

#endif //SILNIK2D_ENGINE_H
