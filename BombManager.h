#ifndef JUEGO_BOMBERMAN___POO_BOMBMANAGER_H
#define JUEGO_BOMBERMAN___POO_BOMBMANAGER_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <list>
#include <map>

#include "TimeManager.h"
#include "Constants.h"

class FireManager;
class BombManager: public sf::Drawable
{
private:
    ///Esta estructura debe declararse aqui porque el uso del std::map y std::list
    struct PlayerProfile {
        unsigned int bombForce;
        bool autoDestruction;
    };

    struct Bomb {
        const unsigned int line, col;
        const PlayerId player;
        const sf::Time birthtime;
    };

public:
    ///Envia un mensaje de error si no se pudieron crear los recursos
    BombManager (TimeManager const& timeManager, FireManager& fireManager);

    ///Agrega una bomba al controlador
    ///Como máximo se debe tener una bomba
    void putBomb (PlayerId player, unsigned int line, unsigned int col);

    ///Devuelve si existe o no una bomba en la ubicacion dada
    bool isThereABomb (unsigned int line, unsigned int col) const;

    ///Si existe una bomba en la posicion dada, la destruye
    void destroy (unsigned int line, unsigned int col);

    ///Destruye todas las bombas que pertenecen al jugador dado
    void destroy (PlayerId player);

    ///Se declara un ID del jugador
    void addPlayerProfile (PlayerId player, unsigned int bombForce, bool autoDestruction);
    void setAutoDestruction (PlayerId player, bool activation);
    void setBombForce (PlayerId player, unsigned int force);

    ///Retorna el numero de bombas que posee el jugador actualmente en el mapa
    unsigned int getNbBomb (PlayerId player) const;

    void update ();

private:
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;

    ///Elimina la bomba de la lista y crea una explosion
    std::list<Bomb>::iterator destroy (std::list<Bomb>::iterator bomb);

private:
    TimeManager const& _timeManager;

    FireManager& _fireManager;

    std::map<PlayerId, PlayerProfile> _profiles;
    std::list<Bomb> _bombs;

    sf::Texture _spriteSheet;
};


#endif //JUEGO_BOMBERMAN___POO_BOMBMANAGER_H
