#include "../headers/Game.h"

void Game::start() {
    _window.create(sf::VideoMode(800, 600), "Game");
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
        }
        _window.clear();
        _window.display();
    }

}
