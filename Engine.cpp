//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "iostream"

sf::RenderWindow Engine::_window;
//sf::Clock Engine::_clock;


Engine::Cordinates point(500.0,300.0);
Engine::Cordinates point2(550.0,350.0);
void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(1280, 720, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    point2.setColor(sf::Color::Blue);
    point.setColor(sf::Color::Red);

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
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    point.set_coordinates(event.mouseButton.x, event.mouseButton.y);
                    std::cout << "New coordinates of red point: X-" << point.getCoordinates().first << " Y-" << point.getCoordinates().second << "\n";
                } else if(event.mouseButton.button == sf::Mouse::Right) {
                    point2.set_coordinates(event.mouseButton.x, event.mouseButton.y);
                    std::cout << "New coordinates of blue point: X-" << point2.getCoordinates().first << " Y-" << point2.getCoordinates().second << "\n";
                }
            }
        }



        // mouse test begin
        sf::Vector2i mousePosition = Mouse::getPosition(_window);
        bool isLeftButtonPressed = Mouse::isButtonPressed(sf::Mouse::Left);
        sf::CircleShape cursor(5.f);
        cursor.setFillColor(sf::Color::Red);
        cursor.setPosition(static_cast<sf::Vector2f>(mousePosition));
        _window.draw(cursor);
		//mouse test end

        _window.draw(point);
        _window.draw(point2);
        _window.display();
    }
}
