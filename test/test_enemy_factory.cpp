//
// Created by Marco on 09/01/2025.
//
#include <gtest/gtest.h>
#include "../headers/EnemyFactory.h"
#include "../headers/Enemy_Boss.h"
#include "../headers/Enemy_Minion.h"

TEST(EnemyFactoryTest, CreateEnemyBoss) {
    EnemyFactory factory;

    // Crea un Enemy_Boss con forza 3, nome "Boss", e le texture
    unique_ptr<Enemy> boss = factory.createEnemy(3,2);

    // Verifica che il nemico creato sia un Boss
    assert(dynamic_cast<Enemy_Boss*>(boss.get()) != nullptr);

    // Verifica i valori iniziali (esempio: Hp, attacco, armatura)
    assert(boss->getHp() == 40);
    assert(boss->getAttack() == 10);
    assert(boss->getArmour() == 5);
}

TEST(EnemyFactoryTest, CreateEnemyMonster) {


    EnemyFactory factory;

    // Crea un Enemy_Boss con forza 3, nome "Boss", e le texture
    unique_ptr<Enemy> Monster = factory.createEnemy(1,2);

    // Verifica che il nemico creato sia un Boss
    assert(dynamic_cast<Enemy_Monster*>(Monster.get()) != nullptr);

    // Verifica i valori iniziali (esempio: Hp, attacco, armatura)
    assert(Monster->getHp() == 15);
    assert(Monster->getAttack() == 5);
    assert(Monster->getArmour() == 2);
}

TEST(EnemyFactoryTest, CreateEnemyMinion) {


    EnemyFactory factory;

    // Crea un Enemy_Boss con forza 3, nome "Boss", e le texture
    unique_ptr<Enemy> Minion = factory.createEnemy(2,2);

    // Verifica che il nemico creato sia un Boss
    assert(dynamic_cast<Enemy_Minion*>(Minion.get()) != nullptr);

    // Verifica i valori iniziali (esempio: Hp, attacco, armatura)
    assert(Minion->getHp() == 10);
    assert(Minion->getAttack() == 3);
    assert(Minion->getArmour() == 1);
}

TEST(EnemyFactoryTest, CloneEnemy) {


    EnemyFactory factory;

    // Crea un nemico tramite la factory
    unique_ptr<Enemy> boss = factory.createEnemy(3,2);

    // Clona l'oggetto
    unique_ptr<Enemy> clonedBoss = boss->clone();

    // Verifica che siano lo stesso tipo di oggetto
    assert(dynamic_cast<Enemy_Boss*>(boss.get()) != nullptr);
    assert(dynamic_cast<Enemy_Boss*>(clonedBoss.get()) != nullptr);

    // Verifica che gli attributi siano identici
    assert(boss->getHp() == clonedBoss->getHp());
    assert(boss->getAttack() == clonedBoss->getAttack());
    assert
    (boss->getArmour() == clonedBoss->getArmour());
}




