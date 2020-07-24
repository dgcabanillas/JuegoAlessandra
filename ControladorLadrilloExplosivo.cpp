//
// Created by hp on 22/07/2020.
//

#include "ControladorLadrilloExplosivo.h"

#include "Constante.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <stdexcept>
#include <sstream>

ControladorLadrilloExplosivo::ControladorLadrilloExplosivo(ControladorTiempo const& controladorTiempo ) :
        _controladorTiempo(controladorTiempo),
        _ladrillo(),
        _hojaSprites()
{
    //Pido imagen ladrillo_explosivo de la carpeta imagenesBomberman
    std::string ruta = "imagenesBomberman/ladrillo_explosivo.png";
    if (!_hojaSprites.loadFromFile(ruta)){

        //ostringstream nos permite ...
        std::ostringstream oss;
        oss << "Error: No se puede cargar"<<ruta
            << "(ControladorLadrilloExplosivo::ControladorLadrilloExplosivo)";

        //throw permite ...
        throw std::runtime_error(oss.str());
    }
}

void ControladorLadrilloExplosivo::addLadrillo(unsigned int fila, unsigned int columna) {
    _ladrillo.push_back(LadrilloExplosivo{fila,columna, _controladorTiempo.getTiempo()});
}

void ControladorLadrilloExplosivo::actualizar() {
    const sf::Time time = _controladorTiempo.getTiempo();

    auto  it = _ladrillo.begin();
    while (it != _ladrillo.end()){
        if (time - it->horainicio > tiempo_vida_explosion_bloques)
            it = _ladrillo.erase(it);
        else
            ++it;
    }
}

void ControladorLadrilloExplosivo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite sprite(_hojaSprites);

    for (LadrilloExplosivo const& ladrillo : _ladrillo ){
        int dt = (_controladorTiempo.getTiempo() - ladrillo.horainicio).asMicroseconds();
        int tiempovida = tiempo_vida_explosion_bloques.asMilliseconds();
        int i = std::min(3*dt / tiempovida, 2);

        sprite.setTextureRect(sf::IntRect(i*tamaño_bloques,0,tamaño_bloques, tamaño_bloques));
        sprite.setPosition(ladrillo.columna*tamaño_bloques, ladrillo.fila*tamaño_bloques);
        target.draw(sprite, states);
    }
}