#ifndef SILNIK2D_ANIMATEDCHARACTER_H
#define SILNIK2D_ANIMATEDCHARACTER_H

#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;

class AnimatedCharacter {
public:
    AnimatedCharacter(float posX, float posY);

    void update();

    void setWalking(bool isWalking);

    sf::Sprite& getSprite();

    void loadWalkFrames(const string &path);

    void loadIdleFrames(const string &);
private:
    static AnimatedCharacter character;
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
