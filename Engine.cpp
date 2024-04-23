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

sf::RenderWindow Engine::_window;
sf::Clock Engine::_clock;
sf::Sprite Engine::bitmapSprite;
sf::Vector2f Engine::prevMousePos;
std::vector<std::string> Engine::walkFrames;
std::vector<std::string> Engine::idleFrames;
Engine::AnimatedCharacter Engine::character(walkFrames, idleFrames, 100.0f, 100.0f); // Provide the required arguments
Engine::CharacterController Engine::characterController{character.getSprite()};

Point testPoint(150.0, 50);

Point pointCircle(600, 400);
Point pointCircleSymetric(400, 400);

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


    std::vector<std::string> walkFrames;
    for (int i = 0; i < 10; ++i) {
        walkFrames.push_back("../Sprites/HeroKnight/Run/HeroKnight_Run_" + std::to_string(i) + ".png");
    }

// Wczytaj tekstury klatek animacji stanu spoczynku (idle)
    std::vector<std::string> idleFrames;
    for (int i = 0; i < 8; ++i) {
        idleFrames.push_back("../Sprites/HeroKnight/Idle/HeroKnight_Idle_" + std::to_string(i) + ".png");
    }
    // Create the AnimatedCharacter object
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

                        // Pobierz globalne granice bitmapy
                        sf::FloatRect bounds = bitmapSprite.getGlobalBounds();

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

                // W głównej pętli gry, zmodyfikujmy obsługę poruszania postacią, aby używała klawiszy H, J, K, L
            else if (Engine::Keyboard::isKeyPressed(sf::Keyboard::H) ||
                     Engine::Keyboard::isKeyPressed(sf::Keyboard::U) ||
                     Engine::Keyboard::isKeyPressed(sf::Keyboard::J) ||
                     Engine::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                character.setWalking(true);
                float deltaX = 0.0f;
                float deltaY = 0.0f;

                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                    std::cout << "'J' - Move Down" << std::endl;
                    deltaY += 3.0f;
                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                    std::cout << "'U' - Move Up" << std::endl;
                    deltaY -= 3.0f;
                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    std::cout << "'H' - Move Left" << std::endl;
                    deltaX -= 3.0f;

                }
                if (Engine::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                    std::cout << "'K' - Move Right" << std::endl;
                    deltaX += 3.0f;
                }

                // Przesuwamy postać używając CharacterController
                characterController.move(deltaX, deltaY);

            }
            else {
                character.setWalking(false); // Ustawia postać na stan spoczynku
            }

        }

        // Testowanie klasy Keyboard
        if (Engine::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            std::cout << "'Q'" << std::endl;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            wybor = sf::Keyboard::F2;
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::F3)) {
            wybor = sf::Keyboard::F3;
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
                    square.rotateRight(deltaTime);
                } else if(Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    square.rotateLeft(deltaTime);
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            square.increaseSize();
                        }
                        else {
                            square.decreaseSize();
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
                    circle.moveDown();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    circle.moveUp();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    circle.moveLeft();
                }
                if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    circle.moveRight();
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            circle.increaseSize();
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
        }

        square.draw(sf::Color::Blue);
        triangle.draw(sf::Color::Green);
        circle.draw(sf::Color::Red);

        _window.draw(bitmapSprite);

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
