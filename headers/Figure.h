#ifndef SILNIK2D_FIGURE_H
#define SILNIK2D_FIGURE_H

#include <vector>
#include "../Engine.h"
#include "Point.h"
//! @class Figure
//! @brief Klasa bazowa dla wszelkich figur geometrycznych, oferująca szereg operacji transformacyjnych i rysowania.
class Figure : public sf::Drawable, public sf::Transformable {
protected:
    bool isFilled{};
    bool withinBounds{};
    std::vector<Point> points;
public:
//! @brief Zwraca wektor punktów składających się na figurę.
//! @return Stała referencja do wektora punktów.
    const std::vector<Point> &getPoints() const;

public:
//! @brief Domyślny konstruktor, inicjalizuje figurę jako niewypełnioną i w obrębie granic.
    Figure() {
        isFilled = false;
        withinBounds = true;
    }
//! @brief Czysto wirtualna funkcja rysująca figurę.
    virtual void draw() = 0;
//! @brief Przesuwa figurę w lewo.
    virtual void moveLeft();
//! @brief Przesuwa figurę w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    virtual void moveLeft(float speed);
//! @brief Przesuwa figurę w prawo.
    virtual void moveRight();
//! @brief Przesuwa figurę w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    virtual void moveRight(float speed);
//! @brief Przesuwa figurę w górę.
    virtual void moveUp();
//! @brief Przesuwa figurę w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    virtual void moveUp(float speed);
//! @brief Przesuwa figurę w dół.
    virtual void moveDown();
//! @brief Przesuwa figurę w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    virtual void moveDown(float speed);
//! @brief Obraca figurę w lewo (przeciwnie do ruchu wskazówek zegara).
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
    virtual void rotateLeft(float deltaTime);
//! @brief Obraca figurę w lewo z określoną prędkością obrotu.
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
//! @param speed - Prędkość obrotu.
    virtual void rotateLeft(float deltaTime, float speed);
//! @brief Obraca figurę w prawo (zgodnie z ruchem wskazówek zegara).
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
    virtual void rotateRight(float deltaTime);
//! @brief Obraca figurę w prawo z określoną prędkością obrotu.
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
//! @param speed - Prędkość obrotu.
    virtual void rotateRight(float deltaTime, float speed);
//! @brief Zwiększa rozmiar figury.
    virtual void increaseSize();
//! @brief Zwiększa rozmiar figury z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zwiększenia rozmiaru.
    virtual void increaseSize(float speed);
//! @brief Zmniejsza rozmiar figury.
    virtual void decreaseSize();
//! @brief Zmniejsza rozmiar figury z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zmniejszenia rozmiaru.
    virtual void decreaseSize(float speed);
//! @brief Ustawia figurę jako wypełnioną.
    virtual void fill();
//! @brief Usuwa wypełnienie figury.
    virtual void unfill();

};


#endif //SILNIK2D_FIGURE_H
