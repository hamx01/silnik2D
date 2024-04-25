#include <utility>

#include "../headers/Circle.h"
#include "../headers/PrimitiveRenderer.h"
//! @brief - Konstruktor klasy Circle.
//! @param point - Punkt centralny okręgu.
//! @param Rr - Promień okręgu.
Circle::Circle(Point point, float Rr) {
    this->R = Rr;
    this->point = std::move(point);
}
//! @brief - Rysuje okręg na ekranie.
void Circle::draw() {
    PrimitiveRenderer::drawCircle(point, R, sf::Color::White);
}
//! @brief - Rysuje okręg na ekranie z określonym kolorem.
//! @param color - Kolor okręgu.
void Circle::draw(sf::Color color) {
    PrimitiveRenderer::drawCircle(point, R, color);
    if(isFilled) {
        PrimitiveRenderer::fillCircle(point, R, color);
    }
}
//! @brief - Przesuwa okręg w lewo.
void Circle::moveLeft() {
    float speed = -10;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(point.getCoordinates().first + speed, point.getCoordinates().second);
}
//! @brief - Przesuwa okręg w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
void Circle::moveLeft(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first - speed;
    float new_y = point.getCoordinates().second;
    if (new_x - R < 0) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, -speed, 0);
    point.setCoordinates(new_x, new_y);
}
//! @brief - Przesuwa okręg w prawo.
void Circle::moveRight() {
    float speed = 10;
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(point.getCoordinates().first + speed, point.getCoordinates().second);
}
//! @brief - Przesuwa okręg w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
void Circle::moveRight(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first + speed;
    float new_y = point.getCoordinates().second;
    if (new_x + R > Engine::getWindowSize().first) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, speed, 0);
    point.setCoordinates(new_x, new_y);
}
//! @brief - Przesuwa okręg w górę.
void Circle::moveUp() {
    float speed = -10;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(point.getCoordinates().first, point.getCoordinates().second + speed);
}
//! @brief - Przesuwa okręg w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
void Circle::moveUp(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first;
    float new_y = point.getCoordinates().second - speed;
    if (new_y - R < 0) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, 0, -speed);
    point.setCoordinates(new_x, new_y);
}
//! @brief - Przesuwa okręg w dół.
void Circle::moveDown() {
    float speed = 10;
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(point.getCoordinates().first, point.getCoordinates().second + speed);
}
//! @brief - Przesuwa okręg w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
void Circle::moveDown(float speed) {
    if(speed < 0) speed *= -1;
    float new_x = point.getCoordinates().first;
    float new_y = point.getCoordinates().second + speed;
    if (new_y + R > Engine::getWindowSize().second) {
        return;
    }
    PrimitiveRenderer::translateCircle(point, R, 0, speed);
    point.setCoordinates(new_x, new_y);
}
//! @brief - Zwiększa rozmiar okręgu.
void Circle::increaseSize() {
    scaleSize(1.1f);
}
//! @brief - Zwiększa rozmiar okręgu z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zwiększenia rozmiaru.
void Circle::increaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    scaleSize(1.1f + speed / 100.0f);
}
//! @brief - Zmniejsza rozmiar okręgu.
void Circle::decreaseSize() {
    scaleSize(0.9f);
}
//! @brief - Zmniejsza rozmiar okręgu z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zmniejszenia rozmiaru.
void Circle::decreaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    scaleSize(0.9f - speed / 100.0f);
}
//! @brief - Skaluje rozmiar okręgu według określonego współczynnika.
//! @param scaleFactor - Współczynnik skalowania.
void Circle::scaleSize(float scaleFactor) {
    float newRadius = R * scaleFactor;
    float windowWidth = Engine::getWindowSize().first;
    float windowHeight = Engine::getWindowSize().second;

    if (newRadius > 0 &&
        point.getCoordinates().first + newRadius < windowWidth &&
        point.getCoordinates().second + newRadius < windowHeight &&
        point.getCoordinates().first - newRadius > 0 &&
        point.getCoordinates().second - newRadius > 0) {
        R = newRadius;
    } else {

    }
}
//! @brief - Zwraca punkt centralny okręgu.
//! @return Stała referencja do punktu centralnego.
const Point &Circle::getPoint() const {
    return point;
}
//! @brief - Zwraca promień okręgu.
//! @return Promień okręgu.
float Circle::getR() const {
    return R;
}
//! @brief - Ustawia nowe współrzędne punktu centralnego okręgu.
//! @param x - Nowa współrzędna X.
//! @param y - Nowa współrzędna Y.
void Circle::setCoordinates(float x, float y) {
    point.setCoordinates(x, y);
}
//! @brief - Metoda do rysowania okręgu na danym celu renderowania, do użytku wewnętrznego w bibliotece SFML.
//! @param target - Cel renderowania.
//! @param states - Stan renderowania.
void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
//! @brief - Generyczna metoda przesunięcia okręgu.
//! @param x - Przesunięcie w osi X.
//! @param y - Przesunięcie w osi Y.
void Circle::move(float x, float y) {
    PrimitiveRenderer::translateCircle(point, R, x, y);
}



