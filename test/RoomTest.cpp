//
// Created by Marco on 10/12/2024.
//
#include <gtest/gtest.h>
#include "../headers/Room.h"
#include "../headers/RoomFactory.h"
#include "../headers/Room_Manager.h"
#include "../headers/Enemy.h"

TEST(RoomTest, GetSize) {


    RoomFactory RF;
    Room_Manager RM(10,20);

    RM.addRoom_Pointer(RF.createRoom(1,10,20));

    auto room = RM.getRandomRoom();
    ASSERT_NE(room, nullptr) << "getRandomRoom ha restituito un puntatore nullo";

    auto height = room->getHeight();
    auto width = room->getWidth();

    EXPECT_EQ(height, 20) << "L'altezza della stanza non corrisponde a quella attesa";
    EXPECT_EQ(width, 10) << "La larghezza della stanza non corrisponde a quella attesa";
}

