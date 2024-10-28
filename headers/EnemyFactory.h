//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H


#include "Enemy.h"
#include "Enemy_Monster.h"

class EnemyFactory {

public:
    static unique_ptr<Enemy> createEnemy(int enemyType,int strenght);

};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H
