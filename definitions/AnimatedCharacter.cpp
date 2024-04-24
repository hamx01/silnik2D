#include "../headers/AnimatedCharacter.h"

AnimatedCharacter::AnimatedCharacter(std::vector<std::string> walkFrames, std::vector<std::string> idleFrames, float posX, float posY)
: walkFrames_(std::move(walkFrames)), idleFrames_(std::move(idleFrames)) {
    currentFrameIndex_ = 0;
    frameDuration_ = sf::seconds(0.1f);
    animationClock_.restart();

    characterSprite_.setPosition(posX, posY);
    if (!idleFrames_.empty()) {
        characterTexture_.loadFromFile(idleFrames_[0]);
        characterSprite_.setTexture(characterTexture_);
    }
}

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

void AnimatedCharacter::setWalking(bool isWalking) {
    isWalking_ = isWalking;
}

sf::Sprite& AnimatedCharacter::getSprite() {
    return characterSprite_;
}