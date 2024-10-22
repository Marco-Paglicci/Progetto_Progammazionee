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
    Weapon W ;
    string classe_;


    /*variabili grafiche*/
    Texture texture;
    Sprite sprite;

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

    //variabile per animazione
    int swap_frame = 0;
    int swap_frame_camminata = 0;
    string moving;

public:

    Personaggio(float x, float y, float size, RenderWindow &window);


    /*GETTER and SETTER */

    int getHp() const;

    void setHp(int hp);

    int getArmor() const;

    void setArmor(int armor);

    const Weapon &getW() const;

    void setW(const Weapon &w);

    const string &getClasse() const;

    void setClasse(const string &classe);

    const Texture &getTexture() const;

    void setTexture(const Texture &texture);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);


    /* FUNZIONI GRAFICHE */

    void Steady_Animate();

    void virtual Camminata_DX();

    void virtual Camminata_SX();

    void virtual Camminata_UP();

    void virtual Camminata_DOWN();

    void aggiornaPosizione();

    void Collision(string bordo);

    void setPosition(float x_, float y_);

    FloatRect getCollisionRect() const;

    string getCollisionDirection(const FloatRect &otherRect) const;

    static int getElapsedFrames();

    void draw();

};


#endif //PROGETTO_PROGRAMMAZIONE_PERSONAGGIO_H
