//
// Created by Marco on 28/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENEMY_H
#define PROGETTO_PROGRAMMAZIONE_ENEMY_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Enemy {


protected:

    /*attributi nemico */
    string name;
    int Hp;
    int armour;
    int attack;
    int strenght;
    float x_, y_;

    /*variabili grafiche*/
    Texture texture;
    Sprite sprite;

    Texture texture_FW;
    Sprite sprite_FW;


public:

    explicit Enemy(int strenght, string name,Texture texturel,Texture texture_FW);

    virtual unique_ptr<Enemy> clone() const = 0;

    virtual void drawEnemy(RenderWindow &window) = 0;

    /*getter and setter*/



    int getHp() const;

    const Sprite &getSpriteFw() const;

    void setSpriteFw(const Sprite &spriteFw);

    const Texture &getTextureFw() const;

    void setTextureFw(const Texture &textureFw);

    void setHp(int hp);

    int getArmour() const;

    void setArmour(int armour);

    int getAttack() const;

    void setAttack(int attack);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    const Texture &getTexture() const;

    void setTexture(const Texture &texture);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);

    const string &getName() const;

    void setName(const string &name);
};


#endif //PROGETTO_PROGRAMMAZIONE_ENEMY_H
