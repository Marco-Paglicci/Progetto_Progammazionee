//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../../headers/ZigZag_Room.h"

ZigZag_Room::ZigZag_Room(int width, int height): Room(width,height) {


    genera_ZigZag();
    Enemy = EnemyFactory::createEnemy(1,2);


}


void ZigZag_Room::genera_ZigZag() {

    Room::Generate_OuterWalls();
    generate_InnerWalls();

}

void ZigZag_Room::drawRoom(sf::RenderWindow &window) {

    window.draw(background_image);
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);
    window.draw(exit);
    window.draw(enemy);

    // da rimuovere o no dipendentemente se si vogliono visualzzare i muri ( senza Texture )
    //todo : far visualizzzare ENEMY
    Enemy->setX(enemy.getPosition().x-55);
    Enemy->setY(enemy.getPosition().y-55);

    Enemy->drawEnemy(window);

    for (const auto &wall: innerWalls) {
        window.draw(wall);
    }
    //todo:comment this
}

unique_ptr<Room> ZigZag_Room::clone() const {
    return make_unique<ZigZag_Room>(width_,height_);
}


void ZigZag_Room::generate_InnerWalls() {

    float wallWidth = 30.f;
    float wallHight = height_ - 150.f;



    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/background_ZIGZAG.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);

    //GENERA I WALLS
    //1
    sf::RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(width_ / 5, -100);
    innerWalls.push_back(wall);
    //2
    sf::RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition((width_ / 2), height_ - wallHight);
    innerWalls.push_back(wall2);
    //3
    sf::RectangleShape wall3(sf::Vector2f(wallWidth, wallHight));
    wall3.setPosition((width_ / 5) * 4, -100);
    innerWalls.push_back(wall3);

    //rende tutti i muri  su Innerwalls rossi
    //FOR DEBUG

    for (auto &wall: innerWalls) {
        wall.setFillColor(sf::Color::Red);

    }


    // Crea l'ingresso
    Room::entrance.setSize(sf::Vector2f(20.f, 20.f));
    Room::entrance.setFillColor(sf::Color::Green);
    Room::entrance.setPosition(width_ - (width_ / 10), height_ / 2);
}
