//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_MONSTER_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_MONSTER_H


#include "Enemy.h"

class Enemy_Monster : public Enemy {

public:
    Enemy_Monster(int strenght,  string name, const Texture &texture, const Texture &texture_FW);

    void drawEnemy(RenderWindow &window) override;

    unique_ptr<Enemy> clone() const override;

};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_MONSTER_H
