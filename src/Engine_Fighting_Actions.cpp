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
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(Engine::getR()->getE()->getArmour()*rollD20())/100))));


    // Aggiungi messaggi alla casella di testo
    addMessage("Weapon Attack: " + std::to_string(getP()->getWeapon()->getPower()));
    addMessage("Attack with " + std::to_string(attack_power) + " power!");
    addMessage("You hit! Dealing " + std::to_string(damage) + " damage!");

    Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );
    addMessage("Enemy health = " + std::to_string(getR()->getE()->getHp()));


    //todo remove testing
    cout <<  "Weapon Attack :" + to_string(Engine::getP()->getWeapon()->getPower()) << endl ;
    cout << "Attack with " + to_string(attack_power) + " power !" << endl ;
    cout << "you hit ! Dealing  " + to_string(damage) + " damage  !" << endl ;
    cout << "Enemy healt  =   " + to_string(Engine::getR()->getE()->getHp()) << endl;
    /* Durante il calcolo dei danni vengono usato numeri decimali
     * quindi è fondamentale riportare il valore in float, per assegnare
     * il dannop invece si riportas il valore numerico , arrotondando
     * all'intero più vicino per comodità */

    if (getR()->getE()->getHp() <= 0) {
        getR()->getE()->setIsAlive(false);
        cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
        addMessage("You killed the evil " + getR()->getE()->getName() + "!");
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

    Clock clock;

    int random = 0;

    while (clock.getElapsedTime().asSeconds() < 2.0f) {
        random = rand() % 20 + 1;
    }

    addMessage("You rolled a " + std::to_string(random) + "!");
    if (random == 20) {
        addMessage("Critical hit!");
    } else if (random == 1) {
        addMessage("Critical FAILURE!");
    }

    return random;
}