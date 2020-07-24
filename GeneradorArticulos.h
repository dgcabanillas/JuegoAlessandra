//
// Created by hp on 22/07/2020.
//

#ifndef BOMBERMAN_GENERADORARTICULOS_H
#define BOMBERMAN_GENERADORARTICULOS_H

#include <vector>

//Esta clase se utiliza para generar potenciadores o desventajas cuando se destruye un bloque
class GeneradorArticulos {

private:
    unsigned int  _nbIntentoIzquierda;
    std::vector<unsigned int > _nbArticulosIzquierda;

public:

    //El constructor nos permitira trabajar con la cantida de
    //ladrillos que se destruiran
    //En un bucle for
    //_nbIntentoIzquierda[i] = seria la cantidad de articulos en el mapa
    GeneradorArticulos(unsigned int nbIntento, std::vector<unsigned int> const& nbArticulos);

    //Intenta y comprueba si se creo un articulo
    //Devuelve -1 si no se genera ningun articulo
    int generar();
};



#endif //BOMBERMAN_GENERADORARTICULOS_H
