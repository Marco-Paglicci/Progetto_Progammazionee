//
// Created by Marco on 28/10/2024.
//

#include <iostream>
#include <random>
#include "../../headers/EnemyFactory.h"

//La definizione precedente al costruttore è necessaria per evitare problemi
//dato che gli elementi sono definiti come statici , questo codice aggiuntivo permetto al file.cpp
//di "ritrovare" le variabili necessarie al funzionamento del programma


string EnemyFactory::enemy_name;
vector<string> EnemyFactory::monster_names;
vector<string> EnemyFactory::minions_names;
vector<Texture> EnemyFactory::monster_texture;
Texture EnemyFactory::enemy_Texture;

//Definisco prematuramente la variabile dedicata all'operatore logico causale
std::mt19937 gen(std::random_device{}()); // Definisci una volta per tutte

EnemyFactory::EnemyFactory() {

    enemy_name = "default name";


    //riempo i vettori contenenti i nomi dei mostri
    monster_names    = {"Ombra Strisciante", "Golem di Pietra Antica", "Strega delle Caverne" , "Ragno della Cripta" , "Demone della Forgia Oscura"};
    minions_names = {"Sgherro dell’Oscurità","Predone delle Cripte","Cultista della Luna Nera","Sentinella di Ferro","Bruto delle Profondità"};

    //file names delle Texture
    vector<string> fileNames =
            {
                "../assets/enemy_texture/enemy_monster/ombra_strisciante.png",
                "../assets/enemy_texture/enemy_monster/golem_pietra.png",
                "../assets/enemy_texture/enemy_monster/strega.png",
                "../assets/enemy_texture/enemy_monster/ragno.png",
                "../assets/enemy_texture/enemy_monster/demone.png"
            };



    //carica le texture su monster_texture
    for(const auto& fileName : fileNames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            monster_texture.push_back(texture);
        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }

}



unique_ptr<Enemy> EnemyFactory::createEnemy(int enemyType, int strenght) {
    switch (enemyType) {
        case 1:
            return make_unique<Enemy_Monster>(strenght, selectName(enemyType),enemy_Texture);
        case 2:
            //todo finish to implement
            //return make_unique<ZigZag_Room>(width, height);
        case 3:
            //return make_unique<LongCorridor_Room>(width, height);
        default:
            cout << "Enemy type not recognized!" << std::endl;
            return nullptr;
    }
}

string EnemyFactory::selectName(int enemyType) {

    int i;

    switch (enemyType) {
        case 1:
             i = randomIndex();
            enemy_name = monster_names[i];
            enemy_Texture = monster_texture[i];
            cout << "Creating monster , index : " + to_string(i) + " name : " + enemy_name <<endl;


        case 2:
            enemy_name = minions_names[randomIndex()];


    }


    return enemy_name;
}

int EnemyFactory::randomIndex() {
    //sceglie un indice casuale all'interno del vettore
    uniform_int_distribution<> distr(0, monster_names.size() - 1);
    int randomIndex = distr(gen);

    return randomIndex;
}

