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
#include "headers/Game.h"

sf::RenderWindow Engine::_window;
sf::Clock Engine::_clock;
sf::Sprite Engine::bitmapSprite;
sf::Vector2f Engine::prevMousePos;
std::vector<std::string> walkFrames;
std::vector<std::string> idleFrames;
AnimatedCharacter character(walkFrames, idleFrames, 100.0f, 100.0f);
CharacterController characterController{character.getSprite(), character};
Game pong;
sf::Keyboard::Key wybor;


Point testPoint(150.0, 50);

Square square(Point(200.0, 200.0), Point(200.0, 50), Point(350.0, 50), Point(350, 200));
Triangle triangle(Point(310.0, 319.0), Point(598.0, 316.0), Point(427.0, 177.0));
Circle circle(Point(200, 250), 60);

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
    // Obs
    for (int i = 0; i < 10; ++i) {
        walkFrames.push_back("../Sprites/HeroKnight/Run/HeroKnight_Run_" + std::to_string(i) + ".png");
    }
    for (int i = 0; i < 8; ++i) {
        idleFrames.push_back("../Sprites/HeroKnight/Idle/HeroKnight_Idle_" + std::to_string(i) + ".png");
    }
    character = AnimatedCharacter(walkFrames, idleFrames, 100, 100);

    engineLoop();
}

void Engine::engineLoop() {
    while (_window.isOpen()) {
        float deltaTime = Engine::_clock.restart().asSeconds();
        _window.clear();
        // Handle input
        sf::Event event{};
        while (_window.pollEvent(event)) {
            bool runningPong = false; // Flaga informująca, czy gra Pong jest uruchomiona
            if (event.type == sf::Event::Closed) { _window.close(); }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    testPoint.setCoordinates(float(event.mouseButton.x), float(event.mouseButton.y));
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                if (Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (Keyboard::isKeyPressed(sf::Keyboard::M)) {
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
                    else if (Keyboard::isKeyPressed(sf::Keyboard::L) &&
                        bitmapSprite.getGlobalBounds().contains(sf::Vector2f(float(event.mouseMove.x), float(event.mouseMove.y)))) {
                        sf::Vector2f mousePosition = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                        bitmapSprite.setPosition(mousePosition - sf::Vector2f(bitmapSprite.getGlobalBounds().width / 2, bitmapSprite.getGlobalBounds().height / 2));
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
                runningPong = true;
                pong.run(_window);

            case sf::Keyboard::F9:
                runningPong = false;
                // Clear the window
                _window.clear();
            default:
                break;
        }

        _window.draw(bitmapSprite);
        square.draw(sf::Color::Blue);
        triangle.draw(sf::Color::Green);
        circle.draw(sf::Color::Red);

        character.update();
        _window.draw(character.getSprite());



        _window.display();
    }




}

std::pair<float, float> Engine::getWindowSize() {
    std::pair<float, float> windowSize;
    windowSize.first = float(_window.getSize().x);
    windowSize.second = float(_window.getSize().y);
    return windowSize;
}

sf::RenderWindow& Engine::getWindow() {
    return _window;
}
