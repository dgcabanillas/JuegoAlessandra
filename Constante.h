//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_CONSTANTE_H
#define BOMBERMAN_CONSTANTE_H

#include <SFML/System/Time.hpp>
#include <array>  //Permite tener matrices de tamaño fijo

//Valores constantes
const int tamaño_bloques = 32;
const sf::Time duracion_potenciadores = sf::milliseconds(130);
const sf::Time tiempo_vida_explosion_bloques = sf::milliseconds(200);
const sf::Time tiempo_vida_bomba = sf::milliseconds(2000); //Tiempo antes de que la bomba se autodestruya
const sf::Time tiempo_vida_fuego = sf::milliseconds(1000); //Duracion de la extension del fuego
const sf::Time velocidad_fuego = sf::milliseconds(40); //Tiempo de extension a traves de los bloques
const sf::Time velocidad_jugador = sf::milliseconds(7);//Tiempo para caminar por pixel
const sf::Time animacion_muerte = sf::milliseconds(800);

//Tipo de dato
typedef int IDJugador;

//El orden de esta parte de codigo es importante para poder mostrar la pantalla, etc.
//enum es un tipo de dato que permite que el valor del rango sea constante
//Dir es un comando que permite mostrar archivos y subcarptas, aqui solo se usa como un nombre de referencia
enum class Dir {LEFT, UP, RIGHT, DOWN};
const std::array<int,4> D_Fila = {+0,-1,+0,+1};
const std::array<int,4> D_Columna = {-1,+0,+1,+0};


//inlin indica al compilador que cada llamado a la función inline deberá ser reemplazado por el cuerpo de esta función
inline bool SonDireccionesOpuestas(Dir D1, Dir D2){
    if ((D1 == Dir::LEFT && D2 == Dir::RIGHT) || (D1 == Dir::RIGHT && D2 == Dir::LEFT))
        return true;
    if ((D1 == Dir::UP && D2 == Dir::DOWN) || (D1 == Dir::DOWN && D2 == Dir::UP))
        return true;
    return false;
}



#endif //BOMBERMAN_CONSTANTE_H
