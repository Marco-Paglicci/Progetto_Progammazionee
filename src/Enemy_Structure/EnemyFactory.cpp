//
// Created by Marco on 28/10/2024.
//

#include <iostream>
#include <random>
#include "../../headers/EnemyFactory.h"

EnemyFactory::EnemyFactory() {
    monster_names    = {"Ombra Strisciante", "Golem di Pietra Antica", "Strega delle Caverne" , "Ragno della Cripta" , "Demone della Forgia Oscura"};
    minions_names = {"Sgherro dell’Oscurità","Predone delle Cripte","Cultista della Luna Nera","Sentinella di Ferro","Bruto delle Profondità"};
}



unique_ptr<Enemy> EnemyFactory::createEnemy(int enemyType, int strenght) {
    switch (enemyType) {
        case 1:
            return make_unique<Enemy_Monster>(strenght, selectName(enemyType),enemy_Texture);
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

string EnemyFactory::selectName(int enemyType) {

    switch (enemyType) {
        case 1:
            enemy_name = monster_names[randomIndex()];
        case 2:
            enemy_name = minions_names[randomIndex()];
        case 3:

    }


    return enemy_name;
}

int EnemyFactory::randomIndex() {
    //sceglie un indice casuale all'interno del vettore
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, monster_names.size() - 1);
    int randomIndex = distr(gen);

    return randomIndex;
}

