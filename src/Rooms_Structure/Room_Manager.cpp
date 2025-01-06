//
// Created by Marco on 22/10/2024.
//

#include <random>
#include <iostream>
#include "../../headers/Room_Manager.h"

bool Room_Manager::initialized = false;

Room_Manager::Room_Manager(int width, int height) {

    if (!initialized) {
        srand(std::time(nullptr));
        initialized = true;
    }

    int num_rooms = 5 + (rand() % 5);
    roompool_size = num_rooms;

    cout << "Numero di stanze generate : " + to_string(num_rooms) << endl;


    //todo rimuovere test
    /*
    // Crea stanze casuali
    for (int i = 0; i < num_rooms - 1; ++i) {
        int randomType = 1 + (rand() % 3); // Sceglie un tipo casuale tra 1, 2, e 3
        auto room = RoomFactory::createRoom(randomType, width, height);
        room->setId(i);
        cout << "Room created with id: " + to_string(room->getId()) << endl;
        roomPool.push_back(move(room));
    }
    */

   //Stanza finale
    roomPool.push_back(RoomFactory::createRoom(4, width, height));


}

unique_ptr<Room> Room_Manager::getRandomRoom() {

    if (roomPool.empty())
    {
        cout << "Nessuna stanza disponibile nel pool!" << endl;
        return nullptr;
    }


    auto room = move(roomPool.front());
    roomPool.erase(roomPool.begin());

    std::cout << "Stanza restituita e rimossa dal pool. Stanze rimanenti: " << roomPool.size() << std::endl;

    return room->clone(); // Restituisce una stanza casuale
}

void Room_Manager::addRoom(int width, int height, int type)
{
    roomPool.push_back(RoomFactory::createRoom(1,width,height));
    cout << "Room added with addRoom" << endl;
}

void Room_Manager::addRoom_Pointer(unique_ptr<Room> r) {

    roomPool.push_back(std::move(r));

}

int Room_Manager::getRoompoolSize() const {
    return roompool_size;
}

void Room_Manager::setRoompoolSize(int roompoolSize) {
    roompool_size = roompoolSize;
}
