#ifndef SILNIK2D_BITMAP_H
#define SILNIK2D_BITMAP_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Bitmap {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    explicit Bitmap(const std::string& filePath, float posX, float posY);

    void setPosition(float x, float y);

    void moveLeft(float pixels);

    void moveUp(float pixels);

    void moveDown(float pixels);

    void moveRight(float pixels);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite getSprite();
};

#endif //SILNIK2D_BITMAP_H
