#include "../headers/Bitmap.h"
//! @brief - Przesuwa bitmapę w lewo o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia.
void Bitmap::moveLeft(float pixels) {
    sprite.move(-pixels, 0);
}
//! @brief - Przesuwa bitmapę w górę o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia.
void Bitmap::moveUp(float pixels) {
    sprite.move(0, -pixels);
}
//! @brief - Przesuwa bitmapę w dół o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia.
void Bitmap::moveDown(float pixels) {
    sprite.move(0, pixels);
}
//! @brief - Przesuwa bitmapę w prawo o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia.
void Bitmap::moveRight(float pixels) {
    sprite.move(pixels, 0);
}
//! @brief - Zwraca sprite'a bitmapy.
//! @return Kopię sprite'a bitmapy.
sf::Sprite Bitmap::getSprite() {
    return sprite;
}
//! @brief - Rysuje bitmapę na danym celu renderowania.
//! @param target - Cel renderowania, na którym będzie narysowana bitmapa.
//! @param states - Stan renderowania używany podczas rysowania.
void Bitmap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

//! @brief - Ustawia pozycję bitmapy.
//! @param x - Nowa pozycja X bitmapy.
//! @param y - Nowa pozycja Y bitmapy.
void Bitmap::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
//! @brief - Konstruktor klasy Bitmap.
//! @param filePath - Ścieżka do pliku graficznego.
//! @param posX - Początkowa pozycja X obrazu.
//! @param posY - Początkowa pozycja Y obrazu.
//! W przypadku błędu wczytania pliku wyświetla komunikat o błędzie.
Bitmap::Bitmap(const std::string &filePath, float posX = 0, float posY = 0) {
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Failed to load bitmap image!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}
