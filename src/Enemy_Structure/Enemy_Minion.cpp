//
// Created by Marco on 21/11/2024.
//

#include "../../headers/Enemy_Minion.h"

unique_ptr<Enemy> Enemy_Minion::clone() const {
    return make_unique<Enemy_Minion>(*this);
}


Enemy_Minion::Enemy_Minion(int strenght,  string name, const Texture &texture, const Texture &texture_FW) : Enemy(strenght, name,
                                                                                         texture,texture_FW) {
    switch (strenght) {
        case 1:
            name = "Wounded " + name;
            Hp = 5;
            armour = 1;
            attack = 2;
        case 2:
            Hp = 9;
            armour = 2;
            attack = 3;
        case 3:
            name = "Angry " + name;
            Hp = 15;
            armour = 0;
            attack = 5;
    }

    sprite.setTexture(texture);
    sprite.setScale(2.7, 3);
}


void Enemy_Minion::drawEnemy(RenderWindow &window) {
    sprite.setPosition(x_,y_);
    window.draw(sprite);
}