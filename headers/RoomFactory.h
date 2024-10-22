//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ROOMFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_ROOMFACTORY_H

#include "Room.h"
#include "../headers/Fangs_Room.h"
#include "../headers/ZigZag_Room.h"
#include "../headers/LongCorridor_Room.h"

class RoomFactory {

public:
    static unique_ptr<Room> createRoom(int roomType, int width, int height);
};


#endif //PROGETTO_PROGRAMMAZIONE_ROOMFACTORY_H
