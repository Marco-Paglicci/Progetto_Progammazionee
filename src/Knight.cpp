//
// Created by Marco on 22/10/2024.
//


#include <iostream>
#include "../headers/Knight.h"

Knight::Knight(float x, float y, float size, sf::RenderWindow &window) : Personaggio(x, y, size, window)
{
    this->setHp(40);
    cout << " HP knight " + to_string(getHp()) << endl;
    this->setArmor(7);

    this->setSpecialReady(true);
    this->setTurnCounter(0);
    this->setSpecialRefresh(3);

    unique_ptr<Treasure> treasure = TreasureFactory::createWeapon("Sword",5);
    auto* weaponPtr = dynamic_cast<Weapon*>(treasure.get());
    if(weaponPtr)
    {
        W = make_unique<Weapon>(*weaponPtr);
    }else
    {
        cout << " Error in created Treasure in Knight " << endl;
    }
}

void Knight::special_attack() {
    if(this->getTurnCounter() == this->getSpecialRefresh())
    {
        this->setTurnCounter(0);
        if(!this->isSpecialReady())
        {
            this->setSpecialReady(true);
        }
    }
    if(!isSpecialReady())
    {
        cout << " SPECIAL NOT READY " << endl;
        return;
    }else
    {
        cout << "SPECIAL READY" << endl;
    }
}
