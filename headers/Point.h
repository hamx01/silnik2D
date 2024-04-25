//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_POINT_H
#define SILNIK2D_POINT_H

#include "SFML/Graphics.hpp"
//! @class Point
//! @brief Klasa reprezentująca punkt na scenie graficznej, zarządzająca jego właściwościami i renderowaniem.
class Point : public sf::Drawable, public sf::Transformable {
private:
    float x;
    float y;
    sf::CircleShape shape;
public:
//! @brief - Konstruktor tworzy punkt o określonych współrzędnych.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
    Point(float x, float y);
//! @brief - Konstruktor tworzy punkt o określonych współrzędnych i kolorze.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
//! @param color - Kolor punktu.
    Point(float x, float y, sf::Color color);

//! @brief - Konstruktor tworzy punkt o określonych współrzędnych, kolorze i rozmiarze.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
//! @param color - Kolor punktu.
//! @param size - Rozmiar punktu (promień w pikselach).
    Point(float x, float y, sf::Color color, float size);

//! @brief - Zwraca współrzędne punktu.
//! @return Para zawierająca współrzędne X i Y punktu.
    std::pair<float, float> getCoordinates() const;
//! @brief - Ustawia nowe współrzędne punktu.
//! @param new_x - Nowa współrzędna X punktu.
//! @param new_y - Nowa współrzędna Y punktu.
    void setCoordinates(float new_x, float new_y);
//! @brief - Ustawia kolor punktu.
//! @param color - Nowy kolor punktu.
    void setColor(sf::Color color);
//! @brief - Rysuje punkt na danym celu renderowania, do użytku wewnętrznego w bibliotece SFML.
//! @param target - Cel renderowania.
//! @param states - Stan renderowania używany podczas rysowania.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SILNIK2D_POINT_H
