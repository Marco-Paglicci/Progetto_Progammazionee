//
// Created by Marco on 05/01/2025.
//

#ifndef PROGETTO_PROGRAMMAZIONE_BOSS_ROOM_H
#define PROGETTO_PROGRAMMAZIONE_BOSS_ROOM_H

#include "Room.h"



class Boss_Room : public Room {

protected:



public:

    Boss_Room(int width, int height);

    void genera_Boss_Room();

    void drawRoom(RenderWindow &window);
    void generate_InnerWalls();

    unique_ptr<Room> clone() const  override;

    bool isBossRoom() const override;

};


#endif //PROGETTO_PROGRAMMAZIONE_BOSS_ROOM_H
