//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../headers/Mouse.h"
//! @brief - Pobiera globalną pozycję kursora myszy.
//! @return Pozycja kursora jako sf::Vector2i, reprezentująca współrzędne x i y.
sf::Vector2i Mouse::getPosition() {
    return sf::Mouse::getPosition();
}
//! @brief - Pobiera pozycję kursora myszy względem określonego okna.
//! @param relativeTo - Referencja do okna, względem którego pozycja jest mierzona.
//! @return Pozycja kursora jako sf::Vector2i, reprezentująca współrzędne x i y względem podanego okna.
sf::Vector2i Mouse::getPosition(const sf::RenderWindow& relativeTo) {
    return sf::Mouse::getPosition(relativeTo);
}
//! @brief - Sprawdza, czy dany przycisk myszy jest wciśnięty.
//! @param button - Przycisk myszy do sprawdzenia (np. sf::Mouse::Left, sf::Mouse::Right).
//! @return true - Jeżeli przycisk jest wciśnięty.
//! @return false - Jeżeli przycisk nie jest wciśnięty.
bool Mouse::isButtonPressed(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}