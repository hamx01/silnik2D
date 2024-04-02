//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
public:
    static void start();
    static void engineLoop();
    class Keyboard {};
    class Mouse {
    public:
        static sf::Vector2i getPosition() {
            return sf::Mouse::getPosition();
        }

        static sf::Vector2i getPosition(const sf::RenderWindow& relativeTo) {
            return sf::Mouse::getPosition(relativeTo);
        }

        static bool isButtonPressed(sf::Mouse::Button button) {
            return sf::Mouse::isButtonPressed(button);
        }
    };
    class Cordinates {};
    class Figures {};
private:
    static sf::RenderWindow _window;
//    static sf::Clock _clock;
};


#endif //SILNIK2D_ENGINE_H
