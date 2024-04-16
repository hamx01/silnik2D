//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//
#include <iostream>
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

sf::RenderWindow Engine::_window;
//sf::Clock Engine::_clock;


Engine::Coordinates point(310.0,319.0);
Engine::Coordinates point2(598.0,316.0);
Engine::Coordinates point3(427.0,177.0);

Engine::Coordinates point5(100.0,200.0);
Engine::Coordinates point6(200.0,200.0);

Engine::Coordinates pointSquare1(200.0,200.0);
Engine::Coordinates pointSquare2(200.0,50);
Engine::Coordinates pointSquare3(350.0,50);
Engine::Coordinates pointSquare4(350, 200);

Engine::Coordinates pointCircle(600,400);
Engine::Coordinates pointCircleSymetric(400,400);


void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(800, 600, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    point2.setColor(sf::Color::Blue);
    point.setColor(sf::Color::Red);

    engineLoop();
}

void Engine::engineLoop() {
    while (_window.isOpen()) {
        _window.clear();
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

        // Test klasy Primitives
        Engine::PrimitiveRenderer::drawPoint(point);
        Engine::PrimitiveRenderer::drawPoint(point2);
        Engine::PrimitiveRenderer::drawLine(point,point2, sf::Color::Red);
        Engine::PrimitiveRenderer::drawLine(point5,point6, sf::Color::Blue);
//        Engine::PrimitiveRenderer::drawTriangle(point,point2,point3, sf::Color::Red);
        Engine::PrimitiveRenderer::drawSquare(pointSquare1,pointSquare2,pointSquare3,pointSquare4,sf::Color::Red);
//        Engine::PrimitiveRenderer::drawCircle(pointCircle, 50, sf::Color::Red);
        Engine::PrimitiveRenderer::drawCircle(pointCircle, 50, sf::Color::Red);
        Engine::PrimitiveRenderer::drawCircleSymetric(pointCircleSymetric, 50, sf::Color::Red);

        // Testowanie klasy Keyboard
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            std::cout << "'Q'" << std::endl;
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::cout << "'A'" << std::endl;
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            std::cout << "'C'" << std::endl;
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            std::cout << "'Escape'" << std::endl;
            _window.close();
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
