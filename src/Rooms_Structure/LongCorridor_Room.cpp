//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../../headers/LongCorridor_Room.h"

LongCorridor_Room::LongCorridor_Room(int width, int height) : Room(width,height) {

    genera_LongCorridor();
    this->setHaveEnemy(false);
}

void LongCorridor_Room::genera_LongCorridor() {

    Room::Generate_OuterWalls();
    generate_InnerWalls();


}

void LongCorridor_Room::drawRoom(sf::RenderWindow &window) {

    window.draw(background_image);
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);


    // da rimuovere o no dipendentemente se si vogliono visualzzare i muri ( senza Texture )

    /*
    for (const auto &wall: innerWalls) {
        window.draw(wall);
    }
     */

}

unique_ptr<Room> LongCorridor_Room::clone() const {
    return make_unique<LongCorridor_Room>(width_,height_);

}



void LongCorridor_Room::generate_InnerWalls() {

    float wallWidth = width_;
    float wallHight = height_ / 3;


    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("./assets/background/LONG_CORRIDOR.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);
    //GENERA I WALLS
    //1
    RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(0, 0);
    innerWalls.push_back(wall);
    //2
    RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition(0, (height_ / 3) * 2);
    innerWalls.push_back(wall2);

    //rende tutti i muri  su Innerwalls bianchi
    for (auto &wall: innerWalls) {
        wall.setFillColor(sf::Color::White);
        wall.setTexture(&texture);

    }

    // Crea l'ingresso e l'uscita


    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));
    Room::entrance.setFillColor(sf::Color::Green);
    Room::entrance.setPosition(width_ - (width_ / 10), height_ / 2);

    cout << "Generating long Room" << endl;

}



