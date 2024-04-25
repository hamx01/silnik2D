#ifndef SILNIK2D_CHARACTERCONTROLLER_H
#define SILNIK2D_CHARACTERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "AnimatedCharacter.h"
//! @class CharackterController
//! @brief Klasa odpowiadająca za kontrolowanie postaci w grze, zarządzanie ruchem i animacjami.
class CharacterController {
private:
    sf::Sprite& characterSprite;
    AnimatedCharacter& character;
public:
//! @brief - Konstruktor klasy CharacterController.
//! @param characterSprite - Referencja do sprite'a postaci.
//! @param character - Referencja do obiektu AnimatedCharacter, który jest animowaną postacią.
    CharacterController(sf::Sprite &characterSprite, AnimatedCharacter &character);
//! @brief - Przesuwa postać o zadane wartości delta X i Y.
//! @param deltaX - Przesunięcie w poziomie.
//! @param deltaY - Przesunięcie w pionie.
    void move(float deltaX, float deltaY);
//! @brief - Przesuwa postać w górę.
    void moveUp();
//! @brief - Przesuwa postać w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveUp(float speed);
//! @brief - Przesuwa postać w dół.
    void moveDown();
//! @brief - Przesuwa postać w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveDown(float speed);
//! @brief - Przesuwa postać w lewo.
    void moveLeft();
//! @brief - Przesuwa postać w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveLeft(float speed);
//! @brief - Przesuwa postać w prawo.
    void moveRight();
//! @brief - Przesuwa postać w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia.
    void moveRight(float speed);
//! @brief - Obraca postać w lewo (zmienia orientację sprite'a).
    void flipLeft();
//! @brief - Obraca postać w prawo (zmienia orientację sprite'a).
    void flipRight();




};

#endif //SILNIK2D_CHARACTERCONTROLLER_H
