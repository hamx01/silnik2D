//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#ifndef SILNIK2D_ENGINE_H
#define SILNIK2D_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>

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
    class Point : public sf::Drawable, public sf::Transformable {
    private:
        float x;
        float y;
        sf::CircleShape shape;
    public:
        Point(float x, float y) {
            shape.setPosition(x, y);
            this->x = x;
            this->y = y;
            this->shape = sf::CircleShape(5.0f);
        }

        Point(float x, float y, sf::Color color) {
            shape.setPosition(x, y);
            shape.setRadius(5.0f);
            shape.setFillColor(color);
            this->x = x;
            this->y = y;
        }

        std::pair<float, float> getCoordinates() const;

        void setCoordinates(float new_x, float new_y);

        void setColor(sf::Color color);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    };
    class AnimatedCharacter {
    public:
        AnimatedCharacter(std::vector<std::string> walkFrames, std::vector<std::string> idleFrames, float posX, float posY)
                : walkFrames_(std::move(walkFrames)), idleFrames_(std::move(idleFrames)) {
            currentFrameIndex_ = 0;
            frameDuration_ = sf::seconds(0.1f);
            animationClock_.restart();

            characterSprite_.setPosition(posX, posY);
            // Wczytaj pierwszą klatkę animacji (idle)
            if (!idleFrames_.empty()) {
                characterTexture_.loadFromFile(idleFrames_[0]);
                characterSprite_.setTexture(characterTexture_);
            }
        }

        void update() {
            // Sprawdź, czy czas upłynął, aby przejść do kolejnej klatki animacji
            if (animationClock_.getElapsedTime() >= frameDuration_) {
                // Wybierz odpowiedni zestaw klatek animacji
                const std::vector<std::string>& frames = isWalking_ ? walkFrames_ : idleFrames_;
                // Przełącz na kolejną klatkę animacji
                currentFrameIndex_ = (currentFrameIndex_ + 1) % frames.size();
                characterTexture_.loadFromFile(frames[currentFrameIndex_]);
                characterSprite_.setTexture(characterTexture_);
                // Zresetuj zegar animacji
                animationClock_.restart();
            }
        }

        void setWalking(bool isWalking) {
            isWalking_ = isWalking;
        }

        sf::Sprite& getSprite() {
            return characterSprite_;
        }

    private:
        std::vector<std::string> walkFrames_;
        std::vector<std::string> idleFrames_;
        sf::Sprite characterSprite_;
        sf::Texture characterTexture_;
        sf::Clock animationClock_;
        sf::Time frameDuration_;
        int currentFrameIndex_;
        bool isWalking_;
    };

    class CharacterController {
    private:
        sf::Sprite& characterSprite;

    public:
        CharacterController(sf::Sprite& characterSprite) : characterSprite(characterSprite) {}

        void move(float deltaX, float deltaY) {
            characterSprite.move(deltaX, deltaY);
        }
    };

    class PrimitiveRenderer {
    public:

        typedef struct MousePosition {
            double x, y;
        } MousePosition;

        PrimitiveRenderer() = default;

        static void drawPoint(const Point &coordinates, sf::Color color = sf::Color::Black);

        static void drawLine(const Point &pointA, const Point &pointB, sf::Color color);

        static void drawSquare(std::vector<Point>& vertices, sf::Color color);

        static void drawTriangle(const Point &pointA, const Point &pointB, const Point &pointC, sf::Color color);

        static void drawCircle(Point& punkt, float R, sf::Color color);

        static void drawCircleSymetric(Point& punkt, float R, sf::Color color);

        static bool isPointInsideTriangle(const Engine::Point& A, const Engine::Point& B, const Engine::Point& C, const Engine::Point& P);

        static void fillCircle(const Point& center, float radius, sf::Color fillColor);

        static void dragPolygon(std::vector<Point>& vertices, const Point& P, bool isDragging, MousePosition& lastMousePosition, sf::Event event);

        static bool isPointInsidePolygon(const std::vector<Point>& vertices, const Point& P);

        static void translateSquare(std::vector<Point>& vertices, float deltaX, float deltaY);

        static void fillSquare(const std::vector<Point>& vertices, sf::Color fillColor, Point& testPoint);

        static void dragPolygonDown(std::vector<Point>& vertices) {
            for (Point &vertex: vertices) {
                float newX = vertex.getCoordinates().first + 10;
                float newY = vertex.getCoordinates().second;
                vertex.setCoordinates(newX, newY);
            }
        }

        static MousePosition getMousePosition(sf::Event event) {
            MousePosition position{};
            position.x = event.mouseMove.x;
            position.y = event.mouseMove.y;
            return position;
        }
    };
private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
    static sf::Sprite bitmapSprite;
    static std::vector<sf::Sprite> sprites; // Deklaracja kontenera sprite'ów
    static sf::Vector2f prevMousePos; // Deklaracja zmiennej przechowującej poprzednie położenie myszy
    static std::vector<std::string> walkFrames; // Declare walkFrames as a static member
    static std::vector<std::string> idleFrames; // Declare idleFrames as a static member
    static AnimatedCharacter character; // Declare AnimatedCharacter object
    static CharacterController characterController; // Declare CharacterController object

};

#endif //SILNIK2D_ENGINE_H
