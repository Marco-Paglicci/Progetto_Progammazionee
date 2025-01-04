//
// Created by Marco on 22/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ROOM_H
#define PROGETTO_PROGRAMMAZIONE_ROOM_H


#include "EnemyFactory.h"
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class Room {

protected:

    //dimensioni
    int width_;
    int height_;

    //pareti Esterne e Interne
    RectangleShape top, bottom, left, right;
    vector<sf::RectangleShape> innerWalls;
    vector<sf::RectangleShape> OuterWalls;

    //Event Placer
    RectangleShape entrance;
    RectangleShape exit;
    RectangleShape enemy;
    bool haveEnemy;

    //objects
    EnemyFactory EF =  EnemyFactory();
    unique_ptr<Enemy> E = EnemyFactory::createEnemy(1,1);
    //inizializzo E con un mostro casuale per non creare problemi durante la compilazione
    //per problemi di non definizione della variabile

    //Graphics
    Sprite background_image;
    Texture texture;
    Texture background_texture;



public:

    Room(int width, int height);

    virtual void drawRoom(RenderWindow &window) = 0;

    virtual ~Room() = default;

    virtual unique_ptr<Room> clone() const = 0;

    const RectangleShape &getTop() const;

    const RectangleShape &getBottom() const;

    const RectangleShape &getLeft() const;

    const RectangleShape &getRight() const;

    const vector<sf::RectangleShape> &getInnerWalls() const;

    const vector<sf::RectangleShape> &getOuterWalls() const;

    const RectangleShape &getEntrance() const;

    const RectangleShape &getExit() const;

    const RectangleShape &getEnemy() const;

    void Generate_OuterWalls(); //I muri esterni sono condivisi ad ogni stanza , quindi fanno aprte della classe padre

    const unique_ptr<Enemy> &getE();

    int getHeight() const;

    int getWidth() const;

    void changeEntranceColor(const string& color);

    bool isHaveEnemy() const;

    void setHaveEnemy(bool haveEnemy);


};


#endif //PROGETTO_PROGRAMMAZIONE_ROOM_H
