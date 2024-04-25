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
private:
    static sf::RenderWindow _window;
    static sf::RenderWindow _game;
    static sf::Clock _clock;
    static bool isWindow1Active;
public:
    static void start();

    static void engineLoop();

    static std::pair<float, float> getWindowSize();

    static sf::RenderWindow& getWindow();

    static sf::RenderWindow& getGameWindow() {
        return _game;
    }

    static sf::RenderWindow& getActiveWindow() {
        if (isWindow1Active) {
            return _window;
        } else {
            return _game;
        }
    }

    static void switchActiveWindow() {
        isWindow1Active = !isWindow1Active;
    }

    static void closeActiveWindow() {
        if (!isWindow1Active) {
            _game.close();
            isWindow1Active = true;
        }
    }
};

#endif //SILNIK2D_ENGINE_H
