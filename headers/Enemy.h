//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemy {


private:

    /*attributi nemico */

    int Hp;
    int armour;
    int attack;
    int strenght;
    float x_, y_;

protected:

    /*variabili grafiche*/
    Texture texture;
    Sprite sprite;

public:

    explicit Enemy(int strenght);

    virtual unique_ptr<Enemy> clone() const = 0;



    /*getter and setter*/

    int getHp() const;

    void setHp(int hp);

    int getArmour() const;

    void setArmour(int armour);

    int getAttack() const;

    void setAttack(int attack);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);


};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_H
