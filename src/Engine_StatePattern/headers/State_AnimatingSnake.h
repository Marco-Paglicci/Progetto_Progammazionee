//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_ANIMATINGSNAKE_H
#define PROGETTO_PROGRAMMAZIONE_STATE_ANIMATINGSNAKE_H

#include "State.h"
#include "../../../headers/Engine.h"

class State_AnimatingSnake :public State {

public:
    void handleInput(Engine& engine) override;
    void update(Engine& engine) override;
    void draw(Engine& engine) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_ANIMATINGSNAKE_H
