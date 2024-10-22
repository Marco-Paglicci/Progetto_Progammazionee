//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_MAGE_H
#define PROGETTO_PROGRAMMAZIONE_MAGE_H

#include "Personaggio.h"

class Mage:public Personaggio {

public:
    Mage(float x, float y, float size, RenderWindow &window);


    void Camminata_UP() override;
    void Camminata_DX() override;
    void Camminata_SX() override;

private:
    Weapon W;
};


#endif //PROGETTO_PROGRAMMAZIONE_MAGE_H
