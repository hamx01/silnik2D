#include "../headers/Game.h"
#include "../headers/Square.h"
#include "../headers/PrimitiveRenderer.h"
#include "../headers/Circle.h"

PrimitiveRenderer render;
Square player(Point(400, 500), Point(400, 450), Point(450, 450), Point(450, 500));
Square enemy(Point(200, 200), Point(200, 150), Point(250, 150), Point(250, 200));
Circle ball(Point(250, 60.0));
int playerScore = 0;
int enemyScore = 0;

void Game::start() {
    // Tworzenie nowego okna
    sf::RenderWindow newWindow(sf::VideoMode(800, 600), "Nowe Okno");
    newWindow.setFramerateLimit(60);

    while (newWindow.isOpen()) {
        float deltaTime = _clock.restart().asSeconds();
        newWindow.clear();

        // Obsługa zdarzeń
        sf::Event event{};
        while (newWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { newWindow.close(); }
            // Obsługa innych zdarzeń, takich jak obsługa myszy i klawiatury, możesz przenieść je tutaj
        }

        // Ustawienie początkowych pozycji gracza i przeciwnika
        // (w rzeczywistej grze te pozycje mogą być dynamicznie ustawiane)
        // playerSquare.setPosition(400, 500);
        // enemySquare.setPosition(200, 200);

        newWindow.draw(player);
        newWindow.draw(enemy);
        newWindow.draw(ball);

        update(deltaTime);

        // Rysowanie obiektów na ekranie
        render.render(newWindow);
        // Tutaj możesz przenieść kod obsługi bitmapy, animacji i innych elementów gry
    }
}

void Game::render(sf::RenderWindow& _window) {
    _window.clear(sf::Color::Black);
    // Rysowanie planszy Pong
    // board.draw(sf::Color::White); // Jeśli plansza nie jest już potrzebna, możemy ją usunąć
    // Inne elementy gry
    // Rysuj obiekty gry
    // Rysujemy kwadrat gracza i przeciwnika oraz piłkę
    _window.draw(player);
    _window.draw(enemy);
    _window.draw(ball);

    // Wyświetlenie obrazu
    _window.display();
}

// Dodaj tę metodę do klasy Game
void Game::Game() resizeBoard(sf::RenderWindow& _window) {
    // Zmiana rozmiaru planszy
    board.resize(_window);
}

void Game::update(float deltaTime) {
    // Aktualizacja logiki gry
    // Sprawdzanie kolizji piłki z paletkami gracza i przeciwnika
    if (ball.intersects(player)) {
        ball.bounceOffPlayer(player);
    }
    if (ball.intersects(enemy)) {
        ball.bounceOffEnemy(enemy);
    }

    // Aktualizacja pozycji piłki
    ball.update(deltaTime);

    // Sprawdzanie czy piłka wyleciała poza ekran
    if (ball.outOfBounds()) {
        // Obsługa punktacji
        if (ball.outOfBoundsLeft()) {
            // Punkty dla gracza
            playerScore++;
        } else {
            // Punkty dla przeciwnika
            enemyScore++;
        }

        // Resetowanie pozycji piłki
        ball.resetPosition();
    }
}

void Game::gameLoop() {

}
