//
// Created by Marco on 28/10/2024.
//

#include "../../headers/Enemy_Monster.h"



unique_ptr<Enemy> Enemy_Monster::clone() const {
    return make_unique<Enemy_Monster>(*this);
}

Enemy_Monster::Enemy_Monster(int strenght, const string name, const Texture &texture) : Enemy(strenght, name,
                                                                                               texture) {}
