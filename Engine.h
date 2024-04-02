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
        static bool isKeyPressedPlayer1(char key);
        static bool isKeyPressedPlayer2(char key);
        static bool isKeyEsc(char key);
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
    class Cordinates : public sf::Drawable, public sf::Transformable {
    private:
        float x;
        float y;
        sf::CircleShape shape;
    public:
        Cordinates(float x, float y) : x(x), y(y), shape(5.0f) {
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
    class Figures {};
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SILNIK2D_ENGINE_H
