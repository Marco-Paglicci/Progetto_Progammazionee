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
