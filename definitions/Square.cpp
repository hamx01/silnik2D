#include "../headers/Square.h"
#include "../headers/PrimitiveRenderer.h"
//! @brief - Rysuje kwadrat używając domyślnego białego koloru.
//! Wykonuje rysowanie konturu kwadratu oraz, jeśli zaznaczono, jego wypełnienie.
void Square::draw() {
    PrimitiveRenderer::drawSquare(points, sf::Color::White);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, sf::Color::White);
    }
}
//! @brief - Rysuje kwadrat w określonym kolorze.
//! @param color - Kolor kwadratu.
//! Wykonuje rysowanie konturu kwadratu oraz, jeśli zaznaczono, jego wypełnienie w podanym kolorze.
void Square::draw(sf::Color color) {
    PrimitiveRenderer::drawSquare(points, color);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, color);
    }
}
//! @brief - Metoda umożliwiająca rysowanie kwadratu na danym celu renderowania, używana w kontekście biblioteki SFML.
//! @param target - Cel renderowania, na którym kwadrat ma być narysowany.
//! @param states - Stan renderowania używany podczas rysowania.
//! Metoda jest aktualnie pusta, ale może być rozwinięta do obsługi bardziej zaawansowanych scenariuszy renderowania w SFML.
void Square::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

//void Square::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    PrimitiveRenderer::drawSquare(points, sf::Color::White);
//    if(isFilled) {
//        PrimitiveRenderer::fillPolygon(points, sf::Color::White);
//    }
//}
