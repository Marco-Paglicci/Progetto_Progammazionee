//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_STARTMENU_H
#define PROGETTO_PROGRAMMAZIONE_STATE_STARTMENU_H


#include "State.h"
#include "../../../headers/Engine.h"
#include "State_CharacterSelection.h"


class State_StartMenu : public State {

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;
};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_STARTMENU_H