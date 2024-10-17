cmake_minimum_required(VERSION 3.29)
project(Progetto_Programmazione)

set(CMAKE_CXX_STANDARD 20)

# Aggiungi SFML_DIR per indicare il percorso dove si trovano i file di configurazione di SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # Modifica questo percorso!

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(Progetto_Programmazione main.cpp headers/Engine.h
        src/Engine.cpp
        src/Engine_input.cpp
        src/Engine_menu.cpp
        src/Engine_snakeanimation.cpp)

target_link_libraries(Progetto_Programmazione  sfml-system sfml-window sfml-graphics)