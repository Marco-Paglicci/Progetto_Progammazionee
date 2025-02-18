//
// Created by Marco on 18/02/2025.
//
#include <gtest/gtest.h>
#include "../headers/Room.h"
#include "../headers/Boss_Room.h"


TEST(BasicTest, CheckRoomConstruction) {


    std::cout << "Inizio test" << std::endl;
    Boss_Room* room = new Boss_Room(10, 10);
    std::cout << "Stanza creata" << std::endl;
    delete room;
    std::cout << "Stanza eliminata" << std::endl;
}

