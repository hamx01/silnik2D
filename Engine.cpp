//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//
#include <iostream>
#include "Engine.h"
#include "headers/Triangle.h"
#include "headers/Square.h"
#include "headers/Circle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "headers/Point.h"
#include "headers/Keyboard.h"
#include "headers/Mouse.h"
#include "headers/AnimatedCharacter.h"
#include "headers/Bitmap.h"
#include "headers/PongGame.h"

sf::RenderWindow Engine::_window;
sf::RenderWindow Engine::_game;
sf::Clock Engine::_clock;
sf::Vector2f prevMousePos;
AnimatedCharacter character(100.0f, 100.0f);
CharacterController characterController{character.getSprite(), character};

Bitmap myBitmap("../img/bitmap.bmp", 150, 150);

PongGame pongGame(Engine::getGameWindow());

sf::Keyboard::Key wybor;

Point testPoint(150.0, 50);

Square square(Point(200.0, 200.0), Point(200.0, 50), Point(350.0, 50), Point(350, 200));
Triangle triangle(Point(310.0, 319.0), Point(598.0, 316.0), Point(427.0, 177.0));
Circle circle(Point(200, 250), 60);
//! @brief - Rozpoczyna działanie silnika gry.
//! Inicjalizuje okno gry, ustawia limit FPS i inicjalizuje inne komponenty gry.
void Engine::start() {
    if (_window.isOpen()) return;

    isWindow1Active = true;

    _window.create(sf::VideoMode(800, 600, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    sf::Texture bitmapTexture;

//    pongGame.run();

    character.loadWalkFrames("../Sprites/HeroKnight/Run/HeroKnight_Run_");
    character.loadIdleFrames("../Sprites/HeroKnight/Run/HeroKnight_Run_");

    engineLoop();
}
//! @brief - Główna pętla silnika gry.
//! Obsługuje wszystkie zdarzenia wejściowe, aktualizacje stanu gry oraz rendering.
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
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                if (Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (Keyboard::isKeyPressed(sf::Keyboard::R)) {
                        sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                        sf::Vector2f delta = mousePos - prevMousePos;

                        prevMousePos = mousePos;

                        if (delta.x > 0) {
                            myBitmap.moveRight(10);
                        } else if (delta.x < 0) {
                            myBitmap.moveLeft(10);
                        }

                        if (delta.y > 0) {
                            myBitmap.moveDown(10);
                        } else if (delta.y < 0) {
                            myBitmap.moveUp(10);
                        }
                    }
                    else if (Keyboard::isKeyPressed(sf::Keyboard::L)) {
                        sf::Vector2f mousePosition = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                        sf::FloatRect bitmapBounds = myBitmap.getSprite().getGlobalBounds();

                        if (bitmapBounds.contains(mousePosition)) {
                            myBitmap.setPosition(mousePosition.x - bitmapBounds.width / 2, mousePosition.y - bitmapBounds.height / 2);
                        }
                    }
                }
            }
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::F1)) {
            wybor = sf::Keyboard::F1;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            wybor = sf::Keyboard::F2;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F3)) {
            wybor = sf::Keyboard::F3;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F4)) {
            wybor = sf::Keyboard::F4;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F8)) {
            wybor = sf::Keyboard::F8;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F9)) {
            wybor = sf::Keyboard::F9;
        }

        switch(wybor) {
            case sf::Keyboard::F1:
                //ruszanie kwadratem
                if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    square.moveDown();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    square.moveUp();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    square.moveLeft();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    square.moveRight();
                }
                if(Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    square.rotateRight(deltaTime, 5);
                } else if(Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    square.rotateLeft(deltaTime, 15);
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            square.increaseSize(70);
                        }
                        else {
                            square.decreaseSize(20);
                        }
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Right) {
                    square.fill();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    square.unfill();
                    }
                }
                break;
            case sf::Keyboard::F2:
                //ruszanie trójkątem
                if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    triangle.moveDown();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    triangle.moveUp();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    triangle.moveLeft();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    triangle.moveRight();
                }
                if(Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    triangle.rotateRight(deltaTime);
                } else if(Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    triangle.rotateLeft(deltaTime);
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            triangle.increaseSize();
                        }
                        else {
                            triangle.decreaseSize();
                        }
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Right) {
                    triangle.fill();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        triangle.unfill();
                    }
                }
                break;
            case sf::Keyboard::F3:
                //ruszanie kołem
                if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    circle.moveDown(40);
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    circle.moveUp(40);
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    circle.moveLeft(40);
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    circle.moveRight(40);
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            circle.increaseSize(50);
                        }
                        else {
                            circle.decreaseSize();
                        }
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Right) {
                    circle.fill();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        circle.unfill();
                    }
                }
                break;
            case sf::Keyboard::F4:
                //ruszanie ludzikiem
                character.setWalking(false);
                if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    characterController.moveDown();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    characterController.moveUp();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    characterController.moveLeft();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    characterController.moveRight();
                }
                break;
            case sf::Keyboard::F8:
                if (!_game.isOpen()) {
                    _game.create(sf::VideoMode(800, 600, 32), "Pong");
                    Engine::switchActiveWindow();
                    pongGame.run();
                }
                break;
            case sf::Keyboard::F9:
                if (_game.isOpen()) {
                    Engine::closeActiveWindow();
                }
                break;
        }

        square.draw(sf::Color::Blue);
        triangle.draw(sf::Color::Green);
        circle.draw(sf::Color::Red);

        character.update();

        _window.draw(character.getSprite());
//        _window.draw(mySprite.getSprite());
        _window.draw(myBitmap.getSprite());

        _window.display();
    }
}
//! @brief - Pobiera rozmiar głównego okna.
//! @return Para float reprezentująca szerokość i wysokość okna.
std::pair<float, float> Engine::getWindowSize() {
    std::pair<float, float> windowSize;
    windowSize.first = float(_window.getSize().x);
    windowSize.second = float(_window.getSize().y);
    return windowSize;
}
//! @brief - Zwraca referencję do głównego okna renderowania.
//! @return Referencja do głównego okna sf::RenderWindow.
sf::RenderWindow& Engine::getWindow() {
    return _window;
}
//! @brief - Zmienna statyczna wskazująca, czy główne okno gry jest aktywne.
bool Engine::isWindow1Active = true;
