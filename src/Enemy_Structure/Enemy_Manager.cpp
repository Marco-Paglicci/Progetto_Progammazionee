//
// Created by Marco on 28/10/2024.
//
#include <random>

#include <iostream>
#include "../../headers/Enemy_Manager.h"

Enemy_Manager::Enemy_Manager() {

    enemyPool.push_back(EnemyFactory::createEnemy(1,1));

}

unique_ptr<Enemy> Enemy_Manager::getRandomEnemy() {

    if(enemyPool.empty()) return nullptr;

    cout << "Dimensione enemy pool " + enemyPool.size() << endl;

    //sceglie un indice casuale all'interno del vettore
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, enemyPool.size() - 1);

    int randomIndex = distr(gen);  // Genera l'indice casuale
    cout << "Indice casuale scelto: " << randomIndex << endl;

    return enemyPool[randomIndex]->clone();
}


