//
// Created by Marco on 22/10/2024.
//

#include "../headers/State_AnimatingSnake.h"

void State_AnimatingSnake::handleInput(Engine &engine) {

}

void State_AnimatingSnake::draw(Engine &engine)
{
    if(engine.isAnimatingSnake() && !engine.isStartMenu() && !engine.isFight())
    {
        engine.snakeAnimation();
    }

}
