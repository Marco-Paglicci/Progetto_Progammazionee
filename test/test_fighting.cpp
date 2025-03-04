//
// Created by Marco on 04/03/2025.
//
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Enemy_Monster.h"
#include "../headers/EnemyFactory.h"
#include "../headers/Personaggio.h"
#include "../headers/Engine.h"
#include "../src/Engine_StatePattern/headers/State_Fighting.h"

TEST(test_fighting, test_fighting) {
    Engine engine;
    unique_ptr<Room> R = RoomFactory::createRoom(1,800,600);
    engine.setR(R);
    engine.changeState(new State_Fighting());
    engine.getP()->getWeapon()->setPower(10);
    while(engine.getP()->getHp()>0 && engine.getR()->getE()->getHp() > 0)
    {
        engine.attackAction(engine);
    }
    cout << "test completato con successo" << endl;
}