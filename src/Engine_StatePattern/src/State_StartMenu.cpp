//
// Created by Marco on 22/10/2024.
//

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
        }
    }


}

void State_StartMenu::draw(Engine &engine) {

    if (engine.getClock().getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
    {
        engine.setVisible(!engine.isVisible());
        engine.ResetClock(engine.getClock());
    }
    if (engine.isVisible())
        engine.menu();
    engine.input();

}
