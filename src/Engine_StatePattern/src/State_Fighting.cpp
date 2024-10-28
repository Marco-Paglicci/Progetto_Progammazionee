//
// Created by Marco on 23/10/2024.
//

#include <iostream>
#include "../headers/State_Fighting.h"

void State_Fighting::handleInput(Engine &engine) {

    Event event{};
    while (engine.getWindow().pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            engine.getWindow().close();
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

    }
}

void State_Fighting::draw(Engine &engine) {

    engine.fight_window_draw();
    handleInput(engine);

}
