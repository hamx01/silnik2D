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
    float dx, dy, kx, ky, e;
    int i;

    float x1 = pointA.getCoordinates().first;
    float x2 = pointB.getCoordinates().first;
    float y1 = pointA.getCoordinates().second;
    float y2 = pointB.getCoordinates().second;

    if (x1 <= x2) kx = 1; else kx = -1;
    if (y1 <= y2) ky = 1; else ky = -1;

    dx = x2 - x1;
    if (dx < 0) dx = -dx;
    dy = y2 - y1;
    if (dy < 0) dy = -dy;

    drawPoint(Point(x1, y1), color);

    if (dx >= dy) {
        e = dx / 2;
        for(i = 0; float(i) < dx; i++) {
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
        for(i = 0; float(i) < dy; i++) {
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

void Engine::PrimitiveRenderer::drawTriangle(std::vector<Point>& vertices, sf::Color color) {
    int n = int(vertices.size());

    for(int i = 0; i<n; i++) {
        if(i < 2) {
            drawLine(vertices[i], vertices[i+1], color);
        } else if(i == 2) {
            drawLine(vertices[i], vertices[0], color);
        }
    }
}
void Engine::PrimitiveRenderer::drawSquare(std::vector<Point>& vertices, sf::Color color) {
    int n = int(vertices.size());

    for(int i = 0; i<n; i++) {
        if(i < 3) {
            drawLine(vertices[i], vertices[i+1], color);
        } else if(i == 3) {
            drawLine(vertices[i], vertices[0], color);
        }
    }
}

void Engine::PrimitiveRenderer::drawCircle(Engine::Point& punkt, float R, sf::Color color) {
    float step = 1.0f / R;
    sf::VertexArray points(sf::Points);
    float xc = punkt.getCoordinates().first;
    float yc = punkt.getCoordinates().second;

    for (float a = 0; a < 2 * M_PI; a += step) {
        float x = xc + R * std::cos(a) + 0.5f;
        float y = yc + R * std::sin(a) + 0.5f;

        points.append(sf::Vertex(sf::Vector2f(x, y), color));
    }

    _window.draw(points);
}

void Engine::PrimitiveRenderer::drawCircleSymetric(Engine::Point& punkt, float R, sf::Color color) {
    float xc = punkt.getCoordinates().first;
    float yc = punkt.getCoordinates().second;
    sf::VertexArray points(sf::Points);

    float step = 1.0f / R;
    for (float a = 0; a <= M_PI / 4; a += step) {
        float x = xc + R * std::cos(a) + 0.5f;
        float y = yc + R * std::sin(a) + 0.5f;

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

    int numPoints = int(points.getVertexCount());
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
    float xc = center.getCoordinates().first;
    float yc = center.getCoordinates().second;

    for (int x = int(xc - radius); float(x) <= xc + radius; ++x) {
        for (int y = int(yc - radius); float(y) <= yc + radius; ++y) {
            if (std::pow(x - xc, 2) + std::pow(y - yc, 2) <= std::pow(radius, 2)) {
                drawPoint(Point(x, y), fillColor);
            }
        }
    }
}

void Engine::PrimitiveRenderer::translatePolygon(std::vector<Point>& vertices, float deltaX, float deltaY) {
    bool withinBounds = true;

    // Sprawdzenie, czy po przesunięciu wszystkie wierzchołki będą w granicach okna
    for (auto& point : vertices) {
        float x = point.getCoordinates().first;
        float y = point.getCoordinates().second;

        float newX = x + deltaX;
        float newY = y + deltaY;

        if (newX < 0 || newX > 800 || newY < 0 || newY > 600) {
            withinBounds = false;
            break;
        }
    }

    // Przesunięcie wierzchołków, jeśli wszystkie są w granicach
    if (withinBounds) {
        for (auto& point : vertices) {
            float newX = point.getCoordinates().first + deltaX;
            float newY = point.getCoordinates().second + deltaY;

            point.setCoordinates(newX, newY);
        }
    } else {
        std::cerr << "Przekroczenie granicy okna!" << std::endl;
    }

    std::cout << "Zaktualizowane wspolrzedne:" << std::endl;
    for (const auto& point : vertices) {
        std::cout << "Punkt - x: " << point.getCoordinates().first
                  << " || y: " << point.getCoordinates().second << std::endl;
    }
}




void Engine::PrimitiveRenderer::fillSquare(const std::vector<Point>& vertices, sf::Color fillColor) {
    sf::ConvexShape filledSquare;
    filledSquare.setPointCount(vertices.size());
    for(int i = 0; i < vertices.size(); i++) {
        filledSquare.setPoint(i, sf::Vector2f(vertices[i].getCoordinates().first, vertices[i].getCoordinates().second));
    }
    filledSquare.setFillColor(sf::Color::Transparent);
    filledSquare.setFillColor(fillColor);
    _window.draw(filledSquare);
}

void Engine::PrimitiveRenderer::scalePolygon(std::vector<Point>& vertices, float scaleFactor) {
    float centerX = 0.0f;
    float centerY = 0.0f;
    for (const auto& point : vertices) {
        centerX += point.getCoordinates().first;
        centerY += point.getCoordinates().second;
    }
    centerX /= float(vertices.size());
    centerY /= float(vertices.size());

    for (auto& point : vertices) {
        float x = point.getCoordinates().first;
        float y = point.getCoordinates().second;

        float distX = x - centerX;
        float distY = y - centerY;

        float scaledDistX = distX * scaleFactor;
        float scaledDistY = distY * scaleFactor;

        point.setCoordinates(centerX + scaledDistX, centerY + scaledDistY);
    }
}

void Engine::PrimitiveRenderer::rotatePolygon(std::vector<Point>& vertices, float angle, float deltaTime) {
    if (vertices.empty()) return;

    float normalizedAngle = angle / float(vertices.size());

    float centerX = 0.0f;
    float centerY = 0.0f;
    for (const Point& vertex : vertices) {
        auto [x, y] = vertex.getCoordinates();
        centerX += x;
        centerY += y;
    }
    centerX /= float(vertices.size());
    centerY /= float(vertices.size());

    for (Point& vertex : vertices) {
        auto [x, y] = vertex.getCoordinates();

        x -= centerX;
        y -= centerY;

        float rotatedX = x * cos(normalizedAngle * deltaTime) - y * sin(normalizedAngle * deltaTime);
        float rotatedY = x * sin(normalizedAngle * deltaTime) + y * cos(normalizedAngle * deltaTime);

        rotatedX += centerX;
        rotatedY += centerY;

        vertex.setCoordinates(rotatedX, rotatedY);
    }
}




