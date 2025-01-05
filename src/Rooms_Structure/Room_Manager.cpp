//
// Created by Marco on 22/10/2024.
//

#include <random>
#include <iostream>
#include "../../headers/Room_Manager.h"

Room_Manager::Room_Manager(int width, int height) {

     initialized = false;
    if (!initialized) {
        srand(std::time(nullptr));
        initialized = true;
    }

    int num_rooms = 5 + (rand() % 5);

    cout << "Numero di stanze generate : " + to_string(num_rooms) << endl;

    // Crea stanze casuali
    for (int i = 0; i < num_rooms - 1; ++i) {
        int randomType = 1 + (rand() % 3); // Sceglie un tipo casuale tra 1, 2, e 3
        roomPool.push_back(RoomFactory::createRoom(randomType, width, height));
    }

    //todo crea nuovo tipo di stanza che identifica la stanza finale su RoomFactory;
    //todo fix : a causa delle dimensioni ridotte dle RoomPool sceglie sempre la prima stanza , aggiungi altre staze
}

unique_ptr<Room> Room_Manager::getRandomRoom() {

    if (roomPool.empty())
    {
        cout << "Nessuna stanza disponibile nel pool!" << endl;
        return nullptr;
    }

    //todo continue from here

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
