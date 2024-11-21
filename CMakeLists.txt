cmake_minimum_required(VERSION 3.29)

# Nome del progetto
project(Progetto_Programmazione)

# Specifica la versione di C++
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
        src/Rooms_Structure/Room.cpp
        headers/Room.h
        src/Rooms_Structure/Fangs_Room.cpp
        headers/Fangs_Room.h
        src/Rooms_Structure/ZigZag_Room.cpp
        headers/ZigZag_Room.h
        src/Rooms_Structure/LongCorridor_Room.cpp
        headers/LongCorridor_Room.h
        src/Rooms_Structure/Room_Manager.cpp
        headers/Room_Manager.h
        src/Rooms_Structure/RoomFactory.cpp
        headers/RoomFactory.h
        src/Engine_StatePattern/src/State.cpp
        src/Engine_StatePattern/headers/State.h
        src/Engine_StatePattern/src/State_StartMenu.cpp
        src/Engine_StatePattern/headers/State_StartMenu.h
        src/Engine_StatePattern/src/State_CharacterSelection.cpp
        src/Engine_StatePattern/headers/State_CharacterSelection.h
        src/Engine_StatePattern/src/State_Playing.cpp
        src/Engine_StatePattern/headers/State_Playing.h
        src/Engine_StatePattern/src/State_AnimatingSnake.cpp
        src/Engine_StatePattern/headers/State_AnimatingSnake.h
        src/Enemy_Structure/Enemy.cpp
        headers/Enemy.h
        src/Enemy_Structure/Enemy_Manager.cpp
        headers/Enemy_Manager.h
        src/Enemy_Structure/EnemyFactory.cpp
        headers/EnemyFactory.h
        src/Enemy_Structure/Enemy_Monster.cpp
        headers/Enemy_Monster.h
        src/Enemy_Structure/Enemy_Minion.cpp
        headers/Enemy_Minion.h
)



target_link_libraries(${PROJECT_NAME}  sfml-system sfml-window sfml-graphics)

# Copia i file .dll nella directory di output
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/SFML/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)