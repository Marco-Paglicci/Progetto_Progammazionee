//
// Created by Marco on 22/10/2024.
//

#include "../headers/State_CharacterSelection.h"

void State_CharacterSelection::handleInput(Engine &engine) {

    Event event{};
    while(engine.getWindow().pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed((Keyboard::Num1))) {
                engine.setClasse("Knight");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
            }
            if (Keyboard::isKeyPressed((Keyboard::Num2))) {
                engine.setClasse("Thief");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);

            }
            if (Keyboard::isKeyPressed((Keyboard::Num3))) {
                engine.setClasse("Mage");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);

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
    engine.input();

}
