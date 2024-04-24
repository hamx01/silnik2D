#ifndef SILNIK2D_PONGGAME_H
#define SILNIK2D_PONGGAME_H

#include "Square.h"
#include "Circle.h"
#include "Keyboard.h"
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <random>

class PongGame {
private:
    sf::RenderWindow& window;
    Square leftPaddle;
    Square rightPaddle;
    Circle ball;
    sf::Font font;
    sf::Text scoreText;
    int leftScore = 0;
    int rightScore = 0;
    float ballSpeedX = 2;
    float ballSpeedY = 1;
public:
    explicit PongGame(sf::RenderWindow& window) : window(window) {
        window.create(sf::VideoMode(800, 600, 32), "Pong");

        if (!font.loadFromFile("../arial.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
        }
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setPosition(350, 10);
        scoreText.setFillColor(sf::Color::White);

        Point leftPaddleTop(50, 225); // Zmniejszam wartość y dla górnej krawędzi
        Point leftPaddleBottom(50, 375); // Zwiększam wartość y dla dolnej krawędzi
        Point rightPaddleTop(750, 225); // Zmniejszam wartość y dla górnej krawędzi
        Point rightPaddleBottom(750, 375); // Zwiększam wartość y dla dolnej krawędzi

        leftPaddle = Square(leftPaddleTop, Point(leftPaddleTop.getCoordinates().first + 20, leftPaddleTop.getCoordinates().second),
                            Point(leftPaddleBottom.getCoordinates().first + 20, leftPaddleBottom.getCoordinates().second),
                            leftPaddleBottom);

        rightPaddle = Square(rightPaddleTop, Point(rightPaddleTop.getCoordinates().first - 20, rightPaddleTop.getCoordinates().second),
                             Point(rightPaddleBottom.getCoordinates().first - 20, rightPaddleBottom.getCoordinates().second),
                             rightPaddleBottom);

        ball = Circle(Point(400, 300), 10);
    }

    void run() {
        while (window.isOpen()) {
            handleInput();
            update();
            render();
        }
    }

private:
    void handleInput() {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::W)) {
            leftPaddle.moveUp();
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::S)) {
            leftPaddle.moveDown();
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rightPaddle.moveUp();
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rightPaddle.moveDown();
        }
    }

    void update() {
        ball.move(ballSpeedX, ballSpeedY);

        if (ball.getPoint().getCoordinates().first <= leftPaddle.getBounds().left + leftPaddle.getBounds().width &&
            ball.getPoint().getCoordinates().first >= leftPaddle.getBounds().left &&
            ball.getPoint().getCoordinates().second <= leftPaddle.getBounds().top + leftPaddle.getBounds().height &&
            ball.getPoint().getCoordinates().second >= leftPaddle.getBounds().top) {
            ballSpeedX *= -1;
        }

        if (ball.getPoint().getCoordinates().first + ball.getR() * 2 >= rightPaddle.getBounds().left &&
            ball.getPoint().getCoordinates().first <= rightPaddle.getBounds().left + rightPaddle.getBounds().width &&
            ball.getPoint().getCoordinates().second + ball.getR() * 2 >= rightPaddle.getBounds().top &&
            ball.getPoint().getCoordinates().second <= rightPaddle.getBounds().top + rightPaddle.getBounds().height) {
            ballSpeedX *= -1;
        }


        if (ball.getPoint().getCoordinates().second - ball.getR() <= 0 || ball.getPoint().getCoordinates().second + ball.getR() >= 600) {
            ballSpeedY *= -1;
        }

        if (ball.getPoint().getCoordinates().first - ball.getR() <= 0) {
            // Right player scores
            ++rightScore;
            std::cout << "Right player scores. Ball coordinates: (" << ball.getPoint().getCoordinates().first << ", " << ball.getPoint().getCoordinates().second << ")" << std::endl;
            resetBall();
        }
        if (ball.getPoint().getCoordinates().first + ball.getR() >= 800) {
            // Left player scores
            ++leftScore;
            std::cout << "Left player scores. Ball coordinates: (" << ball.getPoint().getCoordinates().first << ", " << ball.getPoint().getCoordinates().second << ")" << std::endl;
            resetBall();
        }

        // Update score text
        scoreText.setString("Left: " + std::to_string(leftScore) + "  Right: " + std::to_string(rightScore));
    }
    void render() {
        window.clear(sf::Color::Black);

        // Draw paddles, ball, and score
        leftPaddle.draw(sf::Color::White);
        rightPaddle.draw(sf::Color::White);
        ball.draw(sf::Color::White);

        leftPaddle.fill();
        rightPaddle.fill();

        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(scoreText);

        window.display();
    }

    void resetBall() {
        ball.setCoordinates(400, 300);
    }
};
#endif //SILNIK2D_PONGGAME_H
