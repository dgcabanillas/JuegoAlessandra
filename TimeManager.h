#ifndef JUEGO_BOMBERMAN___POO_TIMEMANAGER_H
#define JUEGO_BOMBERMAN___POO_TIMEMANAGER_H


#include <SFML/System/Clock.hpp>

///Clase que nos sirve como el reloj del juego
///Nos permite ajustar el tiempo
class TimeManager
{
public:
    TimeManager ();

    ///Establece la velocidad
    void setSpeed (float speed);

    ///Pausa el reloj, si esta en pause devuelve un mensaje de error
    void pause ();

    ///Reanuda el reloj, si ya se reaudo, manda un mensaje de advertencia
    void resume ();

    sf::Time getTime () const;

    bool isPaused () const;

private:
    ///Actualiza el valor de la hora
    void update ();

private:
    float _speed; ///Garzantiza > 0.f
    bool _paused;

    sf::Clock _clock;
    sf::Time _time; ///Valor de la hora
};


#endif //JUEGO_BOMBERMAN___POO_TIMEMANAGER_H
