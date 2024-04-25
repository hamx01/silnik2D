#include "../headers/Figure.h"
#include "../headers/PrimitiveRenderer.h"
//! @brief - Przesuwa figurę w lewo o stałą wartość.
void Figure::moveLeft() {
    PrimitiveRenderer::translatePolygon(points, -10.0f, 0);
}
//! @brief - Przesuwa figurę w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia (negatywna dla przesunięcia w lewo, ale przetwarzana na negatywną jeśli podana jako dodatnia).
void Figure::moveLeft(float speed) {
    if(speed > 0) speed *= -1;
    if(speed < -100) speed = -100;
    PrimitiveRenderer::translatePolygon(points, speed, 0);
}
//! @brief - Przesuwa figurę w prawo o stałą wartość.
void Figure::moveRight() {
    PrimitiveRenderer::translatePolygon(points, 10.0f, 0);
}
//! @brief - Przesuwa figurę w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia (dodatnia).
void Figure::moveRight(float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::translatePolygon(points, speed, 0);
}
//! @brief - Przesuwa figurę w dół o stałą wartość.
void Figure::moveDown() {
    PrimitiveRenderer::translatePolygon(points, 0, 10.0f);
}
//! @brief - Przesuwa figurę w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia (dodatnia).
void Figure::moveDown(float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::translatePolygon(points, 0, speed);
}
//! @brief - Przesuwa figurę w górę o stałą wartość.
void Figure::moveUp() {
    PrimitiveRenderer::translatePolygon(points, 0, -10.0f);
}
//! @brief - Przesuwa figurę w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia (negatywna dla przesunięcia w górę, ale przetwarzana na negatywną jeśli podana jako dodatnia).
void Figure::moveUp(float speed) {
    if(speed > 0) speed *= -1;
    if(speed < 100) speed = -100;
    PrimitiveRenderer::translatePolygon(points, 0, speed);
}
//! @brief - Obraca figurę w lewo (przeciwnie do ruchu wskazówek zegara).
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
void Figure::rotateLeft(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, -15.0f, deltaTime);
}
//! @brief - Obraca figurę w lewo z określoną prędkością.
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
//! @param speed - Prędkość obrotu (negatywna).
void Figure::rotateLeft(float deltaTime, float speed) {
    if(speed > 0) speed *= -1;
    if(speed < 100) speed = -100;
    PrimitiveRenderer::rotatePolygon(points, speed, deltaTime);
}
//! @brief - Obraca figurę w prawo (zgodnie z ruchem wskazówek zegara).
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
void Figure::rotateRight(float deltaTime) {
    PrimitiveRenderer::rotatePolygon(points, 15.0f, deltaTime);
}
//! @brief - Obraca figurę w prawo z określoną prędkością.
//! @param deltaTime - Czas, który wpływa na stopień obrotu.
//! @param speed - Prędkość obrotu (dodatnia).
void Figure::rotateRight(float deltaTime, float speed) {
    if(speed < 0) speed *= -1;
    if(speed > 100) speed = 100;
    PrimitiveRenderer::rotatePolygon(points, speed, deltaTime);
}
//! @brief - Zwiększa rozmiar figury.
void Figure::increaseSize() {
    PrimitiveRenderer::scalePolygon(points, 1.1f);
}
//! @brief - Zwiększa rozmiar figury z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zwiększenia rozmiaru (od 0 do 100).
void Figure::increaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    PrimitiveRenderer::scalePolygon(points, 1.1f + speed / 10.0f);
}
//! @brief - Zmniejsza rozmiar figury.
void Figure::decreaseSize() {
    PrimitiveRenderer::scalePolygon(points, 0.9f);
}
//! @brief - Zmniejsza rozmiar figury z określoną "prędkością".
//! @param speed - Wartość skalująca tempo zmniejszenia rozmiaru (od 0 do 100).
void Figure::decreaseSize(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    speed /= 100.0f;
    PrimitiveRenderer::scalePolygon(points, 0.9f - speed / 10.0f);
}
//! @brief - Wypełnia figurę kolorem (ustawia flagę wypełnienia).
void Figure::fill() {
    isFilled = true;
}
//! @brief - Usuwa wypełnienie figury (usuwa flagę wypełnienia).
void Figure::unfill() {
    isFilled = false;
}
//! @brief - Zwraca wektor punktów figury.
//! @return Stała referencja do wektora punktów.
const std::vector<Point> &Figure::getPoints() const {
    return points;
}
