//
// Created by Marco on 28/10/2024.
//

#include "../../headers/Enemy.h"

Enemy::Enemy(int strenght, string name, Texture texturel, Texture texture_FW) {


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

const string &Enemy::getName() const {
    return name;
}

void Enemy::setName(const string &name) {
    Enemy::name = name;
}

const Sprite &Enemy::getSpriteFw() const {
    return sprite_FW;
}

void Enemy::setSpriteFw(const Sprite &spriteFw) {
    sprite_FW = spriteFw;
}

const Texture &Enemy::getTextureFw() const {
    return texture_FW;
}

void Enemy::setTextureFw(const Texture &textureFw) {
    texture_FW = textureFw;
}

