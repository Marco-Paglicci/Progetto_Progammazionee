//
// Created by Marco on 06/01/2025.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_BOSS_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_BOSS_H

#include "Enemy.h"

class Enemy_Boss : public Enemy {



public:
    Enemy_Boss(int strenght, string name, const Texture &texture, const Texture &texture_FW);

    void drawEnemy(RenderWindow &window) override;

    unique_ptr<Enemy> clone() const override;
};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_BOSS_H
