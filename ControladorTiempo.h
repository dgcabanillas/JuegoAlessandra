//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_CONTROLADORTIEMPO_H
#define BOMBERMAN_CONTROLADORTIEMPO_H

#include <SFML/System/Clock.hpp>

//Utilizaremos esta clase como un reloj
//De esta manera podemos pausar o alargar el tiempo

class ControladorTiempo {
private:
    float _velocidad; // > 0.f
    bool _pausar;

    //sf::Clock es un constructor predeterminado.
    //El reloj comienza automáticamente después de ser construido.
    sf::Clock _reloj;
    sf::Time _tiempo;

    //Actualiza el valor de la hora
    void actualizar();

public:
    ControladorTiempo();

    //La velocidad debe ser > o.f
    //En caso no lo sea,se manda un mensaje de advertencia
    void setVelocidad (float speed);

    //Pausa el reloj
    //Si ya esta en pausa, se escribe un mensaje de adevertencia
    void pausa();

    //Reanuda el reloj
    //Si ya se reanudo, se escribe un mensaje de adevertencia
    void reanudar();

    sf::Time getTiempo() const ;

    bool enPausa() const ;


};


#endif //BOMBERMAN_CONTROLADORTIEMPO_H
