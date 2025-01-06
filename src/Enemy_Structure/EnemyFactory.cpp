//
// Created by Marco on 28/10/2024.
//

#include <iostream>
#include <random>
#include "../../headers/EnemyFactory.h"
#include "../../headers/Enemy_Minion.h"
#include "../../headers/Enemy_Boss.h"

//La definizione precedente al costruttore è necessaria per evitare problemi
//dato che gli elementi sono definiti come statici , questo codice aggiuntivo permetto al file.cpp
//di "ritrovare" le variabili necessarie al funzionamento del programma


string EnemyFactory::enemy_name;
vector<string> EnemyFactory::monster_names;
vector<string> EnemyFactory::minions_names;
vector<Texture> EnemyFactory::monster_texture;
vector<Texture> EnemyFactory::monster_textureFW;
vector<Texture> EnemyFactory::minion_texture;
vector<Texture> EnemyFactory::minion_textureFW;
vector<Texture> EnemyFactory::boss_texture;
vector<Texture> EnemyFactory::boss_textureFW;
Texture EnemyFactory::enemy_Texture;
Texture EnemyFactory::enemy_FW_Texture;
;


//Definisco prematuramente la variabile dedicata all'operatore logico causale
std::mt19937 gen(std::random_device{}()); // Definisci una volta per tutte

EnemyFactory::EnemyFactory() {

    enemy_name = "default name";


    //riempo i vettori contenenti i nomi dei mostri
    monster_names    = {"Ombra Strisciante", "Golem di Pietra Antica", "Strega delle Caverne" , "Ragno della Cripta" , "Demone della Forgia Oscura"};
    minions_names = {"Sgherro dell’Oscurità","Predone delle Cripte","Cultista della Luna Nera","Sentinella di Ferro","Bruto delle Profondità"};

    //carico i file delle texture su vettori appositi per facilitare il caricamento da file e il passsaggio
    //della texture al nemico , carico per monster e minion siaq la texture principale sia il close up
    vector<string> monsters_fileNames =
            {
                "../assets/enemy_texture/enemy_monster/ombra_strisciante.png",
                "../assets/enemy_texture/enemy_monster/golem_pietra.png",
                "../assets/enemy_texture/enemy_monster/strega.png",
                "../assets/enemy_texture/enemy_monster/ragno.png",
                "../assets/enemy_texture/enemy_monster/demone.png"
            };


    vector<string> minion_fileNames =
            {
                    "../assets/enemy_texture/enemy_minion/sgherro.png",
                    "../assets/enemy_texture/enemy_minion/predone.png",
                    "../assets/enemy_texture/enemy_minion/cultista.png",
                    "../assets/enemy_texture/enemy_minion/sentinella.png",
                    "../assets/enemy_texture/enemy_minion/bruto.png"

            };

    vector<string> boss_filenames =
            {
                    "../assets/enemy_texture/enemy_boss/giovanni.png"
            };

    vector<string> monsters_FW_fileNames =
            {
                    "../assets/enemy_texture/monster_FW/ombra_FW.png",
                    "../assets/enemy_texture/monster_FW/golem_FW.png",
                    "../assets/enemy_texture/monster_FW/strega_FW.png",
                    "../assets/enemy_texture/monster_FW/ragno_FW.png",
                    "../assets/enemy_texture/monster_FW/demone_FW.png"

            };

    vector<string> minion_FW_fileNames =
            {
                    "../assets/enemy_texture/minion_FW/sgherro_FW.png",
                    "../assets/enemy_texture/minion_FW/predone_FW.png",
                    "../assets/enemy_texture/minion_FW/cultista_FW.png",
                    "../assets/enemy_texture/minion_FW/sentinella_FW.png",
                    "../assets/enemy_texture/minion_FW/bruto_FW.png"

            };

    vector<string> boss_FW_filenames =
            {
                    "../assets/enemy_texture/enemy_boss_FW/boss_FW.png"
            };

    //carica le texture dai file su vettori di texture, si utilizza load from file e l'apposito ciclo
    //for each

    for(const auto& fileName : monsters_fileNames)
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

    for(const auto& fileName : minion_fileNames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            minion_texture.push_back(texture);

        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }

    for(const auto& fileName : boss_filenames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            boss_texture.push_back(texture);

        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }

    for(const auto& fileName : monsters_FW_fileNames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            monster_textureFW.push_back(texture);

        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }

    for(const auto& fileName : minion_FW_fileNames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            minion_textureFW.push_back(texture);
        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }

    for(const auto& fileName : boss_FW_filenames)
    {
        Texture texture;
        if(texture.loadFromFile(fileName))
        {
            boss_textureFW.push_back(texture);

        }else
        {
            cout<<"Errore caricamento texture" + fileName << endl;
        }
    }


}



unique_ptr<Enemy> EnemyFactory::createEnemy(int enemyType, int strenght) {

    cout << "creating enemy , type -----  " + to_string(enemyType) << endl;

    switch (enemyType) {
        case 1:
            return make_unique<Enemy_Monster>(strenght, selectName(enemyType),enemy_Texture,enemy_FW_Texture);
        case 2:
            return make_unique<Enemy_Minion>(strenght, selectName(enemyType),enemy_Texture,enemy_FW_Texture);
        case 3:
            return make_unique<Enemy_Boss>(strenght, selectName(enemyType),enemy_Texture,enemy_FW_Texture);
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
            enemy_FW_Texture = monster_textureFW[i];
            cout << "Creating monster , index : " + to_string(i) + " name : " + enemy_name <<endl;
            break;

        case 2:
            i = randomIndex();
            enemy_name = minions_names[i];
            enemy_Texture = minion_texture[i];
            enemy_FW_Texture = minion_textureFW[i];
            cout << "Creating minion, index : "  + to_string(i) + " name : " + enemy_name <<endl;
            break;

        case 3:
            enemy_name = "Paolo";
            enemy_Texture = boss_texture[0];
            enemy_FW_Texture = boss_textureFW[0];
            cout << "Creating boss , name : " + enemy_name <<endl;
            break;
        default:
            cout << "Enemy type not recognized!" << std::endl;
            break;

    }

    cout << "Enemy name generated " + enemy_name << endl;
    return enemy_name;
}

int EnemyFactory::randomIndex() {
    //sceglie un indice casuale all'interno del vettore
    /*
    uniform_int_distribution<> distr(0, monster_names.size() - 1);
    int randomIndex = distr(gen);
    */

    int randomIndex;

    int random = rand() % monster_names.size();
    randomIndex = random;

    return randomIndex;
}

