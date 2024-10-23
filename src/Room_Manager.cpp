//
// Created by Marco on 22/10/2024.
//

#include <random>
#include "../headers/Room_Manager.h"

Room_Manager::Room_Manager(int width, int height) {

    roomPool.push_back(RoomFactory::createRoom(1,width,height));
    roomPool.push_back(RoomFactory::createRoom(2, width, height));  // Crea ZIGZAG
    roomPool.push_back(RoomFactory::createRoom(3, width, height));  // Crea LONG CORRIDOR
}

unique_ptr<Room> Room_Manager::getRandomRoom() {

    if (roomPool.empty()) return nullptr;

    //sceglie un indice casuale all'interno del vettore
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, roomPool.size() - 1);
    return roomPool[distr(gen)]->clone();  // Restituisce una stanza casuale

}