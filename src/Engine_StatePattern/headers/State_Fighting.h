//
// Created by Marco on 23/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H
#define PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H


#include "State.h"
#include "../../../headers/Engine.h"
#include <functional>
#include <vector>



class State_Fighting : public State {

public:
    void handleInput(Engine& engine) override;
    void draw(Engine& engine) override;

    State_Fighting();

protected:
    vector<function<void(Engine&)>> actions;

    //E' un vettore che definisce le azioni eseguibili nello stato di fight
    //attraverso funzioni diverse , in questo modo possiamo scorrere il vettore
    //per identificare la specifica azione
};

#endif //PROGETTO_PROGRAMMAZIONE_STATE_FIGHTING_H
