//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../headers/State_Playing.h"
#include "../headers/State_Fighting.h"

void State_Playing::handleInput(Engine &engine) {

}

void State_Playing::draw(Engine &engine) {

        engine.getWindow().draw(engine.getSprite());
        engine.getR()->drawRoom(engine.getWindow());
        engine.getP()->draw();

        engine.input();



    if (engine.getR()->isHaveEnemy()) {

        if (engine.getR()->getE()->isAlive()) {
            engine.getR()->changeEntranceColor("Transparent");
        } else {
            engine.getR()->changeEntranceColor("Green");
        }
    } else {
        engine.getR()->changeEntranceColor("Green");
    }

        /*------CODICE PER LIMITARE IL MOVIMENTO IN ROOM------*/

        //questo codice si occupa delle collisioni  con le pareti della stanza durante il movimento , esterne o interne

        if (engine.getP()->getCollisionRect().intersects(engine.getR()->getTop().getGlobalBounds())) {
            engine.getP()->Collision("top");
        }
        if (engine.getP()->getCollisionRect().intersects(engine.getR()->getBottom().getGlobalBounds())) {
            engine.getP()->Collision("bottom");
        }
        if (engine.getP()->getCollisionRect().intersects(engine.getR()->getLeft().getGlobalBounds())) {
            engine.getP()->Collision("left");
        }
        if (engine.getP()->getCollisionRect().intersects(engine.getR()->getRight().getGlobalBounds())) {
            engine.getP()->Collision("right");
        }
        if (engine.getP()->getCollisionRect().intersects(engine.getR()->getTop().getGlobalBounds()) ||
            engine.getP()->getCollisionRect().intersects(engine.getR()->getBottom().getGlobalBounds()) ||
            engine.getP()->getCollisionRect().intersects(engine.getR()->getLeft().getGlobalBounds()) ||
            engine.getP()->getCollisionRect().intersects(engine.getR()->getRight().getGlobalBounds())) {

            for (const auto &wall: engine.getR()->getOuterWalls()) {
                if (engine.getP()->getCollisionRect().intersects(wall.getGlobalBounds())) {
                    engine.getP()->Collision(engine.getP()->getCollisionDirection(wall.getGlobalBounds()));
                }
            }
        }

        //codice per collisione con muri interni
        for (const auto &wall: engine.getR()->getInnerWalls()) {
            if (engine.getP()->getCollisionRect().intersects(wall.getGlobalBounds())) {
                engine.getP()->Collision(engine.getP()->getCollisionDirection(wall.getGlobalBounds()));
            }
        }
    //per le stanze senza un nemico all'interno
    if (!engine.getR()->isHaveEnemy() &&
        engine.getP()->getCollisionRect().intersects((engine.getR()->getEntrance().getGlobalBounds()))) {
        engine.getWindow().clear();
        engine.setAnimatingSnake(true);
        engine.changeState(new State_AnimatingSnake());
        }
    //per le stanze con un nemico all'interno
        if (!engine.getR()->getE()->isAlive() && engine.getP()->getCollisionRect().intersects((engine.getR()->getEntrance().getGlobalBounds()))) {
            engine.getWindow().clear();
            engine.setAnimatingSnake(true);
            engine.changeState(new State_AnimatingSnake());
        }
        if (engine.getR()->getE()->isAlive() &&   engine.getP()->getCollisionRect().intersects((engine.getR()->getEnemy().getGlobalBounds()))) {
            engine.getWindow().clear();
            playEnemySound(engine);
            engine.changeState(new State_Fighting());
        }
        engine.getWindow().display();

}

void State_Playing::enter(Engine &engine) {
    if (!engine.play_soundtrack.openFromFile("./assets/audio/soundtracks/play_soundtrack.ogg")) {
        cout << "Errore: impossibile caricare la traccia audio del menu!" << endl;
    } else {
        engine.play_soundtrack.setLoop(true); // Riproduzione in loop
        engine.play_soundtrack.setVolume(60); // Volume al 50%
        engine.play_soundtrack.play();        // Avvia la musica
        cout << "Playing soundtrack for play mode" << endl;
    }
}

void State_Playing::exit(Engine &engine) {
    engine.play_soundtrack.stop();
    cout << "stopping soundtrack" << endl;
}

void State_Playing::playEnemySound(Engine &engine) {

    engine.soundBuffer.loadFromFile("./assets/audio/effects/enemy_contact_sound_v2.ogg");
    engine.enemy_sound.setBuffer(engine.soundBuffer);
    engine.chosed.play();


    Time soundDuration = engine.enemy_sound.getBuffer()->getDuration();


    Clock clock;
    while (clock.getElapsedTime() < soundDuration) {
        // Continua a eseguire il ciclo per mantenere il programma attivo
    }


}
