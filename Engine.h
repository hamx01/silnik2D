//
// Created by Andrii Solianyk on 25/03/2024.
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
public:
    static void start();
    static void engineLoop();
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
    class Keyboard {};
    class Mouse {};
    class Cordinates {};
    class Figures {};
};


#endif //SILNIK2D_ENGINE_H
