//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class Engine {
public:
    static void start();
    static void engineLoop();


    class Keyboard {
    public:
        static bool isKeyPressed(sf::Keyboard::Key key) {
        return sf::Keyboard::isKeyPressed(key);
        }
    };

    class Mouse {
    public:
        static sf::Vector2i getPosition() {
            return sf::Mouse::getPosition();
        }

        static sf::Vector2i getPosition(const sf::RenderWindow& relativeTo) {
            return sf::Mouse::getPosition(relativeTo);
        }

        static bool isButtonPressed(sf::Mouse::Button button) {
            return sf::Mouse::isButtonPressed(button);
        }
    };
    class Coordinates : public sf::Drawable, public sf::Transformable {
    private:
        float x;
        float y;
        sf::CircleShape shape;
    public:
        Coordinates(float x, float y) : x(x), y(y), shape(5.0f) {
            shape.setPosition(x, y);
        }

        std::pair<float, float> getCoordinates() const {
            return std::make_pair(x, y);
        }

        void set_coordinates(float new_x, float new_y) {
            this->x = new_x;
            this->y = new_y;
            shape.setPosition(new_x, new_y);
        }

        void setColor(sf::Color color) {
            shape.setFillColor(color);
        }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            states.transform *= getTransform();
            target.draw(shape, states);
        }

    };
    class PrimitiveRenderer {
    public:
        PrimitiveRenderer() = default;

        static void drawPoint(const Coordinates &coordinates, sf::Color color = sf::Color::Black) {
            int x = coordinates.getCoordinates().first;
            int y = coordinates.getCoordinates().second;
            sf::Vertex point(sf::Vector2f(x, y), color);
            Engine::_window.draw(&point, 2, sf::Points);
        }

        static void drawLine(const Coordinates& pointA, const Coordinates& pointB, sf::Color color) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(pointA.getCoordinates().first, pointA.getCoordinates().second), color),
                    sf::Vertex(sf::Vector2f(pointB.getCoordinates().first, pointB.getCoordinates().second), color)
            };

            Engine::_window.draw(line, 2, sf::Lines);
        }

        static void drawTriangle(const Coordinates& pointA, const Coordinates& pointB, const Coordinates& pointC, sf::Color color) {
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
    };
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SILNIK2D_ENGINE_H
