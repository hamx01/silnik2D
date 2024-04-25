//
// Created by Michał Wojtachnio, Artur Szymkiewicz, Łukasz Tomczyk, Andrii Solianyk
//

#include "../headers/Keyboard.h"
//! @brief - Sprawdza, czy dany klawisz jest naciśnięty.
//! @param key - Klawisz do sprawdzenia.
//! @return true - Jeżeli klawisz jest naciśnięty.
//! @return false - Jeżeli klawisz nie jest naciśnięty.
bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);

}
