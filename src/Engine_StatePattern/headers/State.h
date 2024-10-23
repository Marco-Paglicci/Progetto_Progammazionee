//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_H
#define PROGETTO_PROGRAMMAZIONE_STATE_H


class Engine;
class State_CharacterSelection;


class State {

public:
    virtual ~State() {}
    virtual void handleInput(Engine& engine) = 0;
    virtual void draw(Engine& engine) = 0;
};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_H
