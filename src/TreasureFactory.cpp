//
// Created by Marco on 21/10/2024.
//

#include "../headers/TreasureFactory.h"

#include <random>
#include <vector>


/*------RANDOM VALUES-----*/
int getRandomInt(int min, int max) {
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

bool getRandomBool() {
    return getRandomInt(0, 1) == 1;
}

/*--------------CREAZIONE TREASURE-------------*/
unique_ptr<Treasure> TreasureFactory::createWeapon(const string& name, int power) {
    return make_unique<Weapon>(name, power);
}

unique_ptr<Treasure> TreasureFactory::createPotion(const string& name, int strength, bool health, bool strengthBonus) {
    return make_unique<Potion>(name, strength, health, strengthBonus);
}

/*-------------CREAZIONE CASUALE-------------*/

unique_ptr<Treasure> TreasureFactory::createRandomTreasure() {

    // Pool di nomi casuali
    vector<string> Weapon_names = {"Excalibur",  "Dragon's Bane", "Mystic Elixir","Uncle Dave Tooth","Emperor Might","Stick","The Stabby"};


    string Weapon_randomName = Weapon_names[getRandomInt(0, Weapon_names.size() - 1)];
    string Potion_randomName ;


    // Genera casualmente se creare una Weapon o una Potion
    if (getRandomBool()) {

        // Crea una Weapon con forza casuale
        int randomPower = getRandomInt(5, 50); // Forza tra 5 e 50
        return createWeapon(Weapon_randomName,  randomPower);

    } else {

        // Crea una Potion con valori casuali
        int randomStrength = getRandomInt(1, 20); // Forza tra 1 e 20
        bool randomHealth = getRandomBool();
        bool randomStrengthBonus = getRandomBool();

        //Assegna il nome alla pozione in base all'effetto

        if(randomStrength>14 && randomHealth)
        {
            if(randomHealth)
                Potion_randomName = "Big Healing Potion";
            if(randomStrengthBonus)
                Potion_randomName = "Big Strength Potion";
            if(randomHealth && randomStrengthBonus)
                Potion_randomName = "Big Super Potion";

        }else if( randomStrength <= 14 && randomStrength>=8)
        {
            if(randomHealth)
                Potion_randomName = "Healing Potion";
            if(randomStrengthBonus)
                Potion_randomName = "Strength Potion";
            if(randomHealth && randomStrengthBonus)
                Potion_randomName = "Super Potion";

        }else if(randomStrength <8 )
        {
            if(randomHealth)
                Potion_randomName = "Small Healing Potion";
            if(randomStrengthBonus)
                Potion_randomName = "Small Strength Potion";
            if(randomHealth && randomStrengthBonus)
                Potion_randomName = "Small Super Potion";
        }

        return createPotion(Potion_randomName,  randomStrength, randomHealth, randomStrengthBonus);
    }
}
