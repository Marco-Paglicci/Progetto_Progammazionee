//
// Created by Marco on 17/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENGINE_H
#define PROGETTO_PROGRAMMAZIONE_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf; //abbreviazione di sfml class per richimare la libreria piu veloemente (non bisogna scriverla)
using namespace std;

class Engine {

private:

    //Window
    RenderWindow window;
    Vector2f resolution;
    bool choise_done = false;
    const unsigned int FPS = 60;
    static const Time TimeperFrame;

    bool startMenu = true;
    bool scelta_personaggio = false;
    bool fight = false;
    bool visible = true;

    string classe = "";

    Personaggio p;
    Room r;

    //Menu//
    string Title = "Dungeon Adventure";
    string Start = "Start";

public:

    Engine();

    void input();

    void run();

    void menu();

    const RenderWindow &getWindow() const;

};


#endif //PROGETTO_PROGRAMMAZIONE_ENGINE_H
