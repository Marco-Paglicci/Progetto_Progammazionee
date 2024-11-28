//
// Created by Marco on 17/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_PERSONAGGIO_H
#define PROGETTO_PROGRAMMAZIONE_PERSONAGGIO_H
#include <SFML/Graphics.hpp>

#include "TreasureFactory.h"

using namespace sf;
using namespace std;

class Personaggio {

private:

    /*attributi personaggio*/
    int hp;
    int armor;


    sf::RenderWindow &window_;
    float x_, y_;

    float size_;
    sf::RectangleShape corpo_;
    string collisione;
    sf::RectangleShape bracciasx_;
    sf::RectangleShape bracciadx_;
    sf::RectangleShape gambasx_;
    sf::RectangleShape gambadx_;
    sf::CircleShape testa_;


    //variabile movimento
    bool key_pressed;
    bool steady = true;


protected:

    //sono quelle variabili private che devono essere visibili alle
    //classi derivate, per l'override di alcuni metodi

    string classe_;
    unique_ptr<Weapon> W;

    int armor_boost = 0;

    //variabile per animazione
    int swap_frame = 0;
    int swap_frame_camminata = 0;
    string moving;

    /*variabili grafiche*/
    Texture texture;
    Sprite sprite;

    Texture texture_FW;
    Sprite sprite_FW;

public:

    Personaggio(float x, float y, float size, RenderWindow &window);


    /*GETTER and SETTER */



    int getHp() const;

    const Texture &getTextureFw() const;

    void setTextureFw(const Texture &textureFw);

    const Sprite &getSpriteFw() const;

    void setSpriteFw(const Sprite &spriteFw);

    void setHp(int hp);

    int getArmor() const;

    void setArmor(int armor);

    const Weapon &getW() const;

    void setW(const Weapon &w);

    const string &getClasse() const;

    void setClasse(const string &classe);

    const Texture &getTexture() const;

    void setTexture(string classe_);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);

   Weapon* getWeapon() ;

   void setWeapon(std::unique_ptr<Weapon> newWeapon);

    int getArmorBoost() const;

    void setArmorBoost(int armorBoost);

    /* FUNZIONI GRAFICHE */

    void Steady_Animate();

    virtual void  Camminata_DX();

    virtual void  Camminata_SX();

    virtual void  Camminata_UP();

    virtual void  Camminata_DOWN();

    void aggiornaPosizione();

    void Collision(string bordo);

    void setPosition(float x_, float y_);

    FloatRect getCollisionRect() const;

    string getCollisionDirection(const FloatRect &otherRect) const;

    static int getElapsedFrames();

    void draw();



};


#endif //PROGETTO_PROGRAMMAZIONE_PERSONAGGIO_H
