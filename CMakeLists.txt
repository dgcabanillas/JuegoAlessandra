cmake_minimum_required(VERSION 3.16)
project(Bomberman)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(Bomberman main.cpp
                ControladorBomba.cpp ControladorBomba.h
                Constante.cpp Constante.h
                ControladorLadrilloExplosivo.cpp ControladorLadrilloExplosivo.h
                Fuego.cpp Fuego.h
                ControladorFuego.cpp ControladorFuego.h
                GeneradorArticulos.cpp GeneradorArticulos.h
                Mapa.cpp Mapa.h
                Jugador.cpp Jugador.h
                RelacionJugadores.cpp RelacionJugadores.h
                ControladorTiempo.cpp ControladorTiempo.h
                Mundo.cpp Mundo.h)

target_link_libraries(Bomberman sfml-system sfml-window sfml-graphics)





