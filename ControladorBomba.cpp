//
// Created by hp on 22/07/2020.
//

#include "ControladorBomba.h"

#include "Constante.h"
#include "ControladorFuego.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cassert>
#include <sstream>
#include <stdexcept>

ControladorBomba::ControladorBomba(ControladorTiempo const& controladorTiempo, ControladorFuego& controladorFuego ):
            _controladorTiempo(controladorTiempo),
            _controladorFuego(controladorFuego),
            _perfil(),
            _bomba(),
            _hojaSprite()
{
    //Pido imagen ladrillo_explosivo de la carpeta imagenesBomberman
    std::string ruta = "imagenesBomberman/bomba.png";
    if (!_hojaSprite.loadFromFile(ruta)){
        std::ostringstream oss;
        oss << "Error: No se puede cargar"<<ruta
            << "(ControladorBomba::ControladorBomba)";
        throw std::runtime_error (oss.str());
    }
}

void ControladorBomba::ponerBomba(IDJugador jugador, unsigned int fila, unsigned int columna) {
    //IDJugador debe haberse declarado en ControladorBomba :: addPerfilJugador
    assert(_perfil.find(jugador) != _perfil.end());

    //Maximo 1 bomba por bloque
    if (hayUnaBomba(fila, columna))
        return;

    _bomba.push_back(Bomba{fila, columna, jugador, _controladorTiempo.getTiempo()});
}

bool ControladorBomba::hayUnaBomba(unsigned int fila, unsigned int columna) const {
    for (Bomba const& bomba : _bomba) {
        if (bomba.fila== fila && bomba.columna == columna)
            return true;
    }
    return false;
}

void ControladorBomba:: destruir(unsigned int fila, unsigned int columna) {

    //Como sabemos, hay como máximo 1 bomba en la ubicación dada,si hemos encontrado uno, no hay necesidad de buscar otros
    for (auto itBomb = _bomba.begin() ; itBomb != _bomba.end() ; ++itBomb) {
        if (itBomb->fila == fila && itBomb->columna == columna) {
            destruir(itBomb);
            return;
        }
    }
}

void ControladorBomba::destruir(IDJugador jugador) {

    //IDJugador debe haberse declarado en ControladorBomba :: addPerfilJugador
    assert (_perfil.find(jugador) != _perfil.end());

    auto itBomb = _bomba.begin();
    while (itBomb != _bomba.end()) {
        if (itBomb->jugador == jugador)
            itBomb = destruir(itBomb);
        else
            ++itBomb;
    }
}

void ControladorBomba::addPerfilJugador(IDJugador jugador, unsigned int fuerzaBomba, bool autoDestruccion) {

    //IDJugador solo se puede declarar una vez
    assert (_perfil.find(jugador) == _perfil.end());

    _perfil.emplace (jugador, PerfilJugador{fuerzaBomba, autoDestruccion});
}

void ControladorBomba::setAutoDestruccion(IDJugador jugador, bool activacion) {
    auto itProfile = _perfil.find (jugador);

    //
    assert (itProfile != _perfil.end());

    itProfile->second.autoDestruccion = activacion;
}

void ControladorBomba::setFuerzaBomba(IDJugador jugador, unsigned int fuerza) {
    auto itProfile = _perfil.find (jugador);

    //
    assert (itProfile != _perfil.end());

    itProfile->second.fuerzaBomba = fuerza;
}

unsigned int ControladorBomba::getNbBomba(IDJugador jugador) const {
    unsigned int counter = 0;
    for (Bomba const& bomb : _bomba) {
        if (bomb.jugador == jugador)
            ++counter;
    }
    return counter;
}

void ControladorBomba::actualizar() {
    const sf::Time time = _controladorTiempo.getTiempo();

    auto itBomb = _bomba.begin();
    while ( itBomb != _bomba.end() ) {
        auto itProfile = _perfil.find (itBomb->jugador);

        //
        assert (itProfile != _perfil.end());

        bool autoDestruction = itProfile->second.autoDestruccion;

        if (autoDestruction && time - itBomb->horainicio > tiempo_vida_bomba)
            itBomb = destruir(itBomb);
        else
            ++itBomb;
    }
}

void ControladorBomba::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite (_hojaSprite);
    unsigned int step = (_controladorTiempo.getTiempo().asMilliseconds() / duracion_potenciadores.asMilliseconds()) % 4;
    step = std::min(step, 4-step);

    sprite.setTextureRect (sf::IntRect(step*tamaño_bloques, 0*tamaño_bloques, tamaño_bloques, tamaño_bloques));

    for (Bomba const& bomb : _bomba) {
        sprite.setPosition (bomb.columna*tamaño_bloques, bomb.fila*tamaño_bloques);
        target.draw (sprite, states);
    }
}

std::list<ControladorBomba::Bomba>::iterator ControladorBomba::destruir(std::list<Bomba>::iterator itBomb)
{
    auto itProfile = _perfil.find (itBomb->jugador);
    assert (itProfile != _perfil.end());

    int force = itProfile->second.fuerzaBomba;
    _controladorFuego.addFire (itBomb->fila, itBomb->columna, force);

    return _bomba.erase (itBomb);
}









































