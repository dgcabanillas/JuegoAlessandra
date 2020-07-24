#ifndef JUEGO_BOMBERMAN___POO_FIRE_H
#define JUEGO_BOMBERMAN___POO_FIRE_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <array>

#include "TimeManager.h"

///La explosion de la bomba se propaga en cuatro direcciones distintas
///Tiene una velocidad determinada
///Permanece un cierto tiempo despues de la explosion
///Mantiene una referencia con TimeManager, mapa y textura

class Map;
class Fire: public sf::Drawable
{
public:
    Fire (TimeManager const& timeManager, Map& map, sf::Texture const& spriteSheet,
          int oLine, int oCol, unsigned int force);

    ///Difunde la explosion si se extiende en una direccion
    bool spread ();

    ///Nos dice si el fuego se extendio por completo o no
    bool shouldBeDeleted () const;

    ///Nos dice si la ubicacion del objeto esta dentro o no del rango de explosion
    bool isOnFire (int line, int col) const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    bool isFullySpread () const;

private:
    TimeManager const& _timeManager;
    Map& _map;

    const int _oLine, _oCol; ///Origina el fuego
    const int _force; ///Longitud maxima de la onda explosiva
    sf::Time _lastUpdate;

    struct Branch {
        int length;
        bool fullySpread;///Verdadero, cuando el fuego ya no puede extenderse mas
    };
    std::array<Branch, 4> _branches;

    sf::Texture const& _spriteSheet;
};


#endif //JUEGO_BOMBERMAN___POO_FIRE_H
