#include "../headers/CharacterController.h"

CharacterController::CharacterController(sf::Sprite& characterSprite, AnimatedCharacter& character)
: characterSprite(characterSprite), character(character) {
}

void CharacterController::move(float deltaX, float deltaY) {
    characterSprite.move(deltaX, deltaY);
    character.setWalking(true);
}

void CharacterController::moveUp() {
    move(0.0f, -3.0f);
}

void CharacterController::moveUp(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, -scaledSpeed);
}

void CharacterController::moveDown() {
    move(0.0f, 3.0f);
}

void CharacterController::moveDown(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, scaledSpeed);
}

void CharacterController::moveLeft() {
    move(-3.0f, 0.0f);
    flipLeft();
}

void CharacterController::moveLeft(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(-scaledSpeed, 0.0f);
    flipLeft();
}

void CharacterController::moveRight() {
    move(3.0f, 0.0f);
    flipRight();
}

void CharacterController::moveRight(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(scaledSpeed, 0.0f);
    flipRight();
}

void CharacterController::flipLeft() {
    characterSprite.setScale(-1.f, 1.f);
}

void CharacterController::flipRight() {
    characterSprite.setScale(1.f, 1.f);
}
