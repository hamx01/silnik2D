//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_PRIMITIVERENDERER_H
#define SILNIK2D_PRIMITIVERENDERER_H

#include "Point.h"
#include "../Engine.h"

class PrimitiveRenderer {
public:
    PrimitiveRenderer() = default;

    static void drawPoint(const Point &coordinates, sf::Color color = sf::Color::Black);

    static void drawLine(const Point &pointA, const Point &pointB, sf::Color color);

    static void drawSquare(std::vector<Point>& vertices, sf::Color color);

    static void drawTriangle(std::vector<Point>& vertices, sf::Color color);

    static void drawCircle(Point& punkt, float R, sf::Color color);

    static void drawCircleSymetric(Point& punkt, float R, sf::Color color);

    static bool isPointInsideTriangle(const Point& A, const Point& B, const Point& C, const Point& P);

    static void fillCircle(const Point& center, float radius, sf::Color fillColor);

    static void fillCircleBresenham(const Point &center, float radius, sf::Color fillColor);

    static void translateCircle(Point& center, float R, float deltaX, float deltaY);

    static bool isPointInsidePolygon(const std::vector<Point>& vertices, const Point& P);

    static void translatePolygon(std::vector<Point>& vertices, float deltaX, float deltaY);

    static void fillPolygon(const std::vector<Point>& vertices, sf::Color fillColor);

    static void scalePolygon(std::vector<Point>& vertices, float scaleFactor);

    static void rotatePolygon(std::vector<Point>& vertices, float angle, float deltaTime);
};

#endif //SILNIK2D_PRIMITIVERENDERER_H
