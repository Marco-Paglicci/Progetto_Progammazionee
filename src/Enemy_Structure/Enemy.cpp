//
// Created by Marco on 28/10/2024.
//

#include "../../headers/Enemy.h"

Enemy::Enemy(int strenght, string name, Texture texture) {

}


/*getter and setter*/

int Enemy::getHp() const {
    return Hp;
}

void Enemy::setHp(int hp) {
    Hp = hp;
}

int Enemy::getArmour() const {
    return armour;
}

void Enemy::setArmour(int armour) {
    Enemy::armour = armour;
}

int Enemy::getAttack() const {
    return attack;
}

void Enemy::setAttack(int attack) {
    Enemy::attack = attack;
}

float Enemy::getX() const {
    return x_;
}

void Enemy::setX(float x) {
    x_ = x;
}

float Enemy::getY() const {
    return y_;
}

void Enemy::setY(float y) {
    y_ = y;
}

const Texture &Enemy::getTexture() const {
    return texture;
}

void Enemy::setTexture(const Texture &texture) {
    Enemy::texture = texture;
}

const Sprite &Enemy::getSprite() const {
    return sprite;
}

void Enemy::setSprite(const Sprite &sprite) {
    Enemy::sprite = sprite;
}




