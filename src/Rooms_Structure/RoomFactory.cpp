//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../../headers/RoomFactory.h"





unique_ptr<Room> RoomFactory::createRoom(int roomType, int width, int height) {
    switch (roomType) {
        case 1:
            return make_unique<Fangs_Room>(width, height);
        case 2:
            return make_unique<ZigZag_Room>(width, height);
        case 3:
            return make_unique<LongCorridor_Room>(width, height);
        default:
            cout << "Room type not recognized!" << std::endl;
            return nullptr;
    }
}