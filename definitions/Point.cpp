//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../headers/Point.h"
#include "../Engine.h"
//! @brief - Konstruktor tworzy punkt o określonych współrzędnych.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
Point::Point(float x, float y) {
    shape.setPosition(x, y);
    this->x = x;
    this->y = y;
    this->shape = sf::CircleShape(5.0f);
}
//! @brief - Konstruktor tworzy punkt o określonych współrzędnych i kolorze.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
//! @param color - Kolor punktu.
Point::Point(float x, float y, sf::Color color) {
    shape.setPosition(x, y);
    shape.setRadius(5.0f);
    shape.setFillColor(color);
    this->x = x;
    this->y = y;
}
//! @brief - Konstruktor tworzy punkt o określonych współrzędnych, kolorze i rozmiarze.
//! @param x - Współrzędna X punktu.
//! @param y - Współrzędna Y punktu.
//! @param color - Kolor punktu.
//! @param size - Rozmiar punktu (promień w pikselach).
Point::Point(float x, float y, sf::Color color, float size) {
    shape.setPosition(x, y);
    shape.setRadius(size);
    shape.setFillColor(color);
    this->x = x;
    this->y = y;
}
//! @brief - Zwraca współrzędne punktu.
//! @return Para zawierająca współrzędne X i Y punktu.
std::pair<float, float> Point::getCoordinates() const {
    return std::make_pair(x, y);
}
//! @brief - Ustawia nowe współrzędne punktu.
//! @param new_x - Nowa współrzędna X punktu.
//! @param new_y - Nowa współrzędna Y punktu.
void Point::setCoordinates(float new_x, float new_y) {
    this->x = new_x;
    this->y = new_y;
    shape.setPosition(new_x, new_y);
}
//! @brief - Ustawia kolor punktu.
//! @param color - Nowy kolor punktu.
void Point::setColor(sf::Color color) {
    shape.setFillColor(color);
}
//! @brief - Rysuje punkt na określonym celu renderowania.
//! @param target - Cel renderowania, do którego punkt ma być narysowany.
//! @param states - Stan renderowania używany podczas rysowania.
void Point::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}