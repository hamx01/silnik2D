//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../Engine.h"
#include <cmath>

//! Metoda rysująca punkt na ekranie
void Engine::PrimitiveRenderer::drawPoint(const Point &coordinates, sf::Color color) {
    float x = coordinates.getCoordinates().first;
    float y = coordinates.getCoordinates().second;
    sf::Vertex point(sf::Vector2f(x, y), color);
    Engine::_window.draw(&point, 2, sf::Points);
}

//!
//! @param pointA - punkt początkowy linii
//! @param pointB - punkt końcowy linii
//! @param color - kolor linii
void Engine::PrimitiveRenderer::drawLine(const Point& pointA, const Point& pointB, sf::Color color) {
    int dx, dy, kx, ky, e, i;

    int x1 = pointA.getCoordinates().first;
    int x2 = pointB.getCoordinates().first;
    int y1 = pointA.getCoordinates().second;
    int y2 = pointB.getCoordinates().second;

    if (x1 <= x2) kx = 1; else kx = -1;
    if (y1 <= y2) ky = 1; else ky = -1;

    dx = x2 - x1;
    if (dx < 0) dx = -dx;
    dy = y2 - y1;
    if (dy < 0) dy = -dy;

    drawPoint(Point(x1, y1), color);

    if (dx >= dy) {
        e = dx / 2;
        for(i = 0; i < dx; i++) {
            x1 += kx;
            e -= dy;
            if(e < 0) {
                y1 += ky;
                e += dx;
            }
            drawPoint(Point(x1, y1), color);
        }
    }
    else
    {
        e = dy / 2;
        for(i = 0; i < dy; i++) {
            y1 += ky;
            e -= dx;
            if(e < 0) {
                x1 += kx;
                e += dy;
            }
            drawPoint(Point(x1, y1), color);
        }
    }
}

void Engine::PrimitiveRenderer::drawTriangle(const Point& pointA, const Point& pointB, const Point& pointC, sf::Color color) {
    drawLine(pointA, pointB, color);
    drawLine(pointB, pointC, color);
    drawLine(pointC, pointA, color);
}
void Engine::PrimitiveRenderer::drawSquare(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD, sf::Color color) {
    drawLine(pointA, pointB, color);
    drawLine(pointB, pointC, color);
    drawLine(pointC, pointD, color);
    drawLine(pointD, pointA, color);
}

 void Engine::PrimitiveRenderer::drawCircle(Engine::Point& punkt, float R, sf::Color color) {
    float step = 1.0f / R;
    sf::VertexArray points(sf::Points);
    int xc = punkt.getCoordinates().first;
    int yc = punkt.getCoordinates().second;

    for (float a = 0; a < 2 * M_PI; a += step) {
        int x = static_cast<int>(xc + R * std::cos(a) + 0.5f);
        int y = static_cast<int>(yc + R * std::sin(a) + 0.5f);

        points.append(sf::Vertex(sf::Vector2f(x, y), color));
    }

    _window.draw(points);
}

void Engine::PrimitiveRenderer::drawCircleSymetric(Engine::Point& punkt, int R, sf::Color color) {
    int xc = punkt.getCoordinates().first;
    int yc = punkt.getCoordinates().second;
    sf::VertexArray points(sf::Points);

    float step = 1.0f / R;
    for (float a = 0; a <= M_PI / 4; a += step) {
        int x = static_cast<int>(xc + R * std::cos(a) + 0.5f); // Zaokrąglone X
        int y = static_cast<int>(yc + R * std::sin(a) + 0.5f); // Zaokrąglone Y

        points.append(sf::Vertex(sf::Vector2f(x, y), color));

        if (x != xc) {
            points.append(sf::Vertex(sf::Vector2f(xc - (x - xc), y), color));
        }
        if (y != yc) {
            points.append(sf::Vertex(sf::Vector2f(x, yc - (y - yc)), color));
        }
        if (x != xc && y != yc) {
            points.append(sf::Vertex(sf::Vector2f(xc - (x - xc), yc - (y - yc)), color));
        }
    }

    int numPoints = points.getVertexCount();
    for (int i = 0; i < numPoints; ++i) {
        sf::Vertex vertex = points[i];
        if (vertex.position.x != xc) {
            vertex.position.x = xc - (vertex.position.x - xc);
            points.append(vertex);
        }
        if (vertex.position.y != yc) {
            vertex.position.y = yc - (vertex.position.y - yc);
            points.append(vertex);
        }
        if (vertex.position.x != xc && vertex.position.y != yc) {
            sf::Vector2f mirroredPosition = sf::Vector2f(xc - (vertex.position.x - xc), yc - (vertex.position.y - yc));
            points.append(sf::Vertex(mirroredPosition, color));
        }
    }
}

bool Engine::PrimitiveRenderer::isPointInsideTriangle(const Engine::Point& A, const Engine::Point& B, const Engine::Point& C, const Engine::Point& P) {
    double areaABC = 0.5 * ((B.getCoordinates().first - A.getCoordinates().first) * (C.getCoordinates().second - A.getCoordinates().second) -
                            (C.getCoordinates().first - A.getCoordinates().first) * (B.getCoordinates().second - A.getCoordinates().second));
    double alpha = 0.5 * ((B.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second) -
                          (C.getCoordinates().first - P.getCoordinates().first) * (B.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double beta = 0.5 * ((C.getCoordinates().first - P.getCoordinates().first) * (A.getCoordinates().second - P.getCoordinates().second) -
                         (A.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double gamma = 1.0 - alpha - beta;

    return alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0;
}

bool Engine::PrimitiveRenderer::isPointInsidePolygon(const std::vector<Point>& vertices, const Point& P) {
    int n = int(vertices.size());
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        double xi = vertices[i].getCoordinates().first, yi = vertices[i].getCoordinates().second;
        double xj = vertices[j].getCoordinates().first, yj = vertices[j].getCoordinates().second;

        if (((yi > P.getCoordinates().second) != (yj > P.getCoordinates().second)) &&
            (P.getCoordinates().first < (xj - xi) * (P.getCoordinates().second - yi) / (yj - yi) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}


void Engine::PrimitiveRenderer::fillCircle(const Point& center, float radius, sf::Color fillColor) {
    int xc = center.getCoordinates().first;
    int yc = center.getCoordinates().second;

    // Iterujemy przez każdy punkt wewnątrz koła i rysujemy go
    for (int x = xc - radius; x <= xc + radius; ++x) {
        for (int y = yc - radius; y <= yc + radius; ++y) {
            // Sprawdzamy czy punkt (x, y) znajduje się wewnątrz koła
            if (std::pow(x - xc, 2) + std::pow(y - yc, 2) <= std::pow(radius, 2)) {
                drawPoint(Point(x, y), fillColor);
            }
        }
    }
}


