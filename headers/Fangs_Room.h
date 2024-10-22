//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_FANGS_ROOM_H
#define PROGETTO_PROGRAMMAZIONE_FANGS_ROOM_H

#include "Room.h"

class Fangs_Room : public Room {

public:
    Fangs_Room(int width, int height);

    void genera_Fangs();

    void drawRoom(RenderWindow &window);
};


#endif //PROGETTO_PROGRAMMAZIONE_FANGS_ROOM_H
