cmake_minimum_required(VERSION 3.16)
project(Juego_bomberman___POO)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)



add_executable(Juego_bomberman___POO main.cpp
                                    BombManager.cpp BombManager.h
                                    Constants.cpp Constants.h
                                    ExplodingBrickManager.cpp ExplodingBrickManager.h
                                    Fire.cpp Fire.h
                                    FireManager.cpp FireManager.h
                                    ItemGenerator.cpp ItemGenerator.h
                                    Map.cpp Map.h
                                    Player.cpp Player.h
                                    PlayerKeyBinding.cpp PlayerKeyBinding.h
                                    TimeManager.cpp TimeManager.h
                                    World.cpp World.h)

target_link_libraries(Juego_bomberman___POO sfml-system sfml-window sfml-graphics)