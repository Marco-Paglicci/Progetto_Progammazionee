//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H


#include "Enemy.h"
#include "Enemy_Monster.h"

class EnemyFactory {

private:

    static string enemy_name;
    static Texture enemy_Texture;

    static vector<string> monster_names ;
    static vector<string> minions_names ;
    static vector<string> boss_names;


public:

    EnemyFactory();

    static unique_ptr<Enemy> createEnemy(int enemyType, int strenght);

    static string selectName(int enemyType);

    static int randomIndex();
};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMYFACTORY_H
