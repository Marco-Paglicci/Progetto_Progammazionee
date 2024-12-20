//
// Created by Marco on 17/10/2024.
//

#include <iostream>
#include "../headers/Engine.h"
#include "Engine_StatePattern/headers/State_StartMenu.h"




// Definizione dei membri statici altrimenti si creano problematiche
//nel programma in quanto non possono essere definiti all'interno del costruttore
//////////////////////////////////////////////////////////////////////////
unique_ptr<Personaggio> Engine::P = nullptr;
unique_ptr<Room> Engine::R = nullptr;
queue<std::string> Engine::messages = {};





Engine::Engine() {

    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Test",Style::Default);
    window.setFramerateLimit(FPS);

    /*texture and background*/
    background.loadFromFile("../assets/background/background.png");
    sprite.setTexture(background);
    sprite.setScale(4, 4);

    /*fightwindow graphic*/
    fight_window_setup();

    /*SnakeAnimation*/
    head.setFillColor(Color::Green);
    head.setSize(Vector2f(20, 20));
    head.setOrigin(head.getSize() / 2.f);
    head.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // inizializzazione del corpo del serpente
    for (int i = 0; i < numRectangles; i++) {
        RectangleShape rect = head;
        rect.setPosition(head.getPosition().x - i * head.getSize().x, head.getPosition().y);
        body.push_back(rect);
    }

    /*object setup*/
    P = make_unique<Personaggio>(100, 200, 30, window);

    //stanza e variabili di appoggio per il suo funzionamento
    R = RM.getRandomRoom();
    if (R == nullptr) {
        cout << "errore! Engine : getRandomRoom " << endl;
    }


    /*state*/
    currentState = new State_StartMenu();  //todo remove

}



void Engine::run() {

    /*----------------------GAMELOOP-----------------*/
   while(window.isOpen())
   {
        /*---------------STATE CHECKING----------------*/

        //Lo state pattern viene utilizzato per verificare condizioni specifiche
        //e modificare il  funzionamento dell'Engine

       if (currentState) {
           window.clear();
           currentState->draw(*this);
       }

   }


}

/*----------GETTER AND SETTER----------*/

bool Engine::isFinished() const {
    return finished;
}

RenderWindow &Engine::getWindow() {
    return window;
}

const Clock &Engine::getClock() const {
    return clock;
}


const string &Engine::getClasse() const {
    return classe;
}

void Engine::setClasse(const string &classe) {
    Engine::classe = classe;
}


void Engine::changeState(State *newState) {

    //Quando effettua un cambioi di stato , chiam le funzioni di ingresso e uscita degli stati (se implementate)
    if(currentState)
    {
        currentState->exit(*this);
        delete currentState; // Pulisce lo stato precedente
    }

    currentState = newState;
    if(currentState)
    {
        currentState->enter(*this);
    }

}

State *Engine::getCurrentState() const {
    return currentState;
}

void Engine::setCurrentState(State *currentState) {
    Engine::currentState = currentState;
}

bool Engine::isStartMenu() const {
    return start_menu;
}

void Engine::setStartMenu(bool startMenu) {
    start_menu = startMenu;
}

bool Engine::isSceltaPersonaggio() const {
    return scelta_personaggio;
}

void Engine::setSceltaPersonaggio(bool sceltaPersonaggio) {
    scelta_personaggio = sceltaPersonaggio;
}

bool Engine::isFight() const {
    return fight;
}

void Engine::setFight(bool fight) {
    Engine::fight = fight;
}

bool Engine::isSceltaEffettuata() const {
    return scelta_effettuata;
}

void Engine::setSceltaEffettuata(bool sceltaEffettuata) {
    scelta_effettuata = sceltaEffettuata;
}

bool Engine::isVisible() const {
    return visible;
}

void Engine::setVisible(bool visible) {
    Engine::visible = visible;
}

const Sprite &Engine::getSprite() const {
    return sprite;
}

void Engine::setSprite(const Sprite &sprite) {
    Engine::sprite = sprite;
}


void Engine::ResetClock(Clock clock) {
    clock.restart();
}

const unique_ptr<Personaggio> &Engine::getP()  {
    return P;
}


const Room_Manager &Engine::getRm() const {
    return RM;
}

const unique_ptr<Room> &Engine::getR()  {
    return R;
}

void Engine::setR(unique_ptr<Room> &r) {
    R = std::move(r);
}

bool Engine::isAnimatingSnake() const {
    return AnimatingSnake;
}

void Engine::setAnimatingSnake(bool animatingSnake) {
    AnimatingSnake = animatingSnake;
}

bool Engine::isCursorPosition() const {
    return cursor_position;
}

void Engine::setCursorPosition(bool cursorPosition) {
    cursor_position = cursorPosition;
}

int Engine::getSelectedOptionIndex() const {
    return selectedOptionIndex;
}

void Engine::setSelectedOptionIndex(int selectedOptionIndex) {
    Engine::selectedOptionIndex = selectedOptionIndex;
}



void Engine::class_setup() {

        if (classe == "knight") {
            cout << "Class Chosen ! : " + classe << endl;
            P = make_unique<Knight>(100, 200, 30, window);

        } else if (classe == "mage") {
            cout << "Class Chosen ! : " + classe << endl;
            P = make_unique<Mage>(100, 200, 30, window);
        } else if (classe == "thief") {
            cout << "Class Chosen ! : " + classe << endl;
            P = make_unique<Thief>(100, 200, 30, window);
        } else {
            cout<< "Errore selezione personaggio" << endl;
        }

        P->setClasse(classe);
        P->setTexture(classe);

}






