//
// Created by Marco on 28/10/2024.
//

#include <iostream>
#include <random>
#include "../../headers/EnemyFactory.h"

string EnemyFactory::enemy_name;
vector<string> EnemyFactory::monster_names;
vector<string> EnemyFactory::minions_names;
vector<Texture> EnemyFactory::monster_texture;
Texture EnemyFactory::enemy_Texture;


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

    switch (enemyType) {
        case 1:
            enemy_name = monster_names[randomIndex()];
            enemy_Texture = monster_texture[randomIndex()];
        case 2:
            enemy_name = minions_names[randomIndex()];


    }


    return enemy_name;
}

int EnemyFactory::randomIndex() {
    //sceglie un indice casuale all'interno del vettore
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, monster_names.size() - 1);
    int randomIndex = distr(gen);

    return randomIndex;
}

