#ifndef JUEGO_BOMBERMAN___POO_EXPLODINGBRICKMANAGER_H
#define JUEGO_BOMBERMAN___POO_EXPLODINGBRICKMANAGER_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <list>

#include "TimeManager.h"

///Permite gestionar la explosion de los ladrillos
///Debe tener una referencia a TimeManager
class ExplodingBrickManager: public sf::Drawable
{
public:
    ///Envia un mensaje de error si los recursos no se pudieron cargar
    ExplodingBrickManager (TimeManager const& timeManager);

    void addBrick (unsigned int line, unsigned int col);

    ///Elimina los ladrillos antiguos
    void update ();

private:
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;

private:
    TimeManager const& _timeManager;

    struct ExplodingBrick {
        const unsigned int line, col;
        const sf::Time birthtime;
    };
    std::list<ExplodingBrick> _bricks;

    sf::Texture _spriteSheet;
};


#endif //JUEGO_BOMBERMAN___POO_EXPLODINGBRICKMANAGER_H
