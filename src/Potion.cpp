//
// Created by Marco on 21/10/2024.
//

#include "../headers/Potion.h"

Potion::Potion(const std::string& name, int strength, bool health, bool strengthBonus)
        : Treasure(name), strength(strength), health(health), strengthBonus(strengthBonus) {}

int Potion::getStrength() const {
    return strength;
}

bool Potion::isHealthPotion() const {
    return health;
}

bool Potion::hasStrengthBonus() const {
    return strengthBonus;
}
