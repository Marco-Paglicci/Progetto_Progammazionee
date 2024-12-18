//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../headers/State_StartMenu.h"


void State_StartMenu::handleInput(Engine &engine) {

    Event event{};
    while(engine.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            engine.getWindow().close();
        }
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed((Keyboard::Enter))) {

                engine.changeState(new State_CharacterSelection());

            }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                engine.getWindow().close();
            }
        }
    }


}

void State_StartMenu::draw(Engine &engine) {

    //costringe State_Menu a passare da entry al primo run del draw;
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
        engine.menu();
    handleInput(engine);

}

void State_StartMenu::enter(Engine &engine) {

    if (!menu_soundtrack.openFromFile("../assets/audio/soundtracks/menu_soundtrack.ogg")) {
        cout << "Errore: impossibile caricare la traccia audio del menu!" << endl;
    } else {
        menu_soundtrack.setLoop(true); // Riproduzione in loop
        menu_soundtrack.setVolume(100); // Volume al 50%
        menu_soundtrack.play();        // Avvia la musica
        cout << "Playing soundtrack" << endl;
    }

}

void State_StartMenu::exit(Engine &engine) {

    menu_soundtrack.stop();
}
