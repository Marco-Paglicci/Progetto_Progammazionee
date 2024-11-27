//
// Created by Marco on 26/11/2024.
//
#include <iostream>
#include "../headers/Engine.h"
#include <random>

////////////////////////////////////////////////////////////////////////////////
//Questo file è puramente per la separazione del codice e per una
//pulizia dei vari passaggi di Engine, contiene le funzioni che si occupano
//delle varie azioni durante il fight
/////////////////////////////////////////////////////////////////////


void Engine::attackAction(Engine &engine) {

    float attack_power  =  (static_cast<float>(Engine::getP()->getWeapon()->getPower() * (static_cast<float>(rollD20())/10)));
    cout <<  "Weapon Attack :" + to_string(Engine::getP()->getWeapon()->getPower()) << endl ;
    cout << "Attack with " + to_string(attack_power) + " power !" << endl ;
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(Engine::getR()->getE()->getArmour()*rollD20())/100))));
    cout << "you hit ! Dealing  " + to_string(damage) + " damage  !" << endl ;
    Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );

    /* Durante il calcolo dei danni vengono usato numeri decimali
     * quindi è fondamentale riportare il valore in float, per assegnare
     * il dannop invece si riportas il valore numerico , arrotondando
     * all'intero più vicino per comodità */


    if(Engine::getR()->getE()->getHp() <= 0)
    {
        Engine::getR()->getE()->setIsAlive(false);
        cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
    }
}

void Engine::defendAction(Engine &engine) {
    std::cout << "Defending...\n";
    // Logica di difesa
}

void Engine::useItemAction(Engine &engine) {
    std::cout << "Using an item...\n";
    // Logica per usare un oggetto
}

void Engine::runAwayAction(Engine &engine) {
    std::cout << "Running away...\n";
    // Logica per fuggire
}

int Engine::rollD20() {

    int random = rand() % 21 + 1;
    cout << "You rolled a  " + to_string(random) + " !" << endl ;
    if(random == 20)
    {
        cout << "critical hit  !" << endl ;
    }
    if(random == 1)
    {
        cout << "critical FAILURE  !" << endl ;
    }
    return random;
}