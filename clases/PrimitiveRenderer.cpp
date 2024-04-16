//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../Engine.h"

void Engine::PrimitiveRenderer::drawPoint(const Coordinates &coordinates, sf::Color color) {
    float x = coordinates.getCoordinates().first;
    float y = coordinates.getCoordinates().second;
    sf::Vertex point(sf::Vector2f(x, y), color);
    Engine::_window.draw(&point, 2, sf::Points);
}

void Engine::PrimitiveRenderer::drawLine(const Coordinates& pointA, const Coordinates& pointB, sf::Color color) {
    sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second), color),
            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second), color)
    };

    Engine::_window.draw(line, 2, sf::Lines);
}

void Engine::PrimitiveRenderer::drawTriangle(const Coordinates& pointA, const Coordinates& pointB, const Coordinates& pointC, sf::Color color) {
    sf::Vertex triangle[] = {
            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second)),
            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second)),
            sf::Vertex(sf::Vector2f(pointC.getCoordinates().first, pointC.getCoordinates().second))
    };
    for (auto & vertex : triangle) {
        vertex.color = color;
    }
    Engine::_window.draw(triangle, 4, sf::Triangles);
}
void Engine::PrimitiveRenderer::drawSquare(const Coordinates& pointA, const Coordinates& pointB, const Coordinates& pointC, const Coordinates& pointD, sf::Color color) {
    sf::Vertex square[] = {
            sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second)),
            sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second)),
            sf::Vertex(sf::Vector2f(pointC.getCoordinates().first, pointC.getCoordinates().second)),
            sf::Vertex(sf::Vector2f(pointD.getCoordinates().first, pointD.getCoordinates().second))
    };
    for (auto & vertex : square) {
        vertex.color = color;
    }
    Engine::_window.draw(square, 4, sf::Quads);
}

void Engine::PrimitiveRenderer::drawFilledCircle(const Coordinates& center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.getCoordinates().first - radius, center.getCoordinates().second - radius);
    circle.setFillColor(color);

    Engine::_window.draw(circle);
}

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

    // Oblicz punkty dla jednej czwartej okręgu (0 do PI/4)
    float step = 1.0f / R;
    for (float a = 0; a <= M_PI / 4; a += step) {
        int x = static_cast<int>(xc + R * std::cos(a) + 0.5f); // Zaokrąglone X
        int y = static_cast<int>(yc + R * std::sin(a) + 0.5f); // Zaokrąglone Y

        // Dodaj punkt do tablicy wierzchołków
        points.append(sf::Vertex(sf::Vector2f(x, y), color));

        // Symetrie punktów względem osi pionowej, poziomej i obydwu przekątnych
        if (x != xc) {
            points.append(sf::Vertex(sf::Vector2f(xc - (x - xc), y), color)); // Symetria względem osi pionowej
        }
        if (y != yc) {
            points.append(sf::Vertex(sf::Vector2f(x, yc - (y - yc)), color)); // Symetria względem osi poziomej
        }
        if (x != xc && y != yc) {
            points.append(
                    sf::Vertex(sf::Vector2f(xc - (x - xc), yc - (y - yc)), color)); // Symetria względem obu przekątnych
        }
    }

    // Odbij punkty, aby uzyskać pełny okrąg
    int numPoints = points.getVertexCount();
    for (int i = 0; i < numPoints; ++i) {
        sf::Vertex vertex = points[i];
        if (vertex.position.x != xc) {
            vertex.position.x = xc - (vertex.position.x - xc); // Symetria względem osi pionowej
            points.append(vertex);
        }
        if (vertex.position.y != yc) {
            vertex.position.y = yc - (vertex.position.y - yc); // Symetria względem osi poziomej
            points.append(vertex);
        }
        if (vertex.position.x != xc && vertex.position.y != yc) {
            sf::Vector2f mirroredPosition = sf::Vector2f(xc - (vertex.position.x - xc), yc - (vertex.position.y - yc));
            points.append(sf::Vertex(mirroredPosition, color)); // Symetria względem obu przekątnych
        }
    }
}