//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_LONGCORRIDOR_ROOM_H
#define PROGETTO_PROGRAMMAZIONE_LONGCORRIDOR_ROOM_H

#include "Room.h"

class LongCorridor_Room: public Room {

public:

    LongCorridor_Room(int width, int height);

    void genera_LongCorridor();

    void drawRoom(RenderWindow &window);
};


#endif //PROGETTO_PROGRAMMAZIONE_LONGCORRIDOR_ROOM_H