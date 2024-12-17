//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ROOM_MANAGER_H
#define PROGETTO_PROGRAMMAZIONE_ROOM_MANAGER_H

#include "RoomFactory.h"

using namespace std;

class Room_Manager {

private:

    //vettore che contiene le varie stanze disponibili
    vector<unique_ptr<Room>> roomPool;

public:

    Room_Manager(int width, int height);

    unique_ptr<Room> getRandomRoom();

    void addRoom(int width, int height,int type);

    void addRoom_Pointer(unique_ptr<Room>);

};


#endif //PROGETTO_PROGRAMMAZIONE_ROOM_MANAGER_H
