//
// Created by Marco on 21/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_TREASUREFACTORY_H
#define PROGETTO_PROGRAMMAZIONE_TREASUREFACTORY_H

#include "Weapon.h"
#include "Potion.h"
#include <memory>
#include <string>

using namespace std;

class TreasureFactory {
public:
    static unique_ptr<Treasure> createWeapon(const string& name,  int power);
    static unique_ptr<Treasure> createPotion(const string& name,  int strength, bool health, bool strengthBonus);

    static unique_ptr<Treasure> createRandomTreasure();
};

#endif //PROGETTO_PROGRAMMAZIONE_TREASUREFACTORY_H
