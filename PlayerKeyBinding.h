#ifndef JUEGO_BOMBERMAN___POO_PLAYERKEYBINDING_H
#define JUEGO_BOMBERMAN___POO_PLAYERKEYBINDING_H


#include <SFML/Window/Keyboard.hpp>

#include "Constants.h"

///Esta estrucutura nos permite almacenar las combinaciones de teclas
struct PlayerKeyBinding {
    sf::Keyboard::Key left;
    sf::Keyboard::Key up;
    sf::Keyboard::Key right;
    sf::Keyboard::Key down;

    sf::Keyboard::Key placeBomb;
    sf::Keyboard::Key remote;

    ///Muestra si key esta asociada a una direccion
    bool isDirectionnalKey (sf::Keyboard::Key key) const
    {
        return (key == up) || (key == right) || (key == down) || (key == left);
    }

    ///Devuelve la direccion asociada a la tecla
    Dir getDirection (sf::Keyboard::Key key) const
    {
        if (key == up)
            return Dir::UP;
        if (key == right)
            return Dir::RIGHT;
        if (key == down)
            return Dir::DOWN;
        return Dir::LEFT;
    }
};

#endif //JUEGO_BOMBERMAN___POO_PLAYERKEYBINDING_H
