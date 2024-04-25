//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_MOUSE_H
#define SILNIK2D_MOUSE_H

#include "SFML/Graphics.hpp"

class Mouse {
public:
//! @brief - Pobiera globalną pozycję kursora myszy.
//! @return Pozycja kursora jako sf::Vector2i, reprezentująca współrzędne x i y.
    static sf::Vector2i getPosition();
//! @brief - Pobiera pozycję kursora myszy względem określonego okna.
//! @param relativeTo - Referencja do okna, względem którego pozycja jest mierzona.
//! @return Pozycja kursora jako sf::Vector2i, reprezentująca współrzędne x i y względem podanego okna.
    static sf::Vector2i getPosition(const sf::RenderWindow &relativeTo);
//! @brief - Sprawdza, czy dany przycisk myszy jest wciśnięty.
//! @param button - Przycisk myszy do sprawdzenia (np. sf::Mouse::Left, sf::Mouse::Right).
//! @return true - Jeżeli przycisk jest wciśnięty.
//! @return false - Jeżeli przycisk nie jest wciśnięty.
    static bool isButtonPressed(sf::Mouse::Button button);
};

#endif //SILNIK2D_MOUSE_H
