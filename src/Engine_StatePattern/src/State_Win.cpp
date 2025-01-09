//
// Created by Marco on 20/12/2024.
//

#include "../headers/State_Win.h"
#include <iostream>


void State_Win::handleInput(Engine &engine) {

    Event event{};
    while(engine.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            engine.getWindow().close();
        }
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed((Keyboard::Enter))) {

                engine.changeState(new State_StartMenu);

            }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                engine.getWindow().close();
            }
        }
    }

}

void State_Win::draw(Engine &engine) {

    if(entry)
    {
        enter(engine);
        entry = false;
    }

    if (engine.getClock().getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
    {
        engine.setVisible(!engine.isVisible());
        engine.ResetClock(engine.getClock());
    }
    if (engine.isVisible())
        engine.win();
    handleInput(engine);

}

void State_Win::enter(Engine &engine) {

    if (!engine.gameover_soundtrack.openFromFile("./assets/audio/soundtracks/gameover_soundtrack.ogg")) {
        cout << "Errore: impossibile caricare la traccia audio del menu!" << endl;
    } else {
        engine.gameover_soundtrack.setLoop(true); // Riproduzione in loop
        engine.gameover_soundtrack.setVolume(100); // Volume al 50%
        engine.gameover_soundtrack.play();        // Avvia la musica
        cout << "Playing soundtrack" << endl;
    }


}

void State_Win::exit(Engine &engine) {

    engine.gameover_soundtrack.stop();

}
