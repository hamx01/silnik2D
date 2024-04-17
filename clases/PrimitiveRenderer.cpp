//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../Engine.h"
#include <cmath>

//! Metoda rysująca punkt na ekranie
void Engine::PrimitiveRenderer::drawPoint(const Coordinates &coordinates, sf::Color color) {
    float x = coordinates.getCoordinates().first;
    float y = coordinates.getCoordinates().second;
    sf::Vertex point(sf::Vector2f(x, y), color);
    Engine::_window.draw(&point, 2, sf::Points);
}

//void Engine::PrimitiveRenderer::drawLine(const Coordinates& pointA, const Coordinates& pointB, sf::Color color) {
//    sf::Vertex line[] = {
//            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second), color),
//            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second), color)
//    };
//
//    Engine::_window.draw(line, 2, sf::Lines);
//}

//!
//! @param pointA - punkt początkowy linii
//! @param pointB - punkt końcowy linii
//! @param color - kolor linii

void Engine::PrimitiveRenderer::drawLine(const Coordinates& pointA, const Coordinates& pointB, sf::Color color) {
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

    drawPoint(Coordinates(x1, y1), color);

    if (dx >= dy)
    {
        e = dx / 2;
        for(i = 0; i < dx; i++)
        {
            x1 += kx;
            e -= dy;
            if(e < 0)
            {
                y1 += ky;
                e += dx;
            }
            drawPoint(Coordinates(x1, y1), color);
        }
    }
    else
    {
        e = dy / 2;
        for(i = 0; i < dy; i++)
        {
            y1 += ky;
            e -= dx;
            if(e < 0)
            {
                x1 += kx;
                e += dy;
            }
            drawPoint(Coordinates(x1, y1), color);
        }
    }


}
//void Engine::PrimitiveRenderer::drawLine(const Coordinates& pointA, const Coordinates& pointB, sf::Color color) {
//    float x0 = pointA.getCoordinates().first;
//    float y0 = pointA.getCoordinates().second;
//    float x1 = pointB.getCoordinates().first;
//    float y1 = pointB.getCoordinates().second;
//
//    float dx = x1 - x0;
//    float dy = y1 - y0;
//
//    float m = dy / dx;
//
//    float y = y0;
//
//    sf::VertexArray line(sf::Points, x1 - x0 + 1);
//
//    for(int x = x0; x<=x1; x++){
//        Coordinates point(x, int(y+0.5));
////        drawPoint(point, color);
//        y+=m;
//        line.append(sf::);
//    }
//
//    _window.draw(line);
//}

void Engine::PrimitiveRenderer::drawTriangle(const Coordinates& pointA, const Coordinates& pointB, const Coordinates& pointC, sf::Color color) {
//    sf::Vertex triangle[] = {
//            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second)),
//            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second)),
//            sf::Vertex(sf::Vector2f(pointC.getCoordinates().first, pointC.getCoordinates().second))
//    };
//    for (auto & vertex : triangle) {
//        vertex.color = color;
//    }

    drawLine(pointA, pointB, color);
    drawLine(pointB, pointC, color);
    drawLine(pointC, pointA, color);

//    Engine::_window.draw(triangle, 4, sf::Triangles);
}
void Engine::PrimitiveRenderer::drawSquare(const Coordinates& pointA, const Coordinates& pointB, const Coordinates& pointC, const Coordinates& pointD, sf::Color color) {
//    sf::Vertex square[] = {
//            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second)),
//            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second)),
//            sf::Vertex(sf::Vector2f(pointC.getCoordinates().first, pointC.getCoordinates().second)),
//            sf::Vertex(sf::Vector2f(pointD.getCoordinates().first, pointD.getCoordinates().second))
//    };
//    for (auto & vertex : square) {
//        vertex.color = color;
//    }

    drawLine(pointA, pointB, color);
    drawLine(pointB, pointC, color);
    drawLine(pointC, pointD, color);
    drawLine(pointD, pointA, color);
//    Engine::_window.draw(square, 4, sf::Quads);
}

//void Engine::PrimitiveRenderer::drawFilledCircle(const Coordinates& center, float radius, sf::Color color) {
//    sf::CircleShape circle(radius);
//    circle.setPosition(center.getCoordinates().first - radius, center.getCoordinates().second - radius);
//    circle.setFillColor(color);
//
//    Engine::_window.draw(circle);
//}

 void Engine::PrimitiveRenderer::drawCircle(Engine::Coordinates& punkt, float R, sf::Color color) {
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

void Engine::PrimitiveRenderer::drawCircleSymetric(Engine::Coordinates& punkt, int R, sf::Color color) {
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

//bool Engine::PrimitiveRenderer::isPointInsideTriangle(const Engine::Coordinates &A, const Engine::Coordinates &B, const Engine::Coordinates &C, const Engine::Coordinates &P) {
//    // Obliczamy wektory normalne dla krawędzi AB, BC i CA
//    Coordinates AB(B.getCoordinates().first - A.getCoordinates().first, B.getCoordinates().second - A.getCoordinates().second)
//    , BC(C.getCoordinates().first - B.getCoordinates().first, C.getCoordinates().second - B.getCoordinates().second)
//    , CA(A.getCoordinates().first - C.getCoordinates().first, A.getCoordinates().second - C.getCoordinates().second);
//
//    // Obliczamy wektory od punktu P do wierzchołków trójkąta
//    Coordinates PA(A.getCoordinates().first - P.getCoordinates().first, A.getCoordinates().second - P.getCoordinates().second)
//    , PB(B.getCoordinates().first - P.getCoordinates().first, B.getCoordinates().second - P.getCoordinates().second)
//    , PC(C.getCoordinates().first - P.getCoordinates().first, C.getCoordinates().second - P.getCoordinates().second);
//
//    // Obliczamy iloczyny skalarny wektorów normalnych i wektorów od punktu do wierzchołków
//    double dotAB = AB.getCoordinates().first * PA.getCoordinates().first + AB.getCoordinates().second * PA.getCoordinates().second;
//    double dotBC = BC.getCoordinates().first * PB.getCoordinates().first + BC.getCoordinates().second * PB.getCoordinates().second;
//    double dotCA = CA.getCoordinates().first * PC.getCoordinates().first + CA.getCoordinates().second * PC.getCoordinates().second;
//
//    // Sprawdzamy, czy iloczyny skalarny mają tę samą parzystość
//    return (dotAB >= 0 && dotBC >= 0 && dotCA >= 0) || (dotAB <= 0 && dotBC <= 0 && dotCA <= 0);
//}

bool Engine::PrimitiveRenderer::isPointInsideTriangle(const Engine::Coordinates& A, const Engine::Coordinates& B, const Engine::Coordinates& C, const Engine::Coordinates& P) {
    // Obliczamy barycentryczne współrzędne punktu P względem trójkąta ABC
    double areaABC = 0.5 * ((B.getCoordinates().first - A.getCoordinates().first) * (C.getCoordinates().second - A.getCoordinates().second) -
                            (C.getCoordinates().first - A.getCoordinates().first) * (B.getCoordinates().second - A.getCoordinates().second));
    double alpha = 0.5 * ((B.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second) -
                          (C.getCoordinates().first - P.getCoordinates().first) * (B.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double beta = 0.5 * ((C.getCoordinates().first - P.getCoordinates().first) * (A.getCoordinates().second - P.getCoordinates().second) -
                         (A.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double gamma = 1.0 - alpha - beta;

    // Sprawdzamy, czy barycentryczne współrzędne są w zakresie [0, 1]
    return alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0;
}


void Engine::PrimitiveRenderer::fillCircle(const Coordinates& center, float radius, sf::Color fillColor) {
    int xc = center.getCoordinates().first;
    int yc = center.getCoordinates().second;

    // Iterujemy przez każdy punkt wewnątrz koła i rysujemy go
    for (int x = xc - radius; x <= xc + radius; ++x) {
        for (int y = yc - radius; y <= yc + radius; ++y) {
            // Sprawdzamy czy punkt (x, y) znajduje się wewnątrz koła
            if (std::pow(x - xc, 2) + std::pow(y - yc, 2) <= std::pow(radius, 2)) {
                drawPoint(Coordinates(x, y), fillColor);
            }
        }
    }
}


