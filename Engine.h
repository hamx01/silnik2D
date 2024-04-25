//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/AnimatedCharacter.h"
//! @class Engine
//! @brief Główna klasa silnika, zarządzająca renderowaniem i logiką gry.
class Engine {
private:
    static sf::RenderWindow _window;//! - Główne okno aplikacji.
    static sf::RenderWindow _game;//! - Okno gry (dodatkowe).
    static sf::Clock _clock;//! - Zegar używany do śledzenia czasu między klatkami.
    static bool isWindow1Active;//! - Flaga określająca, które okno jest obecnie aktywne.
public:
//! @brief Uruchamia silnik gry.
//! Inicjalizuje główne okno gry oraz przygotowuje wszystkie niezbędne zasoby.
    static void start();
//! @brief Główna pętla silnika.
//! Obsługuje zdarzenia, wykonuje aktualizacje logiki gry i renderuje grafikę.
    static void engineLoop();
//! @brief Zwraca wymiary głównego okna gry.
//! @return Para liczb zmiennoprzecinkowych określająca szerokość i wysokość okna.
    static std::pair<float, float> getWindowSize();
//! @brief Zwraca referencję do głównego okna renderowania.
//! @return Referencja do głównego okna sf::RenderWindow.
    static sf::RenderWindow& getWindow();
//! @brief Zwraca referencję do okna gry.
//! @return Referencja do okna gry sf::RenderWindow.
    static sf::RenderWindow& getGameWindow() {
        return _game;
    }
//! @brief Zwraca referencję do aktywnego okna.
//! W zależności od tego, które okno jest aktualnie aktywne, zwraca odpowiednie okno.
//! @return Referencja do aktywnego okna sf::RenderWindow.
    static sf::RenderWindow& getActiveWindow() {
        if (isWindow1Active) {
            return _window;
        } else {
            return _game;
        }
    }
//! @brief Przełącza aktywne okno między głównym a dodatkowym.
//! Zmienia stan flagi isWindow1Active na przeciwny.
    static void switchActiveWindow() {
        isWindow1Active = !isWindow1Active;
    }
//! @brief Zamyka aktywne okno.
//! Jeśli aktywne okno to okno gry, zostanie ono zamknięte.
    static void closeActiveWindow() {
        if (!isWindow1Active) {
            _game.close();
            isWindow1Active = true;
        }
    }
};

#endif //SILNIK2D_ENGINE_H
