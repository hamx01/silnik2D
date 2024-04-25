#ifndef SILNIK2D_SQUARE_H
#define SILNIK2D_SQUARE_H

#include <utility>

#include "Figure.h"
#include "../Engine.h"

//! @class Square
//! @brief Rozszerza klasę Figure, implementując funkcjonalności specyficzne dla kwadratów.
class Square : public Figure {
public:
    //! @brief Domyślny konstruktor, tworzy pusty kwadrat.
    Square() = default;
    //! @brief Konstruktor tworzący kwadrat z czterech punktów.
    //! @param p1 Pierwszy wierzchołek kwadratu.
    //! @param p2 Drugi wierzchołek kwadratu.
    //! @param p3 Trzeci wierzchołek kwadratu.
    //! @param p4 Czwarty wierzchołek kwadratu.
    Square(Point p1, Point p2, Point p3, Point p4) {
        points = {std::move(p1), std::move(p2), std::move(p3), std::move(p4)};
    }
//! @brief Rysuje kwadrat, korzystając z domyślnej metody zdefiniowanej przez klasę Figure.
    void draw() override;
    //! @brief Rysuje kwadrat w określonym kolorze.
    //! @param color Kolor, jakim ma być narysowany kwadrat.
    void draw(sf::Color color);
    //! @brief Rysuje kwadrat na docelowym obiekcie renderującym z użyciem określonych stanów renderowania.
    //! @param target Cel renderowania, na którym ma być narysowany kwadrat.
    //! @param states Aktualne stany renderowania.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
//! @brief Oblicza i zwraca prostokąt ograniczający kwadrat.
//! @return Prostokąt ograniczający jako sf::FloatRect.
    sf::FloatRect getBounds() const {
        // Obliczanie obwiedni prostokątnej
        float left = std::min(points[0].getCoordinates().first, points[1].getCoordinates().first);
        float top = std::min(points[0].getCoordinates().second, points[2].getCoordinates().second);
        float width = std::abs(points[1].getCoordinates().first - points[0].getCoordinates().first);
        float height = std::abs(points[2].getCoordinates().second - points[0].getCoordinates().second);

        return sf::FloatRect(left, top, width, height);
    }
};

#endif //SILNIK2D_SQUARE_H
