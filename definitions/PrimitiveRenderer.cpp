//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../headers/PrimitiveRenderer.h"
#include "../Engine.h"
#include <cmath>

//! Metoda rysująca punkt na ekranie
void PrimitiveRenderer::drawPoint(const Point &coordinates, sf::Color color) {
    float x = coordinates.getCoordinates().first;
    float y = coordinates.getCoordinates().second;
    sf::Vertex point(sf::Vector2f(x, y), color);
    Engine::getActiveWindow().draw(&point, 2, sf::Points);
}

//!
//! @param pointA - punkt początkowy linii
//! @param pointB - punkt końcowy linii
//! @param color - kolor linii
void PrimitiveRenderer::drawLine(const Point& pointA, const Point& pointB, sf::Color color) {
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

void PrimitiveRenderer::drawTriangle(std::vector<Point>& vertices, sf::Color color) {
    int n = int(vertices.size());

    for(int i = 0; i<n; i++) {
        if(i < 2) {
            drawLine(vertices[i], vertices[i+1], color);
        } else if(i == 2) {
            drawLine(vertices[i], vertices[0], color);
        }
    }
}
void PrimitiveRenderer::drawSquare(std::vector<Point>& vertices, sf::Color color) {
    int n = int(vertices.size());

    for(int i = 0; i<n; i++) {
        if(i < 3) {
            drawLine(vertices[i], vertices[i+1], color);
        } else if(i == 3) {
            drawLine(vertices[i], vertices[0], color);
        }
    }
}

void PrimitiveRenderer::drawCircle(Point& punkt, float R, sf::Color color) {
    float step = 1.0f / R;
    sf::VertexArray points(sf::Points);
    float xc = punkt.getCoordinates().first;
    float yc = punkt.getCoordinates().second;

    for (float a = 0; a < 2 * M_PI; a += step) {
        float x = xc + R * std::cos(a) + 0.5f;
        float y = yc + R * std::sin(a) + 0.5f;

        points.append(sf::Vertex(sf::Vector2f(x, y), color));
    }

    Engine::getActiveWindow().draw(points);
}

void PrimitiveRenderer::drawCircleSymetric(Point& punkt, float R, sf::Color color) {
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
    Engine::getWindow().draw(points);
}

bool PrimitiveRenderer::isPointInsideTriangle(const Point& A, const Point& B, const Point& C, const Point& P) {
    double areaABC = 0.5 * ((B.getCoordinates().first - A.getCoordinates().first) * (C.getCoordinates().second - A.getCoordinates().second) -
                            (C.getCoordinates().first - A.getCoordinates().first) * (B.getCoordinates().second - A.getCoordinates().second));
    double alpha = 0.5 * ((B.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second) -
                          (C.getCoordinates().first - P.getCoordinates().first) * (B.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double beta = 0.5 * ((C.getCoordinates().first - P.getCoordinates().first) * (A.getCoordinates().second - P.getCoordinates().second) -
                         (A.getCoordinates().first - P.getCoordinates().first) * (C.getCoordinates().second - P.getCoordinates().second)) / areaABC;
    double gamma = 1.0 - alpha - beta;

    return alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0;
}

bool PrimitiveRenderer::isPointInsidePolygon(const std::vector<Point>& vertices, const Point& P) {
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

void PrimitiveRenderer::fillCircleBresenham(const Point& center, float radius, sf::Color fillColor) {
    float x = 0;
    float y = radius;
    float d = 3 - 2 * radius;

    auto drawLine = [&](int sx, int ex, int ny) {
        for (int i = sx; i <= ex; i++) {
            drawPoint(Point(float(i), float(ny)), fillColor);
        }
    };

    while (y >= x) {
        drawLine(center.getCoordinates().first - x, center.getCoordinates().first + x, center.getCoordinates().second + y);
        drawLine(center.getCoordinates().first - y, center.getCoordinates().first + y, center.getCoordinates().second + x);
        drawLine(center.getCoordinates().first - y, center.getCoordinates().first + y, center.getCoordinates().second - x);
        drawLine(center.getCoordinates().first - x, center.getCoordinates().first + x, center.getCoordinates().second - y);

        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void PrimitiveRenderer::fillCircle(const Point& center, float radius, sf::Color fillColor) {
    sf::CircleShape circle(radius);
    circle.setFillColor(fillColor);
    circle.setPosition(center.getCoordinates().first - radius, center.getCoordinates().second - radius);
    Engine::getWindow().draw(circle);
}

void PrimitiveRenderer::translateCircle(Point& center, float R, float deltaX, float deltaY) {
    float new_x = center.getCoordinates().first + deltaX;
    float new_y = center.getCoordinates().second + deltaY;

    if (new_x - R < 0 || new_x + R > 800 ||
        new_y - R < 0 || new_y + R > 600) {
        return;
    }

    center.setCoordinates(new_x, new_y);
}

void PrimitiveRenderer::translatePolygon(std::vector<Point>& vertices, float deltaX, float deltaY) {
    bool withinBounds = true;

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

    if (withinBounds) {
        for (auto& point : vertices) {
            float newX = point.getCoordinates().first + deltaX;
            float newY = point.getCoordinates().second + deltaY;

            point.setCoordinates(newX, newY);
        }
    } else {

    }
}




void PrimitiveRenderer::fillPolygon(const std::vector<Point>& vertices, sf::Color fillColor) {
    sf::ConvexShape filledSquare;
    filledSquare.setPointCount(vertices.size());
    for(int i = 0; i < vertices.size(); i++) {
        filledSquare.setPoint(i, sf::Vector2f(vertices[i].getCoordinates().first, vertices[i].getCoordinates().second));
    }
    filledSquare.setFillColor(sf::Color::Transparent);
    filledSquare.setFillColor(fillColor);
    Engine::getActiveWindow().draw(filledSquare);
}

void PrimitiveRenderer::scalePolygon(std::vector<Point>& vertices, float scaleFactor) {
    float centerX = 0.0f;
    float centerY = 0.0f;
    float minX = std::numeric_limits<float>::max();
    float minY = std::numeric_limits<float>::max();
    float maxX = std::numeric_limits<float>::min();
    float maxY = std::numeric_limits<float>::min();

    for (const auto& point : vertices) {
        float x = point.getCoordinates().first;
        float y = point.getCoordinates().second;
        centerX += x;
        centerY += y;
        minX = std::min(minX, x);
        minY = std::min(minY, y);
        maxX = std::max(maxX, x);
        maxY = std::max(maxY, y);
    }
    centerX /= float(vertices.size());
    centerY /= float(vertices.size());

    float newMinX = centerX + (minX - centerX) * scaleFactor;
    float newMinY = centerY + (minY - centerY) * scaleFactor;
    float newMaxX = centerX + (maxX - centerX) * scaleFactor;
    float newMaxY = centerY + (maxY - centerY) * scaleFactor;

    float windowWidth = Engine::getWindowSize().first;
    float windowHeight = Engine::getWindowSize().second;

    if (newMinX < 0 || newMaxX > windowWidth || newMinY < 0 || newMaxY > windowHeight) {
        return;
    }

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

void PrimitiveRenderer::rotatePolygon(std::vector<Point>& vertices, float angle, float deltaTime) {
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

    std::vector<Point> rotatedVertices = vertices;

    for (Point& vertex : rotatedVertices) {
        auto [x, y] = vertex.getCoordinates();

        x -= centerX;
        y -= centerY;

        float rotatedX = x * cos(normalizedAngle * deltaTime) - y * sin(normalizedAngle * deltaTime);
        float rotatedY = x * sin(normalizedAngle * deltaTime) + y * cos(normalizedAngle * deltaTime);

        rotatedX += centerX;
        rotatedY += centerY;

        vertex.setCoordinates(rotatedX, rotatedY);
    }

    for (const Point& vertex : rotatedVertices) {
        auto [x, y] = vertex.getCoordinates();
        if (x < 0 || x > Engine::getWindowSize().first || y < 0 || y > Engine::getWindowSize().second) {
            return; // jeżeli chociaż jeden punktjest poza oknem, przestań
        }
    }

    vertices = rotatedVertices; // Apply the rotation
}




