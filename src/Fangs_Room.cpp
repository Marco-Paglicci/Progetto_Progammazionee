//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../headers/Fangs_Room.h"

Fangs_Room::Fangs_Room(int width, int height) : Room(width, height) {

    genera_Fangs();

}

void Fangs_Room::genera_Fangs() {

    float wallWidth = 30.f;
    float wallHight = height_ / 3;

    //svuota innerWalls dai muri precedenti e ne crea nuovi
    innerWalls.clear();
    background_texture.loadFromFile("../assets/background/background_FANGS.png");
    background_image.setTexture(background_texture);
    background_image.setScale(4, 4);
    //GENERA I WALLS
    //1
    RectangleShape wall(sf::Vector2f(wallWidth, wallHight));
    wall.setPosition(width_ / 4, 0);
    innerWalls.push_back(wall);
    //2
    RectangleShape wall2(sf::Vector2f(wallWidth, wallHight));
    wall2.setPosition(width_ / 4, height_ - (wallHight));
    innerWalls.push_back(wall2);
    //3
    RectangleShape wall3(sf::Vector2f(wallWidth, wallHight));
    wall3.setPosition((width_ / 4) * 3, 0);
    innerWalls.push_back(wall3);
    //4
    RectangleShape wall4(sf::Vector2f(wallWidth, wallHight));
    wall4.setPosition((width_ / 4) * 3, height_ - (wallHight));
    innerWalls.push_back(wall4);

    RectangleShape CenterCube(sf::Vector2f(wallHight, wallHight));
    CenterCube.setPosition(width_ / 2 - wallWidth * 2, (height_ / 3));
    innerWalls.push_back(CenterCube);

    cout << "Generating FANGS Room" << endl;
}

void Fangs_Room::drawRoom(RenderWindow &window) {

    window.draw(background_image);
    window.draw(top);
    window.draw(bottom);
    window.draw(left);
    window.draw(right);
    window.draw(entrance);
    window.draw(exit);
    window.draw(enemy);

    // da rimuovere o no dipendentemente se si vogliono visualzzare i muri ( senza Texture )

    /*
    for (const auto &wall: innerWalls) {
        window.draw(wall);
    }
    */


}
