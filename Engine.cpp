//
// Created by Andrii Solianyk on 25/03/2024.
//

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "iostream"

sf::RenderWindow Engine::_window;
sf::Clock Engine::_clock;

std::unordered_map<sf::Keyboard::Key, std::string> keyMap = {
        {sf::Keyboard::A, "A"},
        {sf::Keyboard::B, "B"},
        {sf::Keyboard::C, "C"},
        // Add more keys as needed
        {sf::Keyboard::Space, "Space"},
        {sf::Keyboard::Enter, "Enter"}
};

void Engine::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(1280, 720, 32), "Test Game Engine");
    _window.setFramerateLimit(60);

    gameLoop();
}

//void Engine::gameLoop() {
//    while (_window.isOpen()) {
//        float timeElapsed = _clock.restart().asSeconds();
//        _window.clear(sf::Color(255, 255, 255));
//
//        // Handle input
//        sf::Event event;
//        while (_window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) { _window.close(); }
//            // else handle controls input
//        }
//
//        // Update our entities
//
//        // Draw our new entities
//
//        _window.display();
//    }
//}

void Engine::gameLoop() {
    while (_window.isOpen()) {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color(255, 255, 255));

        // Handle input
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
            if (event.type == sf::Event::KeyPressed) {
                // Check if the pressed key exists in the map
                auto it = keyMap.find(event.key.code);
                if (it != keyMap.end()) {
                    // Print the corresponding string
                    std::cout << "Pressed Key: " << it->second << std::endl;
                } else {
                    // If the key is not found in the map, print as "Unknown"
                    std::cout << "Pressed Key: Unknown" << std::endl;
                }
            }
        }

        _window.display();
    }
}