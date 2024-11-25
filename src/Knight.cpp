//
// Created by Marco on 22/10/2024.
//


#include <iostream>
#include "../headers/Knight.h"

Knight::Knight(float x, float y, float size, sf::RenderWindow &window) : Personaggio(x, y, size, window), W("DefaultWeapon",1)
{
    this->setHp(40);
    cout << " HP knight " + getHp() << endl;
    this->setArmor(10);
    unique_ptr<Treasure> treasure = TreasureFactory::createWeapon("Sword",15);
    auto* weaponPtr = dynamic_cast<Weapon*>(treasure.get());
    if(weaponPtr)
    {
        W = *weaponPtr;
    }else
    {
        cout << " Error in created Treasure in Knight " << endl;
    }
}
