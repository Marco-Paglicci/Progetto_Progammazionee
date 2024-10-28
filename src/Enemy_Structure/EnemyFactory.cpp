//
// Created by Marco on 28/10/2024.
//

#include <iostream>
#include "../../headers/EnemyFactory.h"


unique_ptr<Enemy> EnemyFactory::createEnemy(int enemyType, int strenght) {
    switch (enemyType) {
        case 1:
            return make_unique<Enemy_Monster>(strenght);
        case 2:
            //todo finish to implement
            //return make_unique<ZigZag_Room>(width, height);
        case 3:
            //return make_unique<LongCorridor_Room>(width, height);
        default:
            cout << "Enemy type not recognized!" << std::endl;
            return nullptr;
    }
}
