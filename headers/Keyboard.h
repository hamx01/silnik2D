//
// Created by asoli on 23.04.2024.
//

#ifndef SILNIK2D_KEYBOARD_H
#define SILNIK2D_KEYBOARD_H

#include "SFML/Graphics.hpp"
//! @class Keyboard
//! @brief Klasa statyczna do sprawdzania stanu klawiszy klawiatury.
class Keyboard {
public:
    //! @brief - Sprawdza, czy dany klawisz jest aktualnie naciśnięty.
//! @param key - Klawisz, którego stan ma być sprawdzony.
//! @return true - jeśli klawisz jest naciśnięty, false - w przeciwnym przypadku.
    static bool isKeyPressed(sf::Keyboard::Key key);
};

#endif //SILNIK2D_KEYBOARD_H
