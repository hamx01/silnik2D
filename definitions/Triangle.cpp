#include "../headers/Triangle.h"
#include "../headers/PrimitiveRenderer.h"
//! @brief - Rysuje trójkąt używając domyślnego białego koloru.
//! Wykonuje rysowanie konturu trójkąta oraz, jeśli zaznaczono, jego wypełnienie.
void Triangle::draw() {
    PrimitiveRenderer::drawTriangle(points, sf::Color::White);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, sf::Color::White);
    }
}
//! @brief - Rysuje trójkąt w określonym kolorze.
//! @param color - Kolor trójkąta.
//! Wykonuje rysowanie konturu trójkąta oraz, jeśli zaznaczono, jego wypełnienie w podanym kolorze.
void Triangle::draw(sf::Color color) {
    PrimitiveRenderer::drawTriangle(points, color);
    if(isFilled) {
        PrimitiveRenderer::fillPolygon(points, color);
    }
}
//! @brief - Metoda umożliwiająca rysowanie trójkąta na danym celu renderowania, używana w kontekście biblioteki SFML.
//! @param target - Cel renderowania, na którym trójkąt ma być narysowany.
//! @param states - Stan renderowania używany podczas rysowania.
//! Metoda jest aktualnie pusta, ale może być rozwinięta do obsługi bardziej zaawansowanych scenariuszy renderowania w SFML.
void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
