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
        src/Engine_snakeanimation.cpp
        src/Engine_scelta_personaggio.cpp
        src/Personaggio.cpp
        headers/Personaggio.h
        src/Treasure.cpp
        headers/Treasure.h
        src/Weapon.cpp
        headers/Weapon.h
        src/Potion.cpp
        headers/Potion.h
        src/TreasureFactory.cpp
        headers/TreasureFactory.h
        headers/Version.h
        src/Knight.cpp
        headers/Knight.h
        src/Thief.cpp
        headers/Thief.h
        headers/Thief.h
        src/Mage.cpp
        headers/Mage.h
        src/Room.cpp
        headers/Room.h
        src/Fangs_Room.cpp
        headers/Fangs_Room.h
        src/ZigZag_Room.cpp
        headers/ZigZag_Room.h
        src/LongCorridor_Room.cpp
        headers/LongCorridor_Room.h
)

target_link_libraries(Progetto_Programmazione  sfml-system sfml-window sfml-graphics)