#include "../headers/Bitmap.h"

void Bitmap::moveLeft(float pixels) {
    sprite.move(-pixels, 0);
}

void Bitmap::moveUp(float pixels) {
    sprite.move(0, -pixels);
}

void Bitmap::moveDown(float pixels) {
    sprite.move(0, pixels);
}

void Bitmap::moveRight(float pixels) {
    sprite.move(pixels, 0);
}

sf::Sprite Bitmap::getSprite() {
    return sprite;
}

void Bitmap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Bitmap::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

Bitmap::Bitmap(const std::string &filePath, float posX = 0, float posY = 0) {
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Failed to load bitmap image!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}
