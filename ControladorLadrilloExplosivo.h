//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_CONTROLADORLADRILLOEXPLOSIVO_H
#define BOMBERMAN_CONTROLADORLADRILLOEXPLOSIVO_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

//<list> nos permite ...
#include <list>

#include "ControladorTiempo.h"


//Esta clase nos permite gestionar la animacion de los ladrillos explosivos
//Posee una referencia a un TimeManager
class ControladorLadrilloExplosivo : public sf::Drawable {
private:
    ControladorTiempo const & _controladorTiempo;

    struct LadrilloExplosivo{
        const unsigned int fila, columna;
        const sf::Time horainicio;
    };
    std::list<LadrilloExplosivo> _ladrillo;

    sf::Texture _hojaSprites;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const ;

public:

    //Manda error si no se pudieron cargar los recursos
    ControladorLadrilloExplosivo(ControladorTiempo const & controladorTiempo);

    void addLadrillo (unsigned int fila, unsigned int columna);

    //Elimina los ladrillos antiguuos
    void actualizar();

};


#endif //BOMBERMAN_CONTROLADORLADRILLOEXPLOSIVO_H
