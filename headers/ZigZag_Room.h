//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ZIGZAG_ROOM_H
#define PROGETTO_PROGRAMMAZIONE_ZIGZAG_ROOM_H

#include "Room.h"

class ZigZag_Room : public Room {

public:
    ZigZag_Room(int width, int height);

    void genera_ZigZag();

    void drawRoom(RenderWindow &window);

};


#endif //PROGETTO_PROGRAMMAZIONE_ZIGZAG_ROOM_H
