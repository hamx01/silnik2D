//
// Created by Andrii Solianyk on 25/03/2024.
//

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "iostream"

sf::RenderWindow Engine::_window;
sf::Clock Engine::_clock;

void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(1280, 720, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    engineLoop();
}

void Engine::engineLoop() {
    while (_window.isOpen()) {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color(255, 255, 255));

        // Handle input
        sf::Event event{};
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
        }

        _window.display();
    }
}
