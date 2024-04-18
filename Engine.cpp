//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//
#include <iostream>
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

sf::RenderWindow Engine::_window;
//sf::Clock Engine::_clock;


Engine::Point pointTriangle1(310.0, 319.0);
Engine::Point pointTriangle2(598.0, 316.0);
Engine::Point pointTriangle3(427.0, 177.0);

Engine::Point point5(100.0, 200.0);
Engine::Point point6(200.0, 200.0);

Engine::Point testPoint(150.0, 50);

Engine::Point pointSquare1(200.0, 200.0);
Engine::Point pointSquare2(200.0, 50);
Engine::Point pointSquare3(350.0, 50);
Engine::Point pointSquare4(350, 200);

Engine::Point pointCircle(600, 400);
Engine::Point pointCircleSymetric(400, 400);

std::vector<Engine::Point> triangle = {pointTriangle1, pointTriangle2, pointTriangle3};
std::vector<Engine::Point> square = {pointSquare1, pointSquare2, pointSquare3, pointSquare4};

void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(800, 600, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

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
                    testPoint.setCoordinates(float(event.mouseButton.x), float(event.mouseButton.y));
                    if(Engine::PrimitiveRenderer::isPointInsidePolygon(square, testPoint)){
                        std::cout << "Point is inside figure" << std::endl;
                    }
                    else{
                        std::cout << "Point is not inside figure" << std::endl;
                    }
                } else if(event.mouseButton.button == sf::Mouse::Right) {
//                    Engine::PrimitiveRenderer::MousePosition lastPosition;
//                    lastPosition.x = 150;
//                    lastPosition.y = 50;
//                    Engine::PrimitiveRenderer::dragPolygon(square, testPoint, true, lastPosition, event);

//                    point2.setCoordinates(event.mouseButton.x, event.mouseButton.y);
//                    std::cout << "New coordinates of blue point: X-" << point2.getCoordinates().first << " Y-" << point2.getCoordinates().second << "\n";
                }
            }
        }

        // Test klasy Primitives
//        Engine::PrimitiveRenderer::drawPoint(pointTriangle1);
//        Engine::PrimitiveRenderer::drawPoint(pointTriangle2);
        Engine::PrimitiveRenderer::drawLine(pointTriangle1,pointTriangle2, sf::Color::Red);
        Engine::PrimitiveRenderer::drawLine(point5,point6, sf::Color::Blue);
        Engine::PrimitiveRenderer::drawTriangle(pointTriangle1,pointTriangle2,pointTriangle3, sf::Color::Red);
        Engine::PrimitiveRenderer::drawSquare(pointSquare1,pointSquare2,pointSquare3,pointSquare4,sf::Color::Red);
        Engine::PrimitiveRenderer::drawCircle(pointCircle, 50, sf::Color::Red);
        Engine::PrimitiveRenderer::drawCircleSymetric(pointCircleSymetric, 50, sf::Color::Red);
//        Engine::PrimitiveRenderer::fillCircle(pointCircle,50,sf::Color::Red);
//        Engine::PrimitiveRenderer::MousePosition position = Engine::PrimitiveRenderer::getMousePosition(event);
//        std::cout << "x: " << position.x << "\n";
//        std::cout << "y: " << position.y << "\n";





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

        // ruszanie trókątem
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "'Down'" << std::endl;
            Engine::PrimitiveRenderer::translateSquare(pointSquare1, pointSquare2, pointSquare3, pointSquare4, 0, 10);
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "'Up'" << std::endl;
            Engine::PrimitiveRenderer::translateSquare(pointSquare1, pointSquare2, pointSquare3, pointSquare4, 0, -10);
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            std::cout << "'Left'" << std::endl;
            Engine::PrimitiveRenderer::translateSquare(pointSquare1, pointSquare2, pointSquare3, pointSquare4, -10, 0);
        }
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "'Right'" << std::endl;
            Engine::PrimitiveRenderer::translateSquare(pointSquare1, pointSquare2, pointSquare3, pointSquare4, 10, 0);
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
