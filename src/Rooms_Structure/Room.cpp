//
// Created by Marco on 22/10/2024.
//

#include "../../headers/Room.h"
#include <unordered_map>
#include <iostream>

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

void Room::Generate_OuterWalls()  {

        // Crea i rettangoli che delimitano la stanza
        Room::top.setSize(sf::Vector2f(width_, 10.f));
        Room::bottom.setSize(sf::Vector2f(width_, 10.f));
        Room::left.setSize(sf::Vector2f(10.f, height_));
        Room::right.setSize(sf::Vector2f(10.f, height_));

        //imposta tetxture
        texture.loadFromFile("../assets/wall.png");
        //carica texture sui muri
        Room::top.setTexture(&texture);
        Room::top.setTextureRect(sf::IntRect(0, 0, 20, 30));
        Room::bottom.setTexture(&texture);
        Room::left.setTexture(&texture);
        Room::right.setTexture(&texture);

        Room::top.setFillColor(sf::Color::White);
        Room::bottom.setFillColor(sf::Color::White);
        Room::left.setFillColor(sf::Color::White);
        Room::right.setFillColor(sf::Color::White);

        Room::top.setPosition(0.f, 0.f);
        Room::bottom.setPosition(0.f, height_ - 10.f);
        Room::left.setPosition(0.f, 0.f);
        Room::right.setPosition(width_ - 10.f, 0.f);

        OuterWalls.push_back(top);
        OuterWalls.push_back(bottom);
        OuterWalls.push_back(left);
        OuterWalls.push_back(right);


}

const unique_ptr<Enemy> &Room::getE() {
    return E;
}

int Room::getHeight() const {
    return height_;
}

int Room::getWidth() const {
    return width_;
}

void Room::changeEntranceColor(const string &color)  {

    static const unordered_map<string, Color> colorMap = {
            {"Red", Color::Red},
            {"Green", Color::Green},
            {"Blue", Color::Blue},
            {"Yellow", Color::Yellow},
            {"White", Color::White},
            {"Black", Color::Black},
            {"Cyan", Color::Cyan},
            {"Magenta", Color::Magenta},
            {"Transparent",Color::Transparent}
    };

    auto it = colorMap.find(color);
    if (it != colorMap.end()) {
        entrance.setFillColor(it->second); // Cambia il colore del RectangleShape

    } else {
        cout << "Invalid color input: " << color << std::endl;
    }
}

bool Room::isHaveEnemy() const {
    return haveEnemy;
}

void Room::setHaveEnemy(bool haveEnemy) {
    Room::haveEnemy = haveEnemy;
}

int Room::getId() const {
    return id;
}

void Room::setId(int id) {
    Room::id = id;
}

bool Room::isBossRoom() const {
    return boss_room;
}

void Room::setBossRoom(bool bossRoom) {
    boss_room = bossRoom;
}



