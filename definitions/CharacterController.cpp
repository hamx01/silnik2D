#include "../headers/CharacterController.h"
//! @brief - Konstruktor klasy CharacterController.
//! @param characterSprite - Referencja do sprite'a postaci.
//! @param character - Referencja do obiektu AnimatedCharacter, który jest animowaną postacią.
CharacterController::CharacterController(sf::Sprite& characterSprite, AnimatedCharacter& character)
: characterSprite(characterSprite), character(character) {
}
//! @brief - Przesuwa postać o określoną odległość w osi X i Y.
//! @param deltaX - Przesunięcie w osi X.
//! @param deltaY - Przesunięcie w osi Y.
//! Dodatkowo ustawia stan chodzenia postaci na true.
void CharacterController::move(float deltaX, float deltaY) {
    characterSprite.move(deltaX, deltaY);
    character.setWalking(true);
}
//! @brief - Przesuwa postać w górę.
void CharacterController::moveUp() {
    move(0.0f, -3.0f);
}
//! @brief - Przesuwa postać w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
void CharacterController::moveUp(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, -scaledSpeed);
}
//! @brief - Przesuwa postać w dół.
void CharacterController::moveDown() {
    move(0.0f, 3.0f);
}
//! @brief - Przesuwa postać w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
void CharacterController::moveDown(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, scaledSpeed);
}
//! @brief - Przesuwa postać w lewo.
//! Dodatkowo odwraca postać w lewo.
void CharacterController::moveLeft() {
    move(-3.0f, 0.0f);
    flipLeft();
}
//! @brief - Przesuwa postać w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
//! Dodatkowo odwraca postać w lewo.
void CharacterController::moveLeft(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(-scaledSpeed, 0.0f);
    flipLeft();
}
//! @brief - Przesuwa postać w prawo.
//! Dodatkowo odwraca postać w prawo.
void CharacterController::moveRight() {
    move(3.0f, 0.0f);
    flipRight();
}
//! @brief - Przesuwa postać w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
//! Dodatkowo odwraca postać w prawo.
void CharacterController::moveRight(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(scaledSpeed, 0.0f);
    flipRight();
}
//! @brief - Odwraca postać w lewo.
void CharacterController::flipLeft() {
    characterSprite.setScale(-1.f, 1.f);
}
//! @brief - Odwraca postać w prawo.
void CharacterController::flipRight() {
    characterSprite.setScale(1.f, 1.f);
}
