#ifndef JUEGO_BOMBERMAN___POO_PLAYER_H
#define JUEGO_BOMBERMAN___POO_PLAYER_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include <array>
#include <string>

#include "TimeManager.h"
#include "Map.h"
#include "Constants.h"
#include "PlayerKeyBinding.h"

///Esta clase maneja el mapa y el jugador
///Cada jugador tiene un ID unico
class Player: public sf::Drawable
{
public:
    ///Error en caso los recursos no se puedan cargar
    Player (PlayerId id, TimeManager const& timeManager, Map& map,
            PlayerKeyBinding const& keys, std::string const& spritesPath,
            int line, int col,
            unsigned int blast=1, unsigned int maxBombs=1, bool hasRemote=false);

    void update ();

    void manageEvents (sf::Event const& event);

    void getTile (int& line, int& col) const;

    void die ();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    ///Se localiza en el centro del bloque
    void center (unsigned int &left);

    ///Ajusta dX para que esté dentro del rango
    void adjust (int& nX, int& dX);

    ///Selecciona la bonificacion que tiene el mapa
    void pickBonus ();

private:
    TimeManager const& _timeManager;
    Map& _map;
    const PlayerKeyBinding _keys;
    const PlayerId _id;

    sf::Time _lastUpdate;
    bool     _isDead;
    unsigned int _animationStep; ///
    sf::Texture _spriteSheet;

    int _nLine, _nCol; ///Anima el caminar del jugador
    int _dLine, _dCol; ///Posicon en el bloque

    bool _isRunning;
    Dir _currDir, _nextDir;

    ///Bonificaciones
    unsigned int _blastForce;
    unsigned int _maxBombs;
    bool _hasRemote;
};


#endif //JUEGO_BOMBERMAN___POO_PLAYER_H
