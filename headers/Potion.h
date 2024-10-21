//
// Created by Marco on 21/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_POTION_H
#define PROGETTO_PROGRAMMAZIONE_POTION_H


#include "Treasure.h"

class Potion : public Treasure {
public:
    Potion(const std::string& name, int strength, bool health, bool strengthBonus);

    int getStrength() const;
    bool isHealthPotion() const;
    bool hasStrengthBonus() const;

private:
    int strength;
    bool health;
    bool strengthBonus;
};


#endif //PROGETTO_PROGRAMMAZIONE_POTION_H
