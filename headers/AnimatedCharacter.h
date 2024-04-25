#ifndef SILNIK2D_ANIMATEDCHARACTER_H
#define SILNIK2D_ANIMATEDCHARACTER_H

#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;
//! @class AnimatedCharacter
//! @brief Klasa zarządzająca animowaną postacią w grze 2D.
class AnimatedCharacter {
public:
    //! @brief - Konstruktor inicjujący postać w zadanej pozycji.
    //! @param posX - Początkowa pozycja X postaci.
    //! @param posY - Początkowa pozycja Y postaci.
    AnimatedCharacter(float posX, float posY);
    //! @brief - Aktualizuje stan animacji postaci.
    void update();
//! @brief - Ustawia stan ruchu postaci.
    //! @param isWalking - Ustaw true, aby postać chodziła, false aby
    void setWalking(bool isWalking);
//! @brief - Zwraca sprite postaci.
//! @return Referencja do sprite'a postaci.
    sf::Sprite& getSprite();
//! @brief - Ładuje klatki animacji chodzenia postaci.
//! @param path - Ścieżka do katalogu z klatkami animacji.
    void loadWalkFrames(const string &path);
//! @brief - Ładuje klatki animacji spoczynku postaci.
//! @param path - Ścieżka do katalogu z klatkami animacji.
    void loadIdleFrames(const string &);

    void move(float deltaX, float deltaY);

    void moveUp();

    void moveUp(float speed);

    void moveDown();

    void moveDown(float speed);

    void moveLeft();

    void moveLeft(float speed);

    void moveRight();

    void moveRight(float speed);

    void flipLeft();

    void flipRight();
private:
    std::vector<std::string> walkFrames_; //!< - Wektor ścieżek do klatek animacji chodzenia.
    std::vector<std::string> idleFrames_;//!< - Wektor ścieżek do klatek animacji spoczynku.
    sf::Sprite characterSprite_;  //!< - Sprite postaci.
    sf::Texture characterTexture_; //!< - Tekstura postaci.
    sf::Clock animationClock_;//!< - Zegar do zarządzania czasem animacji.
    sf::Time frameDuration_;//!< - Czas trwania jednej klatki.
    int currentFrameIndex_;//!< - Indeks bieżącej klatki animacji.
    bool isWalking_{};//!< - Flaga określająca, czy postać chodzi.
};

#endif //SILNIK2D_ANIMATEDCHARACTER_H
