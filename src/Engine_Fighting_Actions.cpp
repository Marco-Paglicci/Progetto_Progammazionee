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

    attack_sound();

    getP()->setTurnCounter(getP()->getTurnCounter() + 1); //alzo il contatore per la ricarica della special
    getP()->special_attack(); //se posso ricarico la special

    float attack_power  =  (static_cast<float>(Engine::getP()->getWeapon()->getPower() * (static_cast<float>(rollD20())/10)));
    int effective_armour = getR()->getE()->getArmour() + getR()->getE()->getArmorBoost();    //controlla se il nemico ha  un boost alle statistiche
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour*enemyrollD20())/100))));

    Engine::getR()->getE()->setArmorBoost(0);



    if(damage > 0)
    {
        addMessage("Colpito! hai inflitto  " + std::to_string(damage) + " danni!");

        Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );
    }else
    {
        addMessage("Hai mancato il nemico!");
    }


    addMessage("Salute nemico = " + std::to_string(getR()->getE()->getHp()));





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
        addMessage("Hai ucciso  " + getR()->getE()->getName() + "!");
        cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
        clearMessages();

    }else
    {

        enemy_turn();
    }



}

void Engine::defendAction(Engine &engine) {

    defend_sound();

    getP()->setTurnCounter(getP()->getTurnCounter() + 1);  //alzo il contatore per la ricarica della special
    getP()->special_attack(); //se posso ricarico la special

    std::cout << "Defending...\n";
    addMessage("Ti prepari , aumentando la tua difesa!");
    Engine::getP()->setArmorBoost(5);  // Aggiunge un bonus di armatura

    if ( getP()->getHp() < 5) {
        int heal = rand() % 3 + 2; // Guarisce tra 2 e 5 HP
        getP()->setHp(  getP()->getHp() + heal);
        addMessage(  "Recuperi un po di salute !");
        addMessage( "(+ " + to_string(heal) + " HP)!");
    }

    enemy_turn();
}

void Engine::useSpecialAction(Engine &engine) {

    if(dynamic_cast<class Knight*>(getP().get()))
    {
        cout << "trying special action " <<endl;
        knight_special();
    }
    if(dynamic_cast<class Thief*>(getP().get()))
    {
        cout << "trying special action " <<endl;
        thief_special();
    }
    if(dynamic_cast<class Mage*>(getP().get()))
    {
        cout << "trying special action " <<endl;
        mage_special();
    }

}



void Engine::runAwayAction(Engine &engine) {
    std::cout << "Running away...\n";
    // Logica per fuggire
}

void Engine::knight_special()
{
    if (!getP()->isSpecialReady()) {
        cout << "special no ready " <<endl;
        getP()->special_attack();
        special_notready_sound();
        addMessage("La tua speciale non è pronta!");

    }else
    {
        getP()->setSpecialReady(false);

        cout << "special  ready " <<endl;

        special_sound();    //Riproduce il suono per il power up

        addMessage("Carichi l'energia della spada");
        addMessage("PER DISTRUGGERE IL MALE !");

        attack_sound();
        attack_sound();
        attack_sound();

        //riproduce numerose volte il suono dell'attacco

        float attack_power  =  (static_cast<float>(Engine::getP()->getWeapon()->getPower() * (static_cast<float>(rollD20())/10))) * 2; //Raddoppia l'attacco

        int effective_armour = getR()->getE()->getArmour() + getR()->getE()->getArmorBoost();    //controlla se il nemico ha  un boost alle statistiche
        int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour*enemyrollD20())/100))));

        Engine::getR()->getE()->setArmorBoost(0);
        Engine::getP()->setSpecialReady(false);

        if(damage > 0)
        {
            addMessage("Hai colpito ! Infliggendo  " + std::to_string(damage) + " danni!");

            Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );
        }else
        {
            addMessage("Hai mancato il nemico!");
        }


        addMessage("Vita nemico = " + std::to_string(getR()->getE()->getHp()));

        if (getR()->getE()->getHp() <= 0) {
            getR()->getE()->setIsAlive(false);
            addMessage("Hai ucciso " + getR()->getE()->getName() + "!");
            addMessage("Con la tua mossa finale  !");
            cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
        }else
        {
            enemy_turn();
        }
    }
}

void Engine::thief_special()
{
    if (!getP()->isSpecialReady()) {
        cout << "special no ready " <<endl;
        getP()->special_attack();
        special_notready_sound();
        addMessage("Your special attack is not ready yet!");

    }else
    {
        getP()->setSpecialReady(false);

        special_sound();

        addMessage("Diventi tuttuno con l'ombra, sei oscurità !");
        addMessage("Sei praticamente invisibile !");

        defend_sound();

        Engine::getP()->setArmorBoost(20);  // Aggiunge un bonus di armatura (cosi alto ti rende incolpibile)

        if ( getP()->getHp() < 5) {
            int heal = rand() % 3 + 2; // Guarisce tra 2 e 5 HP
            getP()->setHp(  getP()->getHp() + heal);
            addMessage(  "Puoi recuperare un po di forze !");
            addMessage( "(+ " + to_string(heal) + " HP)!");
        }

        attack_sound();

        addMessage("Attacchi dall'ombra !");

        float attack_power  =  (static_cast<float>(Engine::getP()->getWeapon()->getPower() * (static_cast<float>(rollD20())/10))) ;

        int effective_armour = getR()->getE()->getArmour() + getR()->getE()->getArmorBoost();    //controlla se il nemico ha  un boost alle statistiche
        int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour*enemyrollD20())/100))));

        Engine::getR()->getE()->setArmorBoost(0);
        Engine::getP()->setSpecialReady(false);

        if(damage > 0)
        {
            addMessage("Colpito ! Infliggi  " + std::to_string(damage) + " danni!");

            Engine::getR()->getE()->setHp(Engine::getR()->getE()->getHp() - damage );
        }else
        {
            addMessage("Hai mancato il nemico !");
        }


        addMessage("salute nemico = " + std::to_string(getR()->getE()->getHp()));

        if (getR()->getE()->getHp() <= 0) {
            getR()->getE()->setIsAlive(false);
            addMessage("Hai ucciso  " + getR()->getE()->getName() + "!");
            addMessage(" dalle ombre !");
            cout << "You killed the evil " +  Engine::getR()->getE()->getName() << endl ;
        }else
        {
            enemy_turn();
        }
    }
}

void Engine::mage_special() {

    if (!getP()->isSpecialReady()) {
        cout << "special no ready " <<endl;
        getP()->special_attack();
        special_notready_sound();
        addMessage("Your special attack is not ready yet!");

    }else
    {

        getP()->setSpecialReady(false);

        special_sound();

        addMessage("Concentri la tua magia su te stesso !");
        addMessage("Recuperi energia !");

        magicHeal_sound();

        Engine::getP()->setArmorBoost(20);  // Aggiunge un bonus di armatura (cosi alto ti rende incolpibile)

        Engine::getP()->setHp(Engine::getP()->getHp() + 10);

        addMessage("Hai creato uno scudo !");
        addMessage("Hai recuperato 10 HP !");

        enemy_turn();
    }


}




/*--------------------------------------------------------------------------------------------------*/
////////////////////////////////////////// ENEMY ACTIONS /////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------*/


void Engine::enemy_turn() {

    if(!getR()->getE()->isAlive()) return;


    //controlla se player è ferito per il colpo di grazia
    if(getP()->getHp() <= 5)
    {
        lowHp_sound();
        addMessage(getR()->getE()->getName() + " ti vede debole , e ti attacca feroce!");
        enemy_attack_Action();
        return;
    }

    // Controllo: se il nemico ha meno di 5 HP, proverà a difendersi almeno una volta
    static bool enemyTriedDefending = false; // Variabile per assicurarsi che si difenda almeno una volta
    if (getR()->getE()->getHp() < 5 && !enemyTriedDefending) {
        addMessage(getR()->getE()->getName() + " è ferito e cerca di difendersi");
        enemy_defend_Action();
        enemyTriedDefending = true; // Flag per indicare che ha provato a difendersi
        return;
    }

    // Comportamento standard: sceglie casualmente se attaccare o difendersi
    int decision = rand() % 100; // Numero casuale tra 0 e 99
    if (decision < 70) { // 70% di probabilità di attaccare
        addMessage(getR()->getE()->getName() + " decide di attaccare");
        enemy_attack_Action();
    } else { // 30% di probabilità di difendersi
        addMessage(getR()->getE()->getName() + " si mette in difensiva!");
        enemy_defend_Action();
    }

}


void Engine::enemy_attack_Action() {

    attack_sound();


    float attack_power = static_cast<float>(getR()->getE()->getAttack() * (static_cast<float>(enemyrollD20()) / 10));
    int effective_armour = getP()->getArmor() + getP()->getArmorBoost();    //controlla se ho un boost alle statistiche
    int damage = static_cast<int>(round(attack_power * (1 - (static_cast<float>(effective_armour * rollD20()) / 100))));

    if(damage > 0)
    {
        addMessage("il nemico attacca! infligge  " + std::to_string(damage) + " danni !");
        Engine::getP()->setHp(Engine::getP()->getHp() - damage);

    }else
    {
        addMessage(getR()->getE()->getName() + " ti ha mancato  !");

    }

    addMessage("La tua salute = " + std::to_string(Engine::getP()->getHp()));

    cout << "La tua vita adesso = " + to_string(Engine::getP()->getHp()) << endl;

    getP()->setArmorBoost(0);       //Alla fine del turno avversario resetta il il boost

    if (Engine::getP()->getHp() <= 0) {
        gameover_sound();
        addMessage("Sei stato sconfitto da " + getR()->getE()->getName() + "...");

        std::cout << "Game Over!\n";
    }
}

void Engine::enemy_defend_Action() {

    // Incrementa temporaneamente l'armatura del nemico
    defend_sound();


    getR()->getE()->setArmorBoost(5);
    addMessage(getR()->getE()->getName() + " si prepara al tuo attacco !");
    addMessage(getR()->getE()->getName() + " aumenta la sua difesa !");

    if ( getR()->getE()->getHp() < 5) {
        int heal = rand() % 3 + 2; // Guarisce tra 2 e 5 HP
        getR()->getE()->setHp( getR()->getE()->getHp() + heal);
        addMessage( getR()->getE()->getName() + " recupera un po di salute ");
        addMessage( getR()->getE()->getName() + "(+ " + to_string(heal) + " HP)!");
    }

}


int Engine::rollD20() {

    Clock clock;

    int random = 0;

    dice_sound();

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        random = rand() % 20 + 1;
    }

    addMessage("hai lanciato un  " + std::to_string(random) + "!");
    if (random == 20) {
        addMessage("COLPO CRITICO!");
    } else if (random == 1) {
        addMessage("FALLIMENTO CRITICO!");
    }

    return random;
}

int Engine::enemyrollD20()
{
    Clock clock;

    int random = 0;

    dice_sound();

    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        random = rand() % 20 + 1;
    }

    addMessage("Il nemico ha lanciato " + std::to_string(random) + "!");
    if (random == 20) {
        addMessage("COLPO CRITICO NEMICO!");
    } else if (random == 1) {
        addMessage("FALLIMENTO CRITICO DEL NEMICO!");
    }

    return random;
}


/////////////////////////////////////////////////////////////////////////////////////////////
            /*                AUDIO EFFECTS                   */
////////////////////////////////////////////////////////////////////////////////////////////



void Engine::dice_sound()
{
    Sound dice_thrown;
    SoundBuffer dice_buffer;

    if(!dice_buffer.loadFromFile("../assets/audio/effects/dice_sound.ogg"))
    {
        cout << "Errore caricamento file dice sound" <<endl;
    }else
    {
        dice_thrown.setBuffer(dice_buffer);
        dice_thrown.play();

        Time soundDuration = dice_thrown.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }

}


void Engine::attack_sound()
{
    Sound attack;
    SoundBuffer attack_buffer;

    if(!attack_buffer.loadFromFile("../assets/audio/effects/attack_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        attack.setBuffer(attack_buffer);
        attack.play();

        Time soundDuration = attack.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}

void Engine::defend_sound() {

    Sound defend;
    SoundBuffer defend_buffer;

    if(!defend_buffer.loadFromFile("../assets/audio/effects/defend_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        defend.setBuffer(defend_buffer);
        defend.play();

        Time soundDuration = defend.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}

void Engine::special_sound() {
    Sound special;
    SoundBuffer special_buffer;

    if(!special_buffer.loadFromFile("../assets/audio/effects/powerReady_sound_v2.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        special.setBuffer(special_buffer);
        special.play();

        Time soundDuration = special.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}

void Engine::special_notready_sound() {

    Sound special;
    SoundBuffer special_buffer;

    if(!special_buffer.loadFromFile("../assets/audio/effects/notReady_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        special.setBuffer(special_buffer);
        special.play();

        Time soundDuration = special.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}



void Engine::lowHp_sound() {

    Sound lowHp;
    SoundBuffer lowHp_buffer;

    if(!lowHp_buffer.loadFromFile("../assets/audio/effects/lowHp_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        lowHp.setBuffer(lowHp_buffer);
        lowHp.play();

        Time soundDuration = lowHp.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}

void Engine::magicHeal_sound() {

    Sound magicHeal;
    SoundBuffer magicHeal_buffer;

    if(!magicHeal_buffer.loadFromFile("../assets/audio/effects/magicHeal_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        magicHeal.setBuffer(magicHeal_buffer);
        magicHeal.play();

        Time soundDuration = magicHeal.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}

void Engine::gameover_sound() {

    Sound gameover;
    SoundBuffer gameover_buffer;

    if(!gameover_buffer.loadFromFile("../assets/audio/effects/gameover_sound.ogg"))
    {
        cout << "Errore caricamento file attack_sound" <<endl;
    }else
    {
        gameover.setBuffer(gameover_buffer);
        gameover.play();

        Time soundDuration = gameover.getBuffer()->getDuration();


        Clock clock;
        while (clock.getElapsedTime() < soundDuration) {
            // Continua a eseguire il ciclo per mantenere il programma attivo
        }
    }
}
