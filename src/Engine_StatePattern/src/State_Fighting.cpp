//
// Created by Marco on 23/10/2024.
//

#include <iostream>
#include "../headers/State_Fighting.h"
#include "../headers/State_Playing.h"


State_Fighting::State_Fighting() {

        actions = {
                Engine::attackAction,  // Attacco
                Engine::defendAction,  // Difesa
                Engine::useSpecialAction, // Usa oggetto
                Engine::runAwayAction  // Fuga
        };

}




void State_Fighting::handleInput(Engine &engine) {

    Event event{};
    while (engine.getWindow().pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            engine.getWindow().close();
        }

        //controlliamo input (controllo input da tastiera)
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                engine.getWindow().close();
            }
        }

        //movimento cursore
        if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Up)) {
            engine.setSelectedOptionIndex((engine.getSelectedOptionIndex() - 1 + 4) % 4);
            cout << "UP - KEYPRESSED" << endl;
        }
        if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Down)) {
            engine.setSelectedOptionIndex((engine.getSelectedOptionIndex() + 1) % 4);
            cout << "DOWN - KEYPRESSED" << endl;
        }
        if (event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Enter)) {
            int selectedIndex = engine.getSelectedOptionIndex();
            if (selectedIndex >= 0 && selectedIndex < actions.size()) {
                actions[selectedIndex](engine); // Esegue l'azione associata
            }
            std::cout << "Enter - Action executed\n";
        }


    }

}

void State_Fighting::draw(Engine &engine) {

    if(!engine.getR()->getE()->isAlive())
    {
        // todo remove testing
        engine.getWindow().clear();
        cout << "il nemico è morto " <<endl;
        engine.changeState(new State_Playing());
    }else {
        engine.fight_window_draw();
        handleInput(engine);
    }
}

void State_Fighting::enter(Engine &engine) {

    if (!engine.fight_soundtrack.openFromFile("../assets/audio/soundtracks/fight_soundtrack.ogg")) {
        cout << "Errore: impossibile caricare la traccia audio del menu!" << endl;
    } else {
        engine.fight_soundtrack.setLoop(true); // Riproduzione in loop
        engine.fight_soundtrack.setVolume(60); // Volume al 50% //TODO ADJUST VOLUME
        engine.fight_soundtrack.play();        // Avvia la musica
        cout << "Playing soundtrack for fighting" << endl;
    }

}

void State_Fighting::exit(Engine &engine) {

    engine.fight_soundtrack.stop();
}



