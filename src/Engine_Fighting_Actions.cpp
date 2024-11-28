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
    int effective_armour = getR()->getE()->getArmour() + getR()->getE()->getArmorBoost();    //controlla se il nemico ha  un boost alle statistiche
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour*enemyrollD20())/100))));

    Engine::getR()->getE()->setArmorBoost(0);

    if(damage > 0)
    {
        addMessage("You hit! Dealing " + std::to_string(damage) + " damage!");

        Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );
    }else
    {
        addMessage("You missed the enemy entirely !");
    }


    addMessage("Enemy health = " + std::to_string(getR()->getE()->getHp()));


    //todo remove testing
    cout <<  "Weapon Attack :" + to_string(Engine::getP()->getWeapon()->getPower()) << endl ;
    cout << "Attack with " + to_string(attack_power) + " power !" << endl ;
    cout << "you hit ! Dealing  " + to_string(damage) + " damage  !" << endl ;
    cout << "Enemy health  =   " + to_string(Engine::getR()->getE()->getHp()) << endl;

    /* Durante il calcolo dei danni vengono usato numeri decimali
     * quindi è fondamentale riportare il valore in float, per assegnare
     * il dannop invece si riportas il valore numerico , arrotondando
     * all'intero più vicino per comodità */

    if (getR()->getE()->getHp() <= 0) {
        getR()->getE()->setIsAlive(false);
        addMessage("You killed the evil " + getR()->getE()->getName() + "!");
        cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
    }else
    {
        enemy_turn();
    }



}

void Engine::defendAction(Engine &engine) {
    std::cout << "Defending...\n";
    addMessage("You brace for impact, increasing your armor !");
    Engine::getP()->setArmorBoost(5);  // Aggiunge un bonus di armatura

    if ( getP()->getHp() < 5) {
        int heal = rand() % 3 + 2; // Guarisce tra 2 e 5 HP
        getP()->setHp(  getP()->getHp() + heal);
        addMessage(  "You can recover a little in a defensive stance !");
        addMessage( "(+ " + to_string(heal) + " HP)!");
    }

    enemy_turn();
}

void Engine::useItemAction(Engine &engine) {
    std::cout << "Using an item...\n";
    // Logica per usare un oggetto
}

void Engine::runAwayAction(Engine &engine) {
    std::cout << "Running away...\n";
    // Logica per fuggire
}


void Engine::enemy_turn() {

    if(!getR()->getE()->isAlive()) return;


    //controlla se player è ferito per il colpo di grazia
    if(getP()->getHp() <= 5)
    {
        addMessage(getR()->getE()->getName() + " sees you are weak and attacks viciously!");
        enemy_attack_Action();
        return;
    }

    // Controllo: se il nemico ha meno di 5 HP, proverà a difendersi almeno una volta
    static bool enemyTriedDefending = false; // Variabile per assicurarsi che si difenda almeno una volta
    if (getR()->getE()->getHp() < 5 && !enemyTriedDefending) {
        addMessage(getR()->getE()->getName() + " is severely injured and prepares to defend!");
        enemy_defend_Action();
        enemyTriedDefending = true; // Flag per indicare che ha provato a difendersi
        return;
    }

    // Comportamento standard: sceglie casualmente se attaccare o difendersi
    int decision = rand() % 100; // Numero casuale tra 0 e 99
    if (decision < 70) { // 70% di probabilità di attaccare
        addMessage(getR()->getE()->getName() + " decides to attack!");
        enemy_attack_Action();
    } else { // 30% di probabilità di difendersi
        addMessage(getR()->getE()->getName() + " takes a defensive stance!");
        enemy_defend_Action();
    }

}


void Engine::enemy_attack_Action() {

    float attack_power = static_cast<float>(getR()->getE()->getAttack() * (static_cast<float>(enemyrollD20()) / 10));
    int effective_armour = getP()->getArmor() + getP()->getArmorBoost();    //controlla se ho un boost alle statistiche
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour * rollD20()) / 100))));

    if(damage > 0)
    {
        addMessage("Enemy attacks! Dealing " + std::to_string(damage) + " damage!");
        Engine::getP()->setHp(Engine::getP()->getHp() - damage);

    }else
    {
        addMessage(getR()->getE()->getName() + " miss you !");

    }

    addMessage("Your health = " + std::to_string(Engine::getP()->getHp()));

    cout << "La tua vita adesso = " + to_string(Engine::getP()->getHp()) << endl;

    getP()->setArmorBoost(0);       //Alla fine del turno avversario resetta il il boost

    if (Engine::getP()->getHp() <= 0) {
        addMessage("You were defeated by the " + getR()->getE()->getName() + "...");
        std::cout << "Game Over!\n";
    }
}

void Engine::enemy_defend_Action() {

    // Incrementa temporaneamente l'armatura del nemico

    getR()->getE()->setArmorBoost(5);
    addMessage(getR()->getE()->getName() + " braces for your next attack, increasing its defense!");

    if ( getR()->getE()->getHp() < 5) {
        int heal = rand() % 3 + 2; // Guarisce tra 2 e 5 HP
        getR()->getE()->setHp( getR()->getE()->getHp() + heal);
        addMessage( getR()->getE()->getName() + " regains some health during its defensive stance ");
        addMessage( getR()->getE()->getName() + "(+ " + to_string(heal) + " HP)!");
    }

}


int Engine::rollD20() {

    Clock clock;

    int random = 0;

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
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

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
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