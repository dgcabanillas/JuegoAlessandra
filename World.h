#ifndef JUEGO_BOMBERMAN___POO_WORLD_H
#define JUEGO_BOMBERMAN___POO_WORLD_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

#include <string>
#include <memory>
#include <array>

#include "TimeManager.h"
#include "Map.h"
#include "Player.h"

///Clase de nivel superio que aloja el mapa y los jugadores
class World: public sf::Drawable
{
public:
    World (std::string const& gridPath);

    unsigned int widthInPixels () const;
    unsigned int heightInPixels () const;

    void update ();

    void manageEvents (sf::Event const& event);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    TimeManager _timeManager;

    std::unique_ptr<Map> _map;
    std::array<std::unique_ptr<Player>, 2> _players;
};


#endif //JUEGO_BOMBERMAN___POO_WORLD_H
