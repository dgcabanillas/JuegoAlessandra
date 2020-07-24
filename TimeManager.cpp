#include "TimeManager.h"

#include <iostream>

TimeManager::TimeManager ():
        _speed (1.f),
        _paused (false),
        _clock(),
        _time ()
{
}

void TimeManager::setSpeed (float speed)
{
    if (speed > 0.f) {
        update ();
        _speed = speed;
    } else {
        std::cerr << "Advertencia (TimeManager::setSpeed): valor incorrecto "
                  << "(" << speed << ")" << std::endl;
    }
}

void TimeManager::pause ()
{
    if (!_paused) {
        update ();
        _paused = true;
    } else {
        std::cerr << "Advertencia (TimeManager::pause): Ya esta en pausa " << std::endl;
    }
}

void TimeManager::resume ()
{
    if (_paused) {
        update ();
        _paused = false;
    } else {
        std::cerr << "Advertencia (TimeManager::pause): Esta corriendo" << std::endl;
    }
}

sf::Time TimeManager::getTime () const
{
    if (_paused)
        return _time;

    return _time + _clock.getElapsedTime() * _speed;
}

bool TimeManager::isPaused () const
{
    return _paused;
}

void TimeManager::update ()
{
    if (!_paused)
        _time += _clock.getElapsedTime() * _speed;

    _clock.restart ();
}
