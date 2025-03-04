//
// Created by Marco on 18/02/2025.
//
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Enemy_Monster.h"
#include "../headers/EnemyFactory.h"
#include "../headers/Personaggio.h"
#include "../headers/Engine.h"


TEST(test_negative_damage, NegativeDamage) {

    Engine engine;
    unique_ptr<Room> R = RoomFactory::createRoom(1,800,600);
    engine.setR(R);
    int initial_hp = engine.getR()->getE()->getHp();
    engine.attackAction(engine);
    int final_hp = engine.getR()->getE()->getHp();
    ASSERT_TRUE(initial_hp >= final_hp);
}

TEST(test_negative_damage_enemy , NegativeDamageEnemy) {

    Engine engine;
    unique_ptr<Room> R = RoomFactory::createRoom(1,800,600);
    engine.setR(R);

    int intial_hp = engine.getP()->getHp();
    engine.enemy_attack_Action();
    int final_hp = engine.getP()->getHp();
    ASSERT_TRUE(intial_hp >= final_hp);
}