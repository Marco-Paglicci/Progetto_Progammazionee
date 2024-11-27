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
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(Engine::getR()->getE()->getArmour()*enemyrollD20())/100))));


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
    }else
    {
        enemy_attack_Action();
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


void Engine::enemy_attack_Action() {
    if(!getR()->getE()->isAlive()) return;

    float attack_power = static_cast<float>(getR()->getE()->getAttack() * (static_cast<float>(enemyrollD20()) / 10));
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(Engine::getP()->getArmor() * rollD20()) / 100))));
    addMessage("Enemy attacks! Dealing " + std::to_string(damage) + " damage!");
    Engine::getP()->setHp(Engine::getP()->getHp() - damage);
    addMessage("Your health = " + std::to_string(Engine::getP()->getHp()));

    cout << "La tua vita adesso = " + to_string(Engine::getP()->getHp()) << endl;

    if (Engine::getP()->getHp() <= 0) {
        addMessage("You were defeated by the " + getR()->getE()->getName() + "...");
        std::cout << "Game Over!\n";
    }
}


int Engine::rollD20() {

    Clock clock;

    int random = 0;

    while (clock.getElapsedTime().asSeconds() < 1.5f) {
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

int Engine::enemyrollD20()
{
    Clock clock;

    int random = 0;

    while (clock.getElapsedTime().asSeconds() < 2.0f) {
        random = rand() % 20 + 1;
    }

    addMessage("Enemy rolled a " + std::to_string(random) + "!");
    if (random == 20) {
        addMessage("Enemy Critical hit!");
    } else if (random == 1) {
        addMessage("Enemy Critical FAILURE!");
    }

    return random;
}