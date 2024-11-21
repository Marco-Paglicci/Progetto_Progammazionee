//
// Created by Marco on 21/11/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_MINION_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_MINION_H


#include "Enemy.h"

class Enemy_Minion : public Enemy {

public:
    Enemy_Minion(int strenght,  string name, const Texture &texture);
    void drawEnemy(RenderWindow &window) override;

    unique_ptr<Enemy> clone() const override;
};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_MINION_H
