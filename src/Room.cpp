//
// Created by Marco on 22/10/2024.
//

#include "../headers/Room.h"

Room::Room(int width, int height) : width_(width), height_(height) {}

const RectangleShape &Room::getTop() const {
    return top;
}

const RectangleShape &Room::getBottom() const {
    return bottom;
}

const RectangleShape &Room::getLeft() const {
    return left;
}

const RectangleShape &Room::getRight() const {
    return right;
}

const vector<sf::RectangleShape> &Room::getInnerWalls() const {
    return innerWalls;
}

const vector<sf::RectangleShape> &Room::getOuterWalls() const {
    return OuterWalls;
}

const RectangleShape &Room::getEntrance() const {
    return entrance;
}

const RectangleShape &Room::getExit() const {
    return exit;
}

const RectangleShape &Room::getEnemy() const {
    return enemy;
}
