//
// Created by Marco on 21/11/2024.
//

#include <iostream>
#include "../../headers/Enemy_Minion.h"

unique_ptr<Enemy> Enemy_Minion::clone() const {
    return make_unique<Enemy_Minion>(*this);
}


Enemy_Minion::Enemy_Minion(int strenght,  string name, const Texture &texture, const Texture &texture_FW) : Enemy(strenght, name,
                                                                                         texture,texture_FW) {
    switch (strenght) {
        case 1:
            this->setName(name + " ferito") ;
            Hp = 10;
            armour = 1;
            attack = 2;
            break;
        case 2:
            this->setName(name);
            Hp = 10 ;
            armour = 1;
            attack = 3;
            break;
        case 3:
            this->setName(name + " infuriato");
            Hp = 15;
            armour = 1;
            attack = 5;
            break;
    }


    cout << "forza = " + to_string(strenght) + " nome = " + this->getName() <<endl;

    sprite.setTexture(texture);
    sprite.setScale(2.7, 3);
    sprite_FW.setTexture(texture_FW);
    sprite_FW.setScale(5,5);
    sprite_FW.setPosition(500,0);
}


void Enemy_Minion::drawEnemy(RenderWindow &window) {
    sprite.setPosition(x_,y_);
    window.draw(sprite);
}