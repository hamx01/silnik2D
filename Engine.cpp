//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk
//

#include "Engine.h"
#include <SFML/Graphics.hpp>

sf::RenderWindow Engine::_window;
//sf::Clock Engine::_clock;

void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(1280, 720, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    engineLoop();
}

void Engine::engineLoop() {
    while (_window.isOpen()) {
//        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color(255, 255, 255));

        // Handle input
        sf::Event event{};
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
        }

        // mouse test begin
        sf::Vector2i mousePosition = Mouse::getPosition(_window);
        bool isLeftButtonPressed = Mouse::isButtonPressed(sf::Mouse::Left);
        sf::CircleShape cursor(5.f);
        cursor.setFillColor(sf::Color::Red);
        cursor.setPosition(static_cast<sf::Vector2f>(mousePosition));
        _window.draw(cursor);
		//mouse test end
		
        _window.display();
    }
}
