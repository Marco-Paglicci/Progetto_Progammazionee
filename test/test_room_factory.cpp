//
// Created by Marco on 09/01/2025.
//

#include <gtest/gtest.h>
#include "../headers/RoomFactory.h"
#include "../headers/Room.h"

TEST(RoomFactoryTest, CreatesFangsRoom) {
    unique_ptr<Room> room = RoomFactory::createRoom(1, 10, 10);
    ASSERT_NE(room, nullptr);  // Verifica che la stanza non sia nulla
    ASSERT_EQ(room->getWidth(), 10);  // Verifica la larghezza
    ASSERT_EQ(room->getHeight(), 10);  // Verifica l'altezza
}

TEST(RoomFactoryTest, CreatesZigZagRoom) {
    unique_ptr<Room> room = RoomFactory::createRoom(2, 15, 20);
    ASSERT_NE(room, nullptr);
    ASSERT_EQ(room->getWidth(), 15);
    ASSERT_EQ(room->getHeight(), 20);
}

TEST(RoomFactoryTest, CreatesLongCorridorRoom) {
    unique_ptr<Room> room = RoomFactory::createRoom(3, 30, 5);
    ASSERT_NE(room, nullptr);
    ASSERT_EQ(room->getWidth(), 30);
    ASSERT_EQ(room->getHeight(), 5);
}

TEST(RoomFactoryTest, CreatesBossRoom) {
    unique_ptr<Room> room = RoomFactory::createRoom(4, 50, 50);
    ASSERT_NE(room, nullptr);
    ASSERT_EQ(room->getWidth(), 50);
    ASSERT_EQ(room->getHeight(), 50);
}

TEST(RoomFactoryTest, RoomGeneratesOuterWalls) {
    unique_ptr<Room> room = RoomFactory::createRoom(1, 10, 10);
    room->Generate_OuterWalls();

    // Verifica che i muri esterni siano stati generati
    ASSERT_EQ(room->getOuterWalls().size(), 4);  // Ci dovrebbero essere 4 muri esterni
}

TEST(RoomFactoryTest, CreatesInvalidRoom) {
    unique_ptr<Room> room = RoomFactory::createRoom(99, 10, 10);  // Tipo di stanza non valido
    ASSERT_EQ(room, nullptr);  // Verifica che la stanza sia nulla
}

TEST(RoomFactoryTest, CreatesBossRoomAndSetsFlag) {
    unique_ptr<Room> room = RoomFactory::createRoom(4, 50, 50);
    room->setBossRoom(true);  // Impostiamo la stanza come Boss Room
    ASSERT_TRUE(room->isBossRoom());  // Verifica che il flag sia stato impostato correttamente
}



