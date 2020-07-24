//
// Created by hp on 22/07/2020.
//

#include "ControladorTiempo.h"
#include <iostream>

ControladorTiempo::ControladorTiempo() :
    _velocidad (1.f),
    _pausar (false),
    _reloj (),
    _tiempo ()
{
}

void ControladorTiempo::setVelocidad(float velocidad) {
    if (velocidad > 0.f){
        actualizar();
        _velocidad = velocidad;
    } else{

        //El dispositivo estándar para mensajes de error es el cerr, y el mismo está asociado por defecto con la pantalla o monitor de despliegue
        std::cerr<<"Advertencia (ControladorTiempo::setVelocidad): valor incorrecto"
                 << "(" << velocidad << ")" << std::endl;
    }
}

void ControladorTiempo::pausa() {
    if (!_pausar) {
        actualizar();
        _pausar = true;
    } else {
        std::cerr << "Advertencia (ControladorTiempo::pausa): ya esta en pausa " << std::endl;
    }
}

void ControladorTiempo::reanudar() {
    if (!_pausar) {
        actualizar();
        _pausar = false;
    } else {
        std::cerr << "Advertencia (ControladorTiempo::pausa): ya esta ejecutandose" << std::endl;
    }
}


sf::Time ControladorTiempo::getTiempo() const {
    if (_pausar)
        return _tiempo;

    //getElapsedTime permite obtener el tiempo transcurrido
    return _tiempo + _reloj.getElapsedTime() * _velocidad;
}

bool ControladorTiempo::enPausa() const {
    return _pausar;
}

void ControladorTiempo::actualizar() {
    if (!_pausar)
        _tiempo += _reloj.getElapsedTime() * _velocidad;

    _reloj.restart ();
}


























