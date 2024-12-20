//
// Created by Marco on 20/12/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_GAMEOVER_H
#define PROGETTO_PROGRAMMAZIONE_STATE_GAMEOVER_H

#include "State.h"
#include "../../../headers/Engine.h"
#include "State_StartMenu.h"

class State_GameOver : public State {

private:
    bool entry = true;

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;

    void enter(Engine &engine) override;

    void exit(Engine &engine) override;

};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_GAMEOVER_H
