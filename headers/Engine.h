//
// Created by Marco on 17/10/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_ENGINE_H
#define PROGETTO_PROGRAMMAZIONE_ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

/*personaggi*/
#include "Personaggio.h"
#include "Knight.h"
#include "Mage.h"
#include "Thief.h"
#include "Room_Manager.h"

/*state pattern*/
#include "../src/Engine_StatePattern/headers/State.h"

class State_StartMenu;


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

    Sprite sprite;
    Texture background;

    /*States*/
    State* currentState ;
    bool start_menu = true;
    bool scelta_personaggio = false;
    bool scelta_effettuata = false;
    bool playing = false;
    bool fight = false;
    bool visible = true;
    bool AnimatingSnake = false;


    string classe = "";

    /*Objects*/

    //Utilizzare i puntatori è una contraddizione logica col fatto che il Personaggio appartiene
    //ad Engine e non può esister fuori da esso Utilizzare un std::unique_ptr al posto di un puntatore crudo
    // è una scelta che risolve molti dei problemi di gestione della memoria e indica chiaramente che Engine
    // possiede e gestisce il ciclo di vita del Personaggio.

    static unique_ptr<Personaggio> P ;

    Room_Manager RM =  Room_Manager(800, 400);

    static unique_ptr<Room> R ;


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


    std::vector<RectangleShape> body;
    RectangleShape head;

    /*scelta personaggio*/
    string scelta_Title = "CHOOSE YOUR HERO";
    string chose_Knight = "The Mighty Knight";
    string chose_Mage = "The Powerfull Mage";
    string chose_Thief = "The Sneaky Thief";
    string chose_Archer = "The Brave Archer";

    /*fighting window*/
    RectangleShape backgroundRect;
    RectangleShape Fight_Rect1;
    RectangleShape Fight_Rect2;
    Text fightText;
    Text runText;
    Text talkText;
    Text itemsText;

    vector<sf::RectangleShape> Health_Bar;
    Font fight_fontText;

    Text enemyNameText;
    vector<sf::RectangleShape> Enemy_Health_Bar;

    Clock blinkClock;
    bool isRed = false;

    /* message box */
    Text messageBox;                // Casella di testo per i messaggi
    Font font;                      // Font del testo
    static queue<std::string> messages;   // Coda per i messaggi da visualizzare
    Clock messageTimer;             // Timer per intervallo tra i messaggi
    float messageDelay = 2.0f;          // Ritardo tra un messaggio e il successivo


    /*cursore*/

    CircleShape cursor;
    bool cursor_position = "";
    int selectedOptionIndex = 0;

public:

    Engine();

    void input();

    void run();

    void menu();

    void scelta();

    void class_setup();

    /*state function*/
    void changeState(State* newState);

    /*snake animation fuctions*/
    void snakeAnimation();
    void reset();
    void drawSnake();
    void update(float dt);
    bool isFinished() const;

    bool isAnimatingSnake() const;
    void setAnimatingSnake(bool animatingSnake);

    /*getter and setter*/

    void setClasse(const string &classe);
    const string &getClasse() const;

    static const unique_ptr<Personaggio> &getP() ;
    const Room_Manager &getRm() const;

    static const unique_ptr<Room> &getR()  ;

    void setR(unique_ptr<Room> &r);

    State *getCurrentState() const;
    void setCurrentState(State *currentState);

    bool isStartMenu() const;
    void setStartMenu(bool startMenu);

    bool isSceltaPersonaggio() const;
    void setSceltaPersonaggio(bool sceltaPersonaggio);

    bool isFight() const;
    void setFight(bool fight);

    bool isSceltaEffettuata() const;
    void setSceltaEffettuata(bool sceltaEffettuata);

    bool isVisible() const;
    void setVisible(bool visible);


    const Sprite &getSprite() const;
    void setSprite(const Sprite &sprite);

    const Clock &getClock() const;

    RenderWindow & getWindow() ;

    void ResetClock(Clock clock);

    bool isCursorPosition() const;

    void setCursorPosition(bool cursorPosition);

    int getSelectedOptionIndex() const;

    void setSelectedOptionIndex(int selectedOptionIndex);



    /*fighitng window */
    void fight_window_setup();

    void fight_window_draw();

    static void attackAction(Engine &engine);

    static void defendAction(Engine &engine);

    static void useSpecialAction(Engine &engine);

    static void runAwayAction(Engine &engine);

    static void knight_special();

    static void thief_special();

    static void mage_special();

    static void enemy_attack_Action();

    static void enemy_defend_Action();

    static void enemy_turn();

    static int rollD20();

    static int enemyrollD20();

    /* message box */

    void initMessageBox();
    static void addMessage(const std::string& message);
    void updateMessages();
    void drawMessages(sf::RenderWindow& window);



};


#endif //PROGETTO_PROGRAMMAZIONE_ENGINE_H
