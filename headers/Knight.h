//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_KNIGHT_H
#define PROGETTO_PROGRAMMAZIONE_KNIGHT_H

#include "Personaggio.h"

class Knight : public Personaggio{

public:
    Knight(float x, float y, float size, RenderWindow &window);

private:
    Weapon W;
};


#endif //PROGETTO_PROGRAMMAZIONE_KNIGHT_H
