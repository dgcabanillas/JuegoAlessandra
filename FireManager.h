#ifndef JUEGO_BOMBERMAN___POO_FIREMANAGER_H
#define JUEGO_BOMBERMAN___POO_FIREMANAGER_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>

#include <list>

#include "TimeManager.h"
#include "Fire.h"

///Maneja las explosiones (poder ver el fuego) en el mapa
///De inicio a fin
///Se debe mantener una referencias con TimeManager
class Map;
class FireManager: public sf::Drawable
{
public:
    ///Envia mensaje de error si los recursos no se pudieron cargar
    FireManager (TimeManager const& timeManager, Map& map);

    ///Agrega fuego en el mapa, crece la extgension de la explosion
    void addFire (int line, int col, unsigned int force);

    ///Difunde el fuego y destrue los viejos
    void update ();

    ///Indica si la posicion esta o no, dentro del rango de explosion
    bool isOnFire (int line, int col) const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void updateBufferTexture ();

private:
    TimeManager const& _timeManager;
    Map& _map;

    std::list<Fire> _fires;

    sf::Texture _spriteSheet;
    sf::RenderTexture _bufferTexture;
};




#endif //JUEGO_BOMBERMAN___POO_FIREMANAGER_H
