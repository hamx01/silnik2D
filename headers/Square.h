#ifndef SILNIK2D_SQUARE_H
#define SILNIK2D_SQUARE_H

#include <utility>

#include "Figure.h"
#include "../Engine.h"

class Square : public Figure {
public:
    Square() = default;

    Square(Point p1, Point p2, Point p3, Point p4) {
        points = {std::move(p1), std::move(p2), std::move(p3), std::move(p4)};
    }

    void draw() override;

    void draw(sf::Color color);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

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
