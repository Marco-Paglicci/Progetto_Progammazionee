//
// Created by Marco on 22/10/2024.
//

#include <random>
#include <iostream>
#include "../../headers/Room_Manager.h"

Room_Manager::Room_Manager(int width, int height) {


    roomPool.push_back(RoomFactory::createRoom(2, width, height));  // Crea ZIGZAG
    roomPool.push_back(RoomFactory::createRoom(3, width, height));  // Crea LONG CORRIDOR
    roomPool.push_back(RoomFactory::createRoom(1,width,height));    //Crea Fangs


    //todo fix : a causa delle dimensioni ridotte dle RoomPool sceglie sempre la prima stanza , aggiungi altre staze
}

unique_ptr<Room> Room_Manager::getRandomRoom() {

    if (roomPool.empty()) return nullptr;

    cout << "Dimensione roomPool: " << roomPool.size() << endl;


    //sceglie un indice casuale all'interno del vettore
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, roomPool.size() - 1);

    int randomIndex = distr(gen);  // Genera l'indice casuale
    cout << "Indice casuale scelto: " << randomIndex << endl;


    return roomPool[randomIndex]->clone();  // Restituisce una stanza casuale

}