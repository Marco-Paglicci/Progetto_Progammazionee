//
// Created by Marco on 06/01/2025.
//

#include "../../headers/Enemy_Boss.h"

Enemy_Boss::Enemy_Boss(int strenght,  string name, const Texture &texture, const Texture &texture_FW) : Enemy(strenght, name,
                                                                                                              texture,texture_FW) {

    Hp = 40;
    armour = 7;
    attack = 10;

    sprite.setTexture(texture);
    sprite.setScale(2.7, 3);
    sprite_FW.setTexture(texture_FW);
    sprite_FW.setScale(5, 5);
    sprite_FW.setPosition(500, 0);

}



void Enemy_Boss::drawEnemy(RenderWindow &window) {
    sprite.setPosition(x_,y_);
    window.draw(sprite);

}

unique_ptr<Enemy> Enemy_Boss::clone() const {
    return make_unique<Enemy_Boss>(*this);
}
