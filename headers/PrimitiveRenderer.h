//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_PRIMITIVERENDERER_H
#define SILNIK2D_PRIMITIVERENDERER_H

#include "Point.h"
#include "../Engine.h"
//! @class PrimitiveRenderer
//! @brief Prosta klasa renderująca do rysowania podstawowych kształtów i zarządzania transformacjami.
class PrimitiveRenderer {
public:
//! @brief - Domyślny konstruktor.
    PrimitiveRenderer() = default;
//! @brief - Rysuje punkt o danych współrzędnych.
//! @param coordinates - Współrzędne punktu do narysowania.
//! @param color - Kolor punktu (domyślnie czarny).
    static void drawPoint(const Point &coordinates, sf::Color color = sf::Color::Black);
//! @brief - Rysuje linię między dwoma punktami.
//! @param pointA - Punkt początkowy linii.
//! @param pointB - Punkt końcowy linii.
//! @param color - Kolor linii.
    static void drawLine(const Point &pointA, const Point &pointB, sf::Color color);
//! @brief - Rysuje kwadrat zdefiniowany przez wektor wierzchołków.
//! @param vertices - Wektor punktów będących wierzchołkami kwadratu.
//! @param color - Kolor kwadratu.
    static void drawSquare(std::vector<Point>& vertices, sf::Color color);
//! @brief - Rysuje trójkąt zdefiniowany przez wektor wierzchołków.
//! @param vertices - Wektor punktów będących wierzchołkami trójkąta.
//! @param color - Kolor trójkąta.
    static void drawTriangle(std::vector<Point>& vertices, sf::Color color);
//! @brief - Rysuje koło o określonym promieniu i kolorze.
//! @param punkt - Punkt będący środkiem koła.
//! @param R - Promień koła.
//! @param color - Kolor koła.
    static void drawCircle(Point& punkt, float R, sf::Color color);
//! @brief - Rysuje koło z wykorzystaniem symetrii względem osi i punktu środkowego.
//! @param punkt - Punkt będący środkiem koła.
//! @param R - Promień koła.
//! @param color - Kolor koła.
    static void drawCircleSymetric(Point& punkt, float R, sf::Color color);
//! @brief - Sprawdza, czy punkt znajduje się wewnątrz trójkąta zdefiniowanego przez trzy punkty.
//! @param A - Pierwszy wierzchołek trójkąta.
//! @param B - Drugi wierzchołek trójkąta.
//! @param C - Trzeci wierzchołek trójkąta.
//! @param P - Punkt do sprawdzenia.
//! @return true - Jeżeli punkt znajduje się wewnątrz trójkąta, false - w przeciwnym razie.
    static bool isPointInsideTriangle(const Point& A, const Point& B, const Point& C, const Point& P);
//! @brief - Wypełnia koło określonym kolorem.
//! @param center - Środek koła.
//! @param radius - Promień koła.
//! @param fillColor - Kolor wypełnienia.
    static void fillCircle(const Point& center, float radius, sf::Color fillColor);
//! @brief - Wypełnia koło przy użyciu algorytmu Bresenhama.
//! @param center - Środek koła.
//! @param radius - Promień koła.
//! @param fillColor - Kolor wypełnienia.
    static void fillCircleBresenham(const Point &center, float radius, sf::Color fillColor);
//! @brief - Przesuwa koło o określone przesunięcie.
//! @param center - Środek koła.
//! @param R - Promień koła.
//! @param deltaX - Przesunięcie w poziomie.
//! @param deltaY - Przesunięcie w pionie.
    static void translateCircle(Point& center, float R, float deltaX, float deltaY);
//! @brief - Sprawdza, czy punkt znajduje się wewnątrz wielokąta zdefiniowanego przez wektor wierzchołków.
//! @param vertices - Wektor punktów będących wierzchołkami wielokąta.
//! @param P - Punkt do sprawdzenia.
//! @return true - Jeżeli punkt znajduje się wewnątrz wielokąta, false - w przeciwnym razie.
    static bool isPointInsidePolygon(const std::vector<Point>& vertices, const Point& P);
//! @brief - Przesuwa wielokąt o określone przesunięcie.
//! @param vertices - Wektor punktów będących wierzchołkami wielokąta.
//! @param deltaX - Przesunięcie w poziomie.
//! @param deltaY - Przesunięcie w pionie.
    static void translatePolygon(std::vector<Point>& vertices, float deltaX, float deltaY);
//! @brief - Wypełnia wielokąt określonym kolorem.
//! @param vertices - Wektor punktów będących wierzchołkami wielokąta.
//! @param fillColor - Kolor wypełnienia.
    static void fillPolygon(const std::vector<Point>& vertices, sf::Color fillColor);
//! @brief - Skaluje wielokąt o określony współczynnik.
//! @param vertices - Wektor punktów będących wierzchołkami wielokąta.
//! @param scaleFactor - Współczynnik skalowania.
static void scalePolygon(std::vector<Point>& vertices, float scaleFactor);
//! @brief - Obraca wielokąt o określony kąt w czasie.
//! @param vertices - Wektor punktów będących wierzchołkami wielokąta.
//! @param angle - Kąt obrotu (w stopniach).
//! @param deltaTime - Czas, w którym ma nastąpić obrót.
    static void rotatePolygon(std::vector<Point>& vertices, float angle, float deltaTime);
};

#endif //SILNIK2D_PRIMITIVERENDERER_H
