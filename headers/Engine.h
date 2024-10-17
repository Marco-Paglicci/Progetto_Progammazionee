//
// Created by Marco on 17/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENGINE_H
#define PROGETTO_PROGRAMMAZIONE_ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>


using namespace sf; //abbreviazione di sfml class per richimare la libreria piu veloemente (non bisogna scriverla)
using namespace std;

class Engine {

private:

    /*Window*/
    RenderWindow window;
    Vector2f resolution;
    bool choise_done = false;
    const unsigned int FPS = 60;
    static const Time TimeperFrame;

    /*States*/
    bool startMenu = true;
    bool scelta_personaggio = false;
    bool fight = false;
    bool visible = true;

    string classe = "";

    /*Objects*/
    Personaggio p;
    Room r ;

    /*Menu*/
    string Title = "Dungeon Adventure";
    string Start = "Start";

    /*SnakeAnimation*/
    float speed = 0.2f ;  // velocità del serpente (in pixel al secondo)
    float timeElapsed = 0;  // tempo trascorso dall'ultimo aggiornamento
    bool finished = false;
    int numRectangles = 10;
    Clock clock;
    float dt = clock.restart().asSeconds();
    bool AnimatingSnake = false;


    std::vector<RectangleShape> body;
    RectangleShape head;





public:

    Engine();

    void input();

    void run();

    void menu();

    void snakeAnimation();
    void reset();
    void drawSnake();
    void update(float dt);

    bool isFinished() const;


    const RenderWindow &getWindow() const;

};


#endif //PROGETTO_PROGRAMMAZIONE_ENGINE_H
