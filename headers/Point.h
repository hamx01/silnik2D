//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_POINT_H
#define SILNIK2D_POINT_H

#include "SFML/Graphics.hpp"

class Point : public sf::Drawable, public sf::Transformable {
private:
    float x;
    float y;
    sf::CircleShape shape;
public:
    Point(float x, float y);

    Point(float x, float y, sf::Color color);

    std::pair<float, float> getCoordinates() const;

    void setCoordinates(float new_x, float new_y);

    void setColor(sf::Color color);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SILNIK2D_POINT_H
