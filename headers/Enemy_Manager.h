//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_MANAGER_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_MANAGER_H

#include "EnemyFactory.h"

using namespace std;


class Enemy_Manager {

private:
    vector<unique_ptr<Enemy>> enemyPool;

public:

    Enemy_Manager();



    unique_ptr<Enemy> getRandomEnemy();

};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_MANAGER_H
