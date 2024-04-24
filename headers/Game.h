#ifndef SILNIK2D_GAME_H
#define SILNIK2D_GAME_H

#include "../Engine.h"
#include "Point.h"
#include "PrimitiveRenderer.h"
#include "Circle.h"
#include "Square.h"

class Board {
private:
    // Kwadrat reprezentujący planszę
    Square boardSquare;

public:
    // Konstruktor
    Plansza(sf::RenderWindow& newWindow) {
        // Obliczanie wymiarów planszy na podstawie rozmiaru okna
        float boardWidth = newWindow.getSize().x * 0.8f; // Szerokość planszy na 80% szerokości okna
        float boardHeight = newWindow.getSize().y * 0.8f; // Wysokość planszy na 80% wysokości okna
        float boardX = (newWindow.getSize().x - boardWidth) / 2.0f; // Pozycja X planszy
        float boardY = (newWindow.getSize().y - boardHeight) / 2.0f; // Pozycja Y planszy

        // Inicjalizacja kwadratu reprezentującego planszę
        boardSquare = Square(
                Point(boardX, boardY),
                Point(boardX + boardWidth, boardY),
                Point(boardX + boardWidth, boardY + boardHeight),
                Point(boardX, boardY + boardHeight)
        );
    }

    // Metoda rysująca planszę
    void draw() {
        // Rysowanie planszy za pomocą kwadratu
        boardSquare.draw(sf::Color::White);
    }
};

class Game {
public:
    static void start();

private:
    static sf::RenderWindow newWindow;
    static sf::Clock _clock;
    static Circle _ball;
    static Square _paddle1;
    static Square _paddle2;
    static sf::Vector2f _ballVelocity;
    static float _paddleSpeed;
    static Board board;

    static void update(float deltaTime);
    static void render(sf::RenderWindow& newWindow);
    static void resizeBoard(sf::RenderWindow& newWindow);
};

#endif // SILNIK2D_GAME_H
