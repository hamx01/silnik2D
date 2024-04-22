//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//
#include <iostream>
#include "Engine.h"
#include "headers/Square.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

sf::RenderWindow Engine::_window;
sf::Clock Engine::_clock;
sf::Sprite Engine::bitmapSprite;
sf::Vector2f Engine::prevMousePos;
sf::Keyboard::Key wybor;




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

Square square(Engine::Point(200.0, 200.0), Engine::Point(200.0, 50), Engine::Point(350.0, 50), Engine::Point(350, 200));



bool isFilled = true;

std::vector<Engine::Point> triangle = {pointTriangle1, pointTriangle2, pointTriangle3};
//std::vector<Engine::Point> square = {pointSquare1, pointSquare2, pointSquare3, pointSquare4};

void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(800, 600, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    // Wczytaj plik bitmapowy
    sf::Texture bitmapTexture;
    if (!bitmapTexture.loadFromFile("../img/bitmap.bmp")) {
        // Obsługa błędu, jeśli wczytanie obrazu nie powiedzie się
        std::cerr << "Failed to load bitmap image!" << std::endl;
        return;
    }

    // Przypisz teksturę do sprite'a
    bitmapSprite.setTexture(bitmapTexture);

    bitmapSprite.setPosition(0, float(_window.getSize().y) - bitmapSprite.getGlobalBounds().height);

    engineLoop();
}

void Engine::engineLoop() {
    while (_window.isOpen()) {
        float deltaTime = Engine::_clock.restart().asSeconds();
        _window.clear();
        // Handle input
        sf::Event event{};
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    testPoint.setCoordinates(float(event.mouseButton.x), float(event.mouseButton.y));
                } else if(event.mouseButton.button == sf::Mouse::Right) {
                    testPoint.setCoordinates(float(event.mouseButton.x), float(event.mouseButton.y));
                    std::cout << "New coordinates of test point: X-" << testPoint.getCoordinates().first << " Y-" << testPoint.getCoordinates().second << "\n";
                }

                else if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
//                        if (Engine::PrimitiveRenderer::isPointInsidePolygon(square, testPoint)) {
//                            std::cout << "Point is inside figure" << std::endl;
//                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                        // Oblicz przesunięcie myszy względem poprzedniego położenia myszy
                        sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                        sf::Vector2f delta = mousePos - prevMousePos;

                        // Zmień rozmiar bitmapy w zależności od kierunku ruchu myszy
                        if (delta.x < 0) {
                            bitmapSprite.setScale(bitmapSprite.getScale().x * 0.99f, bitmapSprite.getScale().y);
                        } else if (delta.x > 0) {
                            bitmapSprite.setScale(bitmapSprite.getScale().x * 1.01f, bitmapSprite.getScale().y);
                        }
                        if (delta.y < 0) {
                            bitmapSprite.setScale(bitmapSprite.getScale().x, bitmapSprite.getScale().y * 0.99f);
                        } else if (delta.y > 0) {
                            bitmapSprite.setScale(bitmapSprite.getScale().x, bitmapSprite.getScale().y * 1.01f);
                        }

                        // Zapisz aktualne położenie myszy jako poprzednie położenie
                        prevMousePos = mousePos;
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) &&
                            bitmapSprite.getGlobalBounds().contains(sf::Vector2f(float(event.mouseMove.x), float(event.mouseMove.y)))) {


                        sf::Vector2f mousePosition = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                        bitmapSprite.setPosition(mousePosition - sf::Vector2f(bitmapSprite.getGlobalBounds().width / 2, bitmapSprite.getGlobalBounds().height / 2));
                    }
                }
            }
        }

        // Test klasy Primitives
//        Engine::PrimitiveRenderer::drawPoint(pointTriangle1);
//        Engine::PrimitiveRenderer::drawPoint(pointTriangle2);

//        Engine::PrimitiveRenderer::drawLine(pointTriangle1,pointTriangle2, sf::Color::Red);
//        Engine::PrimitiveRenderer::drawLine(point5,point6, sf::Color::Blue);
//        Engine::PrimitiveRenderer::drawTriangle(triangle, sf::Color::Red);
//        Engine::PrimitiveRenderer::drawSquare(square,sf::Color::Red);
//        Engine::PrimitiveRenderer::drawCircle(pointCircle, 50, sf::Color::Red);
//        Engine::PrimitiveRenderer::drawCircleSymetric(pointCircleSymetric, 50, sf::Color::Red);
    square.draw(sf::Color::Blue);



        if(Engine::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
            wybor = sf::Keyboard::F1;
        }
        if(Engine::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            wybor = sf::Keyboard::F2;
        }

        switch(wybor) {
            case sf::Keyboard::F1:
                if(Engine::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "'Down'" << std::endl;
                    square.moveDown();
                }
                break;
            case sf::Keyboard::F2:
                //ruszanie trójkątem
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "'Down'" << std::endl;
                    Engine::PrimitiveRenderer::translatePolygon(triangle, 0, 10.0f);
                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "'Up'" << std::endl;
                    Engine::PrimitiveRenderer::translatePolygon(triangle, 0, -10.0f);
                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "'Left'" << std::endl;
                    Engine::PrimitiveRenderer::translatePolygon(triangle, -10.0f, 0);
                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "'Right'" << std::endl;
                    Engine::PrimitiveRenderer::translatePolygon(triangle, 10.0f, 0);
                }
                if(Engine::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    Engine::PrimitiveRenderer::rotatePolygon(triangle, 30.0f, deltaTime);
                } else if(Engine::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    Engine::PrimitiveRenderer::rotatePolygon(triangle, -30.0f, deltaTime);
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            PrimitiveRenderer::scalePolygon(triangle, 1.1f); // Powiększenie kwadratu o 10%
                        }
                        else {
                            PrimitiveRenderer::scalePolygon(triangle, 0.9f); // Pomniejszenie kwadratu o 10%
                        }
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Right) {
                    isFilled = false;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        isFilled = true;
                    }
                }
                if(!isFilled) {
                    Engine::PrimitiveRenderer::fillSquare(triangle, sf::Color::Red, testPoint);
                }
                break;
        }

        _window.draw(bitmapSprite);

        // mouse test begin
        sf::Vector2i mousePosition = Mouse::getPosition(_window);
        sf::CircleShape cursor(5.f);
        cursor.setFillColor(sf::Color::Red);
        cursor.setPosition(static_cast<sf::Vector2f>(mousePosition));
        _window.draw(cursor);
		//mouse test end



        _window.display();
    }




}
