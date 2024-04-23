//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_ANIMATEDCHARACTER_H
#define SILNIK2D_ANIMATEDCHARACTER_H

#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;

class AnimatedCharacter {
public:
    AnimatedCharacter(std::vector<std::string> walkFrames, std::vector<std::string> idleFrames, float posX, float posY)
            : walkFrames_(std::move(walkFrames)), idleFrames_(std::move(idleFrames)) {
        currentFrameIndex_ = 0;
        frameDuration_ = sf::seconds(0.1f);
        animationClock_.restart();

        characterSprite_.setPosition(posX, posY);
        // Wczytaj pierwszą klatkę animacji (idle)
        if (!idleFrames_.empty()) {
            characterTexture_.loadFromFile(idleFrames_[0]);
            characterSprite_.setTexture(characterTexture_);
        }
    }

    void update() {
        // Sprawdź, czy czas upłynął, aby przejść do kolejnej klatki animacji
        if (animationClock_.getElapsedTime() >= frameDuration_) {
            // Wybierz odpowiedni zestaw klatek animacji
            const std::vector<std::string>& frames = isWalking_ ? walkFrames_ : idleFrames_;
            // Przełącz na kolejną klatkę animacji
            currentFrameIndex_ = int((currentFrameIndex_ + 1) % frames.size());
            characterTexture_.loadFromFile(frames[currentFrameIndex_]);
            characterSprite_.setTexture(characterTexture_);
            // Zresetuj zegar animacji
            animationClock_.restart();
        }
    }

    void setWalking(bool isWalking) {
        isWalking_ = isWalking;
    }

    sf::Sprite& getSprite() {
        return characterSprite_;
    }

private:
    std::vector<std::string> walkFrames_;
    std::vector<std::string> idleFrames_;
    sf::Sprite characterSprite_;
    sf::Texture characterTexture_;
    sf::Clock animationClock_;
    sf::Time frameDuration_;
    int currentFrameIndex_;
    bool isWalking_{};
};

#endif //SILNIK2D_ANIMATEDCHARACTER_H
