#ifndef SILNIK2D_BITMAP_H
#define SILNIK2D_BITMAP_H


#include <SFML/Graphics.hpp>
#include <iostream>
//! @class Bitmap
//! @brief Klasa reprezentująca bitmapę i umożliwiająca jej manipulację i wyświetlanie w środowisku SFML.
class Bitmap {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    //! @brief - Konstruktor klasy Bitmap.
//! @param filePath - Ścieżka do pliku obrazu używanego jako tekstura.
//! @param posX - Początkowa pozycja X bitmapy na scenie.
//! @param posY - Początkowa pozycja Y bitmapy na scenie.
    explicit Bitmap(const std::string& filePath, float posX, float posY);
//! @brief - Ustawia pozycję bitmapy.
//! @param x - Nowa pozycja X bitmapy.
//! @param y - Nowa pozycja Y bitmapy.
    void setPosition(float x, float y);
//! @brief - Przesuwa bitmapę w lewo o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia w lewo.
    void moveLeft(float pixels);
//! @brief - Przesuwa bitmapę w górę o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia w górę.
    void moveUp(float pixels);
//! @brief - Przesuwa bitmapę w dół o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia w dół.
    void moveDown(float pixels);
//! @brief - Przesuwa bitmapę w prawo o zadaną liczbę pikseli.
//! @param pixels - Liczba pikseli do przesunięcia w prawo.
    void moveRight(float pixels);
//! @brief - Rysuje bitmapę na danym celu renderowania.
//! @param target - Cel renderowania, na którym bitmapa będzie wyświetlana.
//! @param states - Stan renderowania używany podczas rysowania.
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
//! @brief - Zwraca sprite'a używanego do wyświetlania bitmapy.
//! @return Referencja do sprite'a.
    sf::Sprite getSprite();
};

#endif //SILNIK2D_BITMAP_H
