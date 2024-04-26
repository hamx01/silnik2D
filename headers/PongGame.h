#ifndef SILNIK2D_PONGGAME_H
#define SILNIK2D_PONGGAME_H

#include "Square.h"
#include "Circle.h"
#include "Keyboard.h"
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <random>
//! @class PongGame
//! @brief Klasa implementująca mechanikę gry Pong.
class PongGame {
private:
    sf::RenderWindow& window;//! - Referencja do okna gry.
    Square leftPaddle;//! - Obiekt reprezentujący lewą paletkę.
    Square rightPaddle;//! - Obiekt reprezentujący prawą paletkę.
    Circle ball;//! - Obiekt reprezentujący piłkę.
    sf::Font font;//! - Czcionka używana do wyświetlania wyniku.
    sf::Text scoreText;//! - Tekst wyświetlający wynik.
    int leftScore = 0;//! - Liczba punktów zdobytych przez lewego gracza.
    int rightScore = 0;//! - Liczba punktów zdobytych przez prawego gracza.
    float ballSpeedX = 2;//! - Prędkość piłki w osi X.
    float ballSpeedY = 1;//! - Prędkość piłki w osi Y.
public:
//! @brief - Konstruktor klasy PongGame.
//! @param window - Referencja do okna gry, w którym będzie wyświetlana gra.
    explicit PongGame(sf::RenderWindow& window) : window(window) {
        srand(time(nullptr));
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
//! @brief - Główna pętla gry, zarządzająca wejściem, aktualizacją stanu gry i renderowaniem.
    void run() {
        while (window.isOpen()) {
            handleInput();
            update();
            render();
        }
    }

private:
//! @brief - Obsługuje zdarzenia wejściowe, takie jak klawiatura i zamknięcie okna.
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
        if (Keyboard::isKeyPressed(sf::Keyboard::F9)) {
            Engine::closeActiveWindow();
        }
    }
//! @brief - Aktualizuje stan gry, w tym pozycje paletki i piłki oraz wyniki.
    void update() {
        ball.move(ballSpeedX, ballSpeedY);

        if (ball.getPoint().getCoordinates().first - ball.getR() * 1.5 <= leftPaddle.getBounds().left + leftPaddle.getBounds().width &&
            ball.getPoint().getCoordinates().first >= leftPaddle.getBounds().left &&
            ball.getPoint().getCoordinates().second + ball.getR() * 1.5 >= leftPaddle.getBounds().top &&
            ball.getPoint().getCoordinates().second <= leftPaddle.getBounds().top + leftPaddle.getBounds().height) {
            ballSpeedX *= -1;
        }

        if (ball.getPoint().getCoordinates().first + ball.getR() * 1.5 >= rightPaddle.getBounds().left &&
            ball.getPoint().getCoordinates().first <= rightPaddle.getBounds().left + rightPaddle.getBounds().width &&
            ball.getPoint().getCoordinates().second + ball.getR() * 1.5 >= rightPaddle.getBounds().top &&
            ball.getPoint().getCoordinates().second <= rightPaddle.getBounds().top + rightPaddle.getBounds().height) {
            ballSpeedX *= -1;
        }

        if (ball.getPoint().getCoordinates().second - 1.5*ball.getR() <= 0) {
            ballSpeedY *= -1;
        }
        if(ball.getPoint().getCoordinates().second + 1.5*ball.getR() >= 600) {
            ballSpeedY *= -1;
        }

        if (ball.getPoint().getCoordinates().first - 1.5*ball.getR() <= 0) {
            ++rightScore;
            std::cout << "Right player scores. Ball coordinates: (" << ball.getPoint().getCoordinates().first << ", " << ball.getPoint().getCoordinates().second << ")" << std::endl;
            resetBall();
        }
        if (ball.getPoint().getCoordinates().first + 1.5*ball.getR() >= 800) {
            ++leftScore;
            std::cout << "Left player scores. Ball coordinates: (" << ball.getPoint().getCoordinates().first << ", " << ball.getPoint().getCoordinates().second << ")" << std::endl;
            resetBall();
        }

        scoreText.setString("Left: " + std::to_string(leftScore) + "  Right: " + std::to_string(rightScore));
    }
//! @brief - Renderuje obiekty gry na ekranie.
    void render() {
        window.clear(sf::Color::Black);

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
//! @brief - Resetuje pozycję i prędkość piłki po zdobyciu punktu.
    void resetBall() {
        ball.setCoordinates(400, 300);
        ballSpeedX = float((std::rand() % 4 + 2) * (std::rand() % 2 == 0 ? 1 : -1) * 100) / 100.0f; // Random speed between 2 and 5, random direction
        ballSpeedY = float((std::rand() % 4 + 2) * (std::rand() % 2 == 0 ? 1 : -1) * 100) / 100.0f; // Random speed between 2 and 5, random direction
    }
};
#endif //SILNIK2D_PONGGAME_H
