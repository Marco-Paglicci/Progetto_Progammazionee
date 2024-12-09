//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_THIEF_H
#define PROGETTO_PROGRAMMAZIONE_THIEF_H

#include "Personaggio.h"

class Thief:public Personaggio {

public:

    Thief(float x, float y, float size, RenderWindow &window);

    void Camminata_DOWN() override;
    void Camminata_UP() override;
    void Camminata_DX() override;
    void Camminata_SX() override;

    void special_attack() override;

private:

};


#endif //PROGETTO_PROGRAMMAZIONE_THIEF_H
