//
// Created by Marco on 22/10/2024.
//

#include <random>
#include <iostream>
#include "../../headers/Room_Manager.h"

Room_Manager::Room_Manager(int width, int height) {


    roomPool.push_back(RoomFactory::createRoom(2, width, height));  // Crea ZIGZAG
    /*
    roomPool.push_back(RoomFactory::createRoom(1,width,height));    //Crea Fangs
    roomPool.push_back(RoomFactory::createRoom(3, width, height));  // Crea LONG CORRIDOR
    roomPool.push_back(RoomFactory::createRoom(2, width, height));  // Crea ZIGZAG
    roomPool.push_back(RoomFactory::createRoom(1,width,height));    //Crea Fangs
    roomPool.push_back(RoomFactory::createRoom(3, width, height));  // Crea LONG CORRIDOR
    roomPool.push_back(RoomFactory::createRoom(2, width, height));  // Crea ZIGZAG
    roomPool.push_back(RoomFactory::createRoom(1,width,height));    //Crea Fangs
    roomPool.push_back(RoomFactory::createRoom(3, width, height));  // Crea LONG CORRIDOR
    */


    //todo fix : a causa delle dimensioni ridotte dle RoomPool sceglie sempre la prima stanza , aggiungi altre staze
}

unique_ptr<Room> Room_Manager::getRandomRoom() {
    if (roomPool.empty()) return nullptr;

    std::cout << "Dimensione roomPool: " << roomPool.size() << std::endl;

    // Inizializza il seme per la generazione casuale una sola volta
    static bool initialized = false;
    if (!initialized) {
        srand(std::time(nullptr));
        initialized = true;
    }

    // Sceglie un indice casuale all'interno del vettore
    int randomIndex = rand() % roomPool.size();
    std::cout << "Indice casuale scelto: " << randomIndex << std::endl;

    return roomPool[randomIndex]->clone(); // Restituisce una stanza casuale
}

void Room_Manager::addRoom(int width, int height, int type)
{
    roomPool.push_back(RoomFactory::createRoom(1,width,height));
    cout << "Room added with addRoom" << endl;
}

void Room_Manager::addRoom_Pointer(unique_ptr<Room> r) {

    roomPool.push_back(std::move(r));

}
