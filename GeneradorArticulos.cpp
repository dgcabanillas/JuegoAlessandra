//
// Created by hp on 22/07/2020.
//

#include "GeneradorArticulos.h"
#include <iostream>

#include <time.h>

GeneradorArticulos::GeneradorArticulos(unsigned int nbIntento, std::vector<unsigned int> const& nbArticulos) :
    _nbIntentoIzquierda(nbIntento),
    _nbArticulosIzquierda(nbArticulos)
{
    unsigned int sum = 0;
    for (unsigned int nb : _nbArticulosIzquierda)
        sum += nb;
    if (nbIntento < sum)
        std::cerr << "ATENCION: Los artículos no se pueden generar (GeneradorArticulos::GeneradorArticulos)" << std::endl;

    srand(time(NULL));
}

int GeneradorArticulos::generar() {
    if (_nbIntentoIzquierda == 0) {
        std::cerr << "ATTENTION: No se genera ningun elemento adicional (GeneradorArticulos::GeneradorArticulos)" << std::endl;
        return -1;
    }

    unsigned int sum = 0;
    for (unsigned int nb : _nbArticulosIzquierda)
        sum += nb;

    unsigned int rMax = std::max (sum, _nbIntentoIzquierda);
    unsigned int random = rand () % rMax;

    int returnedItem = -1;
    if (sum > random) {
        sum = 0;
        while (sum <= random) {
            ++returnedItem;
            sum += _nbArticulosIzquierda[returnedItem];
        }
        --_nbArticulosIzquierda[returnedItem];
    }

    --_nbIntentoIzquierda;
    return returnedItem;
}
