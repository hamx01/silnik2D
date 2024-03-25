//
// Created by Andrii Solianyk on 25/03/2024.
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
public:
    static void start();
    static void gameLoop();
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SILNIK2D_ENGINE_H
