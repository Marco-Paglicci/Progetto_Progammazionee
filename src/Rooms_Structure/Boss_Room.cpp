//
// Created by Marco on 05/01/2025.
//

#include "../../headers/Boss_Room.h"

Boss_Room::Boss_Room(int width, int height) : Room(width, height) {

    genera_Boss_Room();
    E = EnemyFactory::createEnemy(3,3);
    this->setHaveEnemy(true);

}

void Boss_Room::genera_Boss_Room() {

    Room::Generate_OuterWalls();
    generate_InnerWalls();
}

void Boss_Room::drawRoom(RenderWindow &window) {

    window.draw(background_image);
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);

    E->setX(enemy.getPosition().x-10);
    E->setY(enemy.getPosition().y-10);

    if(E->isAlive())
    {
        E->drawEnemy(window);
    }

}

void Boss_Room::generate_InnerWalls() {

    float wallWidth = 30.f;
    float wallHight = height_ / 3;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/background_BOSS.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);

    // non ha innerwalls

    Room::enemy.setSize(sf::Vector2f(60.f, 60.f));
    Room::enemy.setFillColor(sf::Color::Red);
    Room::enemy.setPosition(width_ / 2 -20, (height_ / 2) + 50 );

}

unique_ptr<Room> Boss_Room::clone() const {
    return make_unique<Boss_Room>(width_,height_);;
}

bool Boss_Room::isBossRoom() const {
    return boss_room;
}

void Boss_Room::setBossRoom(bool bossRoom) {
    boss_room = bossRoom;
}
