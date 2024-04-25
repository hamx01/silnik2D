#include "../headers/AnimatedCharacter.h"

//! @brief - Konstruktor, inicjuje postać w określonej pozycji.
//! @param posX - Położenie początkowe w osi X.
//! @param posY - Położenie początkowe w osi Y.
AnimatedCharacter::AnimatedCharacter(float posX, float posY) {
    currentFrameIndex_ = 0;
    frameDuration_ = sf::seconds(0.1f);
    animationClock_.restart();
    characterSprite_.setPosition(posX, posY);
}
//! @brief - Aktualizuje stan animacji postaci.
//! Sprawdza, czy czas trwania klatki został przekroczony, a następnie aktualizuje teksturę i indeks klatki.
void AnimatedCharacter::update() {
    if (animationClock_.getElapsedTime() >= frameDuration_) {
        const std::vector<std::string>& frames = isWalking_ ? walkFrames_ : idleFrames_;
        currentFrameIndex_ = int((currentFrameIndex_ + 1) % frames.size());
        characterTexture_.loadFromFile(frames[currentFrameIndex_]);
        characterSprite_.setTexture(characterTexture_);
        animationClock_.restart();
    }

    characterSprite_.setOrigin(characterSprite_.getLocalBounds().width / 2.f, characterSprite_.getLocalBounds().height / 2.f);
}
//! @brief - Ustawia stan chodzenia postaci.
//! @param isWalking - true, jeśli postać ma chodzić, false jeśli ma stać w miejscu.
void AnimatedCharacter::setWalking(bool isWalking) {
    isWalking_ = isWalking;
}
//! @brief - Zwraca referencję do sprite'a postaci.
//! @return Referencja do sprite'a postaci.
sf::Sprite& AnimatedCharacter::getSprite() {
    return characterSprite_;
}
//! @brief - Ładuje klatki animacji chodzenia postaci.
//! @param path - Ścieżka do plików z klatkami.
void AnimatedCharacter::loadWalkFrames(const std::string& path) {
    for (int i = 0; i < 10; ++i) {
        walkFrames_.push_back(path + std::to_string(i) + ".png");
    }
}
//! @brief - Ładuje klatki animacji bezruchu postaci.
//! @param path - Ścieżka do plików z klatkami.
//! W przypadku gdy lista klatek nie jest pusta, ładuje pierwszą klatkę jako teksturę postaci.
void AnimatedCharacter::loadIdleFrames(const std::string& path) {
    for (int i = 0; i < 8; ++i) {
        idleFrames_.push_back(path + std::to_string(i) + ".png");
    }
    if (!idleFrames_.empty()) {
        characterTexture_.loadFromFile(idleFrames_[0]);
        characterSprite_.setTexture(characterTexture_);
    }
}

void AnimatedCharacter::move(float deltaX, float deltaY) {
    characterSprite_.move(deltaX, deltaY);
    setWalking(true);
}
//! @brief - Przesuwa postać w górę.
void AnimatedCharacter::moveUp() {
    move(0.0f, -3.0f);
}
//! @brief - Przesuwa postać w górę z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
void AnimatedCharacter::moveUp(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, -scaledSpeed);
}
//! @brief - Przesuwa postać w dół.
void AnimatedCharacter::moveDown() {
    move(0.0f, 3.0f);
}
//! @brief - Przesuwa postać w dół z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
void AnimatedCharacter::moveDown(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(0.0f, scaledSpeed);
}
//! @brief - Przesuwa postać w lewo.
//! Dodatkowo odwraca postać w lewo.
void AnimatedCharacter::moveLeft() {
    move(-3.0f, 0.0f);
    flipLeft();
}
//! @brief - Przesuwa postać w lewo z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
//! Dodatkowo odwraca postać w lewo.
void AnimatedCharacter::moveLeft(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(-scaledSpeed, 0.0f);
    flipLeft();
}
//! @brief - Przesuwa postać w prawo.
//! Dodatkowo odwraca postać w prawo.
void AnimatedCharacter::moveRight() {
    move(3.0f, 0.0f);
    flipRight();
}
//! @brief - Przesuwa postać w prawo z określoną prędkością.
//! @param speed - Prędkość przesunięcia, skalowana od 0 do 100.
//! Dodatkowo odwraca postać w prawo.
void AnimatedCharacter::moveRight(float speed) {
    if(speed < 0) speed = 0;
    if(speed > 100) speed = 100;
    float scaledSpeed = (speed / 100.0f) * 10.0f;
    move(scaledSpeed, 0.0f);
    flipRight();
}
//! @brief - Odwraca postać w lewo.
void AnimatedCharacter::flipLeft() {
    characterSprite_.setScale(-1.f, 1.f);
}
//! @brief - Odwraca postać w prawo.
void AnimatedCharacter::flipRight() {
    characterSprite_.setScale(1.f, 1.f);
}