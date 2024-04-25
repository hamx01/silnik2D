#ifndef SILNIK2D_CIRCLE_H
#define SILNIK2D_CIRCLE_H

#include "Figure.h"
#include "Point.h"
//! @class Circle
//! @brief Klasa reprezentująca okrąg i umożliwiająca jego manipulację oraz rysowanie.
//! Klasa Circle dziedziczy po Figure i reprezentuje okrąg w systemie.

class Circle : public Figure {
private:
    float R{};
public:
//! @brief Zwraca aktualny promień okręgu.
//! @return Promień okręgu.
    float getR() const;

private:
    Point point = Point(0, 0);
public:
//! @brief Zwraca punkt centralny okręgu.
//! @return Stała referencja do punktu centralnego.
    const Point &getPoint() const;

public:
//! @brief Domyślny konstruktor, tworzy okrąg w punkcie (0,0) z promieniem 0.
    Circle() = default;
//! @brief Konstruktor inicjalizujący okrąg z danym punktem centralnym i promieniem.
//! @param point - Punkt centralny okręgu.
//! @param R - Promień okręgu.
    Circle(Point point, float R);
//! @brief Rysuje okrąg przy użyciu domyślnego białego koloru.
    void draw() override;
//! @brief Rysuje okrąg w określonym kolorze.
//! @param color - Kolor, w jakim ma być narysowany okrąg.
    void draw(sf::Color color);
//! @brief Generyczna metoda przesunięcia okręgu.
//! @param x - Przesunięcie w osi X.
//! @param y - Przesunięcie w osi Y.
    void move(float x, float y) override;
//! @brief Przesuwa okrąg w lewo.
    void moveLeft() override;
//! @brief Przesuwa okrąg w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveLeft(float speed) override;
//! @brief Przesuwa okrąg w prawo.
    void moveRight() override;
//! @brief Przesuwa okrąg w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveRight(float speed) override;
//! @brief Przesuwa okrąg w górę.
    void moveUp() override;
//! @brief Przesuwa okrąg w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveUp(float speed) override;
//! @brief Przesuwa okrąg w dół.
    void moveDown() override;
//! @brief Przesuwa okrąg w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveDown(float speed) override;
//! @brief Zwiększa rozmiar okręgu.
    void increaseSize() override;
//! @brief Zwiększa rozmiar okręgu z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zwiększenia rozmiaru.
    void increaseSize(float speed) override;
//! @brief Zmniejsza rozmiar okręgu.
    void decreaseSize() override;
//! @brief Zmniejsza rozmiar okręgu z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zmniejszenia rozmiaru.
    void decreaseSize(float speed) override;
//! @brief Skaluje rozmiar okręgu według określonego współczynnika.
//! @param scaleFactor - Współczynnik skalowania.
    void scaleSize(float scaleFactor);
//! @brief Ustawia nowe współrzędne punktu centralnego okręgu.
//! @param x - Nowa współrzędna X.
//! @param y - Nowa współrzędna Y.
    void setCoordinates(float x, float y);
//! @brief Rysuje okrąg na danym celu renderowania, do użytku wewnętrznego w bibliotece SFML.
//! @param target - Cel renderowania.
//! @param states - Stan renderowania używany podczas rysowania.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SILNIK2D_CIRCLE_H
