//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_PLAYING_H
#define PROGETTO_PROGRAMMAZIONE_STATE_PLAYING_H


#include "State.h"
#include "State_AnimatingSnake.h"
#include "../../../headers/Engine.h"


class State_Playing : public State {

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;

    void enter(Engine &engine) override;

    void exit(Engine &engine) override;

};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_PLAYING_H
