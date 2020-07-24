//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_CONTROLADORBOMBA_H
#define BOMBERMAN_CONTROLADORBOMBA_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <list>
#include <map>

#include "ControladorTiempo.h"
#include "Constante.h"


class ControladorFuego;
class ControladorBomba: sf::Drawable {
private:

    //Estas estructuras se deben declarar aqui por std::map y std::list
    //No es compatible con la declaración directa
    struct PerfilJugador{
        unsigned int fuerzaBomba;
        bool autoDestruccion;
    };

    struct Bomba{
        const unsigned int fila, columna;
        const IDJugador jugador;
        const sf::Time horainicio;
    };

public:
    //Error en caso no se pueda cargar los recursos
    ControladorBomba(ControladorTiempo const& controladorTiempo, ControladorFuego& controladorFuego);

    //Permite agregar una bomba
    //Una bomba como maximo por posicion(fila,columna)
    void ponerBomba (IDJugador jugador, unsigned int fila, unsigned int columna);

    //Devuelve si existe o no una bomba en la ubicación dada
    bool hayUnaBomba (unsigned int fila, unsigned int columna) const ;

    //Si existe una bomba en la posición dada, la destruye.
    void destruir (unsigned int fila, unsigned int columna);

    //Destruye todas las bombas que pertenecen al jugador dado.
    void destruir (IDJugador jugador);

    //Declaracion de IDJugador
    void addPerfilJugador (IDJugador jugador, unsigned int fuerzaBomba, bool autoDestruccion);
    void setAutoDestruccion (IDJugador jugador, bool activacion);
    void setFuerzaBomba (IDJugador jugador, unsigned int fuerza);

    //Retorna el numero de bombas que posee el jugador en el mapa
    unsigned int getNbBomba (IDJugador jugador) const;

    void actualizar();

private:
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;

    //Elimina la bomba de la lista y crea una explosión
    std::list<Bomba>::iterator destruir (std::list<Bomba>::iterator bomba);

private:
    ControladorTiempo const& _controladorTiempo;

    ControladorFuego _controladorFuego;

    std::map<IDJugador, PerfilJugador> _perfil;
    std::list<Bomba> _bomba;

    sf::Texture _hojaSprite;


};


#endif //BOMBERMAN_CONTROLADORBOMBA_H
