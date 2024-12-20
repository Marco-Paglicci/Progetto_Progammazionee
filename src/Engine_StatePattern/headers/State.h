//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_STATE_H
#define PROGETTO_PROGRAMMAZIONE_STATE_H


#include <SFML/Audio.hpp>

class Engine;
class State_CharacterSelection;


class State {

public:
    virtual ~State() {}
    virtual void handleInput(Engine& engine) = 0;
    virtual void draw(Engine& engine) = 0;

    //funzione per attività di ingresso e uscita da uno stato
    virtual void enter(Engine& engine)=0;
    virtual void exit(Engine& engine)=0;

};


#endif //PROGETTO_PROGRAMMAZIONE_STATE_H
