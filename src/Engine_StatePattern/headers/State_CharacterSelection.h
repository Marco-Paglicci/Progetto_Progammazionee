//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_CHARACTERSELECTION_H
#define PROGETTO_PROGRAMMAZIONE_STATE_CHARACTERSELECTION_H


#include "State.h"
#include "../../../headers/Engine.h"

class State_CharacterSelection : public State {

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;

};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_CHARACTERSELECTION_H
