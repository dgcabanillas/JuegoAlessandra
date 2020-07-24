#ifndef JUEGO_BOMBERMAN___POO_CONSTANTS_H
#define JUEGO_BOMBERMAN___POO_CONSTANTS_H


#include <SFML/System/Time.hpp>

#include <array>

///Constantes
const int TILE_SIZE = 32;

const sf::Time POWERUP_ANIMATION_STEP = sf::milliseconds (130);

const sf::Time EXPLODING_BRICK_LIFETIME = sf::milliseconds (200);

const sf::Time BOMB_LIFETIME = sf::milliseconds(2000);///Tiempo antes de la autodestruccion

const sf::Time FIRE_LIFETIME = sf::milliseconds(1000); ///Duracion del fuego una vez expandido
const sf::Time FIRE_SPEED = sf::milliseconds(40); ///Tiempo que demora en extenderse por los bloques

const sf::Time PLAYER_SPEED = sf::milliseconds(7); ///Velocidad del jugador al caminar por los pixeles
const sf::Time DEATH_ANIMATION_STEP = sf::milliseconds(800);


///Tipo de dato
typedef int PlayerId;

///Ell orden que se coloca es importante para una correcta identificacion en el mapa
enum class Dir {LEFT, UP, RIGHT, DOWN};
const std::array<int, 4> D_LINE = {+0, -1, +0, +1};
const std::array<int, 4> D_COL  = {-1, +0, +1, +0};

inline bool areOpposedDirections (Dir D1, Dir D2)
{
    if ((D1 == Dir::LEFT && D2 == Dir::RIGHT) || (D1 == Dir::RIGHT && D2 == Dir::LEFT))
        return true;
    if ((D1 == Dir::UP && D2 == Dir::DOWN) || (D1 == Dir::DOWN && D2 == Dir::UP))
        return true;
    return false;
}


#endif //JUEGO_BOMBERMAN___POO_CONSTANTS_H
