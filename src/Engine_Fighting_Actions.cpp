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

    int attack_power  =  Engine::getP()->getW().getPower() * (rollD20()/10);
    cout << "Attack with " + to_string(attack_power) + " power !" << endl ;
    int damage = attack_power * (1 - ((Engine::getR()->getE()->getArmour()*rollD20())/100));
    cout << "you hit ! Dealing  " + to_string(damage) + " damage  !" << endl ;
    Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );


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

    int random = rand() % 21;
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