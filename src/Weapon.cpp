//
// Created by Marco on 21/10/2024.
//

#include "../headers/Weapon.h"


Weapon::Weapon(const std::string& name, int power)
        : Treasure(name), power(power) {}

int Weapon::getPower() const {
    return power;
}

void Weapon::setPower(int power) const {

}



