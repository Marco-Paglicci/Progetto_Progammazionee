//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../headers/State_CharacterSelection.h"
#include "../headers/State_Playing.h"

void State_CharacterSelection::handleInput(Engine &engine) {

    Event event{};
    while(engine.getWindow().pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed((Keyboard::Num1))) {
                engine.setClasse("knight");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();
                engine.changeState(new State_Playing());
            }
            if (Keyboard::isKeyPressed((Keyboard::Num2))) {
                engine.setClasse("thief");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();
                engine.changeState(new State_Playing());

            }
            if (Keyboard::isKeyPressed((Keyboard::Num3))) {
                engine.setClasse("mage");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();
                engine.changeState(new State_Playing());

            }
            if (Keyboard::isKeyPressed((Keyboard::Escape))) {
                engine.getWindow().close();

            }
        }
    }

}

void State_CharacterSelection::draw(Engine &engine) {
    if (engine.getClock().getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
    {
        engine.setVisible(!engine.isVisible());
        engine.ResetClock(engine.getClock());
    }
    if (engine.isVisible())
        engine.scelta();
    handleInput(engine);

}

void State_CharacterSelection::enter(Engine &engine) {

}

void State_CharacterSelection::exit(Engine &engine) {

}
