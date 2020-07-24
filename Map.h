#ifndef JUEGO_BOMBERMAN___POO_MAP_H
#define JUEGO_BOMBERMAN___POO_MAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <vector>
#include <memory>

#include "TimeManager.h"
#include "ExplodingBrickManager.h"
#include "FireManager.h"
#include "BombManager.h"

///Nos permite generar el mundo donde interactuan los jugadores
///Almacena el terreno (roca, ladrillo, vacio)
///Potenciadores, bombas, explosiones
///Se actualiza a medida que cambia el mapa
class Map: public sf::Drawable
{
public:
    ///Roca: No se puede destruir
    ///Ladrillo: Se puede destruir
    ///El orden de importa
    enum class Terrain {ROCK=0, BRICK=1, EMPTY=2};
    enum class PowerUp {BOMB=0, BLAST=1, REMOTE=2, NONE=3};

public:
    ///Error si los recursos no se pueden cargar
    Map (TimeManager const& timeManager, sf::Image const& grid,
         unsigned int nbBombsBonus=20, unsigned int nbBlastBonus=20, unsigned int nbRemoteBonus=7);

    void update ();

    unsigned int getNbLines () const;
    unsigned int getNbCol () const;

    BombManager& getBombManager ();

    ///Devuelve el terreno solicitado, si las coodenadas estan fuera del maoa, se devuele roca
    Terrain getTerrain (unsigned int line, unsigned int col) const;

    ///Devuelve algun potenciador, si no esta dentro de las coordenadas devuelve NONE
    PowerUp getPowerUp (unsigned int line, unsigned int col) const;

    ///Devuelve si se puede o no transitar por un mosaico
    bool isWalkable (unsigned int line, unsigned int col) const;

    ///Devuelve si el espacio es letal o no
    bool isLethal (unsigned int line, unsigned int col) const;

    ///Quema un bloque y desencadena una explosion de bomba
    ///Destruye Terreno Brick y potenciador
    void burnTile (unsigned int line, unsigned int col);

    ///Elimina el bono del mapa y lo devuelve
    PowerUp pickBonus (unsigned int line, unsigned int col);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    ///Convierte coordenadas 2D en índice 1D, para usar en _grid
    ///Dado que la cuadrícula se almacena en una matriz 1D, necesitamos un método de conversión.
    ///NO comprueba si el punto está fuera de la red o no.
    unsigned int index (unsigned int line, unsigned int col) const;

    ///Actualiza la textura del búfer fuera de la pantalla.
    ///Esta textura solo debe actualizarse cuando se actualiza el mapa
    void updateBufferTexture ();

private:
    TimeManager const& _timeManager;

    unsigned int _nbLines, _nbCol;
    struct Tile {
        Terrain type;
        PowerUp powerUp;
    };
    std::vector<Tile> _grid;

    std::unique_ptr<ExplodingBrickManager> _explodingBricks;
    std::unique_ptr<FireManager> _fireManager;
    std::unique_ptr<BombManager> _bombManager;

    sf::Texture       _spriteSheetTerrain;
    sf::Texture       _spriteSheetPowerup;
    sf::RenderTexture _bufferTexture;
};



#endif //JUEGO_BOMBERMAN___POO_MAP_H
