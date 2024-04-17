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
        static bool isKeyPressed(sf::Keyboard::Key key);
    };
    class Mouse {
    public:
        static sf::Vector2i getPosition();

        static sf::Vector2i getPosition(const sf::RenderWindow &relativeTo);

        static bool isButtonPressed(sf::Mouse::Button button);
    };
    class Coordinates : public sf::Drawable, public sf::Transformable {
    private:
        float x;
        float y;
        sf::CircleShape shape;
    public:
        Coordinates(float x, float y) {
            shape.setPosition(x, y);
            this->x = x;
            this->y = y;
            this->shape = sf::CircleShape(5.0f);
        }

        Coordinates(float x, float y, sf::Color color) {
            shape.setPosition(x, y);
            shape.setRadius(5.0f);
            shape.setFillColor(color);
            this->x = x;
            this->y = y;
        }

        std::pair<float, float> getCoordinates() const;

        void set_coordinates(float new_x, float new_y);

        void setColor(sf::Color color);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    };
    class PrimitiveRenderer {
    public:
        PrimitiveRenderer() = default;

        static void drawPoint(const Coordinates &coordinates, sf::Color color = sf::Color::Black);

        static void drawLine(const Coordinates &pointA, const Coordinates &pointB, sf::Color color);

        static void drawSquare(const Coordinates &pointA, const Coordinates &pointB, const Coordinates &pointC, const Coordinates &pointD, sf::Color color);

        static void drawTriangle(const Coordinates &pointA, const Coordinates &pointB, const Coordinates &pointC, sf::Color color);

        static void drawCircle(Coordinates& punkt, float R, sf::Color color);

        static void drawFilledCircle(const Coordinates &center, float radius, sf::Color color);

        static void drawCircleSymetric(Coordinates& punkt, int R, sf::Color color);

        static bool isPointInsideTriangle(const Engine::Coordinates& A, const Engine::Coordinates& B, const Engine::Coordinates& C, const Engine::Coordinates& P);

        static void fillCircle(const Coordinates& center, float radius, sf::Color fillColor);

    };
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SILNIK2D_ENGINE_H
