//
// Created by Marco on 23/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H
#define PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H


#include "State.h"
#include "../../../headers/Engine.h"

class State_Fighting : public State {

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H
