#ifndef JUEGO_BOMBERMAN___POO_ITEMGENERATOR_H
#define JUEGO_BOMBERMAN___POO_ITEMGENERATOR_H

#include <vector>


class ItemGenerator
{
private:
    unsigned int _nbTriesLeft;
    std::vector<unsigned int> _nbItemsLeft;


public:

    ItemGenerator (unsigned int nbTries, std::vector<unsigned int> const& nbItems);


    int generate ();

};


#endif //JUEGO_BOMBERMAN___POO_ITEMGENERATOR_H
