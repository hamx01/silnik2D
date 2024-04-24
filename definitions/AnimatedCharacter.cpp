#include "../headers/AnimatedCharacter.h"

AnimatedCharacter::AnimatedCharacter(float posX, float posY) {
    currentFrameIndex_ = 0;
    frameDuration_ = sf::seconds(0.1f);
    animationClock_.restart();

    characterSprite_.setPosition(posX, posY);
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

void AnimatedCharacter::loadWalkFrames(const std::string& path) {
    for (int i = 0; i < 10; ++i) {
        walkFrames_.push_back(path + std::to_string(i) + ".png");
    }
}

void AnimatedCharacter::loadIdleFrames(const std::string& path) {
    for (int i = 0; i < 8; ++i) {
        idleFrames_.push_back(path + std::to_string(i) + ".png");
    }
    if (!idleFrames_.empty()) {
        characterTexture_.loadFromFile(idleFrames_[0]);
        characterSprite_.setTexture(characterTexture_);
    }
}
