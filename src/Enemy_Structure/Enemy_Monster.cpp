//
// Created by Marco on 28/10/2024.
//

#include "../../headers/Enemy_Monster.h"



unique_ptr<Enemy> Enemy_Monster::clone() const {
    return make_unique<Enemy_Monster>(*this);
}

Enemy_Monster::Enemy_Monster(int strenght,  string name, const Texture &texture,const Texture &texture_FW) : Enemy(strenght, name,
                                                                                               texture,texture_FW) {
    switch (strenght) {
        case 1:
                name = "Wounded " + name;
                Hp = 10;
                armour = 1;
                attack = 3;
        case 2:
                Hp = 20;
                armour = 3;
                attack = 5;
        case 3:
                name = "Angry " + name;
                Hp = 25;
                armour = 5;
                attack = 8;
    }

    sprite.setTexture(texture);
    sprite.setScale(2.7, 3);
    sprite_FW.setTexture(texture_FW);
    sprite_FW.setScale(5,5);
    sprite_FW.setPosition(500,0);
}

void Enemy_Monster::drawEnemy(RenderWindow &window) {
    sprite.setPosition(x_,y_);
    window.draw(sprite);
}

