//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_TECLAS_H
#define BOMBERMAN_TECLAS_H

#include <SFML/Window/Keyboard.hpp>

#include "Constante.h"

//struct nos permite almacenar las combinaciones de teclas
struct Teclas{
    sf::Keyboard::Key izquierda;
    sf::Keyboard::Key arriba;
    sf::Keyboard::Key derecha;
    sf::Keyboard::Key abajo;

    sf::Keyboard::Key lugarBomba;
    sf::Keyboard::Key remoto;

    //Verifica si la clave esta asociada o no a una accion direccional
    bool TeclasDireccional (sf::Keyboard::Key key) const{
        return (key == arriba) || (key == derecha)|| (key == abajo)|| (key == izquierda);
    }

    //Retorna la direccion asociada a key
    Dir getDireccion (sf::Keyboard::Key key) const{
        if (key == arriba)
            return Dir::UP;
        if (key == derecha)
            return Dir::RIGHT;
        if (key == abajo)
            return Dir::DOWN;
        return Dir::LEFT;
    }


};


#endif //BOMBERMAN_TECLAS_H
