//
// Created by Marco on 23/10/2024.
//
#include <iostream>
#include "../headers/Engine.h"

////////////////////////////////////////////////////////////////////////////////
//Questo file è puramente per la separazione del codice e per una             //
//pulizia dei vari passaggi di Engine, contiene le funzioni che si occupano   //
//del setup e del codice grafico della finestra di combattimento              //
//la sua chiamata e utilizzo è gestito dallo StatePattern                     //
////////////////////////////////////////////////////////////////////////////////

void Engine::fight_window_draw()
{

    window.clear(sf::Color::Black);

    //if special ready change font color

    if(P->isSpecialReady())
    {
        talkText.setFillColor(Color::Yellow);
    }else
    {
        talkText.setFillColor(Color::White);
    }

    window.draw(Fight_Rect2);
    window.draw(Fight_Rect1);
    window.draw(fightText);
    window.draw(runText);
    window.draw(talkText);
    window.draw(itemsText);




    // Disegna il cursore a seconda della posizione
    window.draw(cursor);

    // Posiziona il cursore accanto all'opzione selezionata
    switch (selectedOptionIndex) {
        case 0:
            cursor.setPosition(fightText.getPosition().x - 20, fightText.getPosition().y + 5);
            break;
        case 1:
            cursor.setPosition(runText.getPosition().x - 20, runText.getPosition().y + 5 );
            break;
        case 2:
            cursor.setPosition(talkText.getPosition().x - 20, talkText.getPosition().y + 5);
            break;
        case 3:
            cursor.setPosition(itemsText.getPosition().x - 20, itemsText.getPosition().y + 5 );
            break;
    }

    //disegno healthbar

    /*--------------------------player healtbar--------------------------------------------*/

    Health_Bar.clear();

    if (P->getHp() < 5) {
        sf::RectangleShape Bar(sf::Vector2f(30, 20));
        Bar.setFillColor(isRed ? sf::Color::Red : sf::Color::Transparent);
        Bar.setPosition(50, 50);
        Health_Bar.push_back(Bar);

        // Gestione del lampeggio
        if (blinkClock.getElapsedTime().asSeconds() > 0.3f) {
            isRed = !isRed;
            blinkClock.restart();
        }
    } else {
        for (int i = 0; i < (P->getHp() / 5); ++i) {

            sf::RectangleShape Bar(sf::Vector2f(30, 20));

            if ((P->getHp() / 5) <= 1) {
                Bar.setFillColor(sf::Color::Red);
            } else if ((P->getHp() / 5) == 2) {
                Bar.setFillColor(sf::Color::Yellow);
            } else {
                Bar.setFillColor(sf::Color::Green);
            }

            Bar.setPosition((window.getSize().x / 2) + (35 * i), fightText.getPosition().y);
            Health_Bar.push_back(Bar);
        }
    }



    for (auto &HP: Health_Bar) {
        window.draw(HP);
    }

    /*-------------------------enemy healtbar------------------- --------------------*/


    if( Engine::getR() != nullptr && Engine::getR()->getE() != nullptr )
    {
        enemyNameText.setString(Engine::getR()->getE()->getName());  // Nome del nemico


    }else
    {
        cout << "Enemy not founded" << endl;

    }


    Enemy_Health_Bar.clear();

    //Se gli hp sono inferiori ad una barra (<5)
    if (Engine::getR()->getE()->getHp() < 5) {
        sf::RectangleShape Bar(sf::Vector2f(30, 20));
        Bar.setFillColor(isRed ? sf::Color::Red : sf::Color::Transparent);
        Bar.setPosition(50, 50);
        Enemy_Health_Bar.push_back(Bar);

        // Gestione del lampeggio
        if (blinkClock.getElapsedTime().asSeconds() > 0.3f) {
            isRed = !isRed;
            blinkClock.restart();
        }

    } else {
        // Calcola la lunghezza della barra in base agli HP del nemico
        for (int i = 0; i < (Engine::getR()->getE()->getHp() / 5); ++i) {

            sf::RectangleShape Bar(sf::Vector2f(30, 20));
            if ((Engine::getR()->getE()->getHp() / 5) <= 1) {
                Bar.setFillColor(sf::Color::Red);
            } else if ((Engine::getR()->getE()->getHp() / 5) == 2) {
                Bar.setFillColor(sf::Color::Yellow);
            } else {
                Bar.setFillColor(sf::Color::Green);
            }
            // Posizione sotto il nemico
            Bar.setPosition(50 + (35 * i), 50);
            Enemy_Health_Bar.push_back(Bar);
        }
    }



    // Disegna la barra della salute del nemico
    for (auto &HP: Enemy_Health_Bar) {
        window.draw(HP);
    }






    /*------------------Draw Entites -----------------------*/
    window.draw(Engine::getP()->getSpriteFw());
    window.draw(Engine::getR()->getE()->getSpriteFw());


    /*----------------- Message Box --------------------------*/
    // Aggiorna i messaggi
    updateMessages();

    // Disegna la casella di testo dei messaggi
    drawMessages(window);

    //Il nome del nemico deve essere estratto dopo il set up della stanza altrimenti non verrà trovato nessun puntatore associato
    window.draw(enemyNameText); //disegna nome del nemico


    window.display();

}
void Engine::fight_window_setup() {

    fight_fontText.loadFromFile("./assets/spqri.ttf");

    fightText.setFont(fight_fontText);
    runText.setFont(fight_fontText);
    talkText.setFont(fight_fontText);
    itemsText.setFont(fight_fontText);

    fightText.setCharacterSize(20);
    runText.setCharacterSize(20);
    talkText.setCharacterSize(20);
    itemsText.setCharacterSize(20);

    fightText.setFillColor(sf::Color::White);
    runText.setFillColor(sf::Color::White);
    talkText.setFillColor(sf::Color::White);
    itemsText.setFillColor(sf::Color::White);

    fightText.setStyle(sf::Text::Bold);
    runText.setStyle(sf::Text::Bold);
    talkText.setStyle(sf::Text::Bold);
    itemsText.setStyle(sf::Text::Bold);

    fightText.setString("Attacca");
    runText.setString("Difenditi");
    talkText.setString("Speciale");
    itemsText.setString("items");

    /////////////////////////////////////////////////////////////////////////////////


    Fight_Rect2.setSize(sf::Vector2f(window.getSize().x, window.getSize().y / 5 + 20));
    Fight_Rect2.setPosition(0, window.getSize().y / 5 * 4 - 20);
    Fight_Rect2.setFillColor(sf::Color::White);


    Fight_Rect1.setSize(sf::Vector2f(window.getSize().x - 40, window.getSize().y / 5 - 20));
    Fight_Rect1.setPosition(20, window.getSize().y / 5 * 4);
    Fight_Rect1.setFillColor(sf::Color::Black);

    fightText.setOrigin(0, 0);
    fightText.setPosition(window.getSize().x / 20.f + 15, (window.getSize().y / 5) * 4 + 20);

    runText.setOrigin(0, 0);
    runText.setPosition(fightText.getPosition().x, fightText.getPosition().y + 40);

    talkText.setOrigin(0, 0);
    talkText.setPosition(fightText.getPosition().x + 170, fightText.getPosition().y);

    itemsText.setOrigin(0, 0);
    itemsText.setPosition(fightText.getPosition().x + 170, fightText.getPosition().y + 40);

    cursor.setRadius(5);
    cursor.setFillColor(sf::Color::Red);
    cursor.setPosition(fightText.getPosition().x - 20, fightText.getPosition().y);

    // Configura il font per il nome del nemico
    enemyNameText.setFont(fight_fontText);
    enemyNameText.setCharacterSize(15);
    enemyNameText.setFillColor(sf::Color::White);
    enemyNameText.setStyle(sf::Text::Bold);

    // Posiziona il nome sopra il nemico (regola la posizione a seconda delle esigenze)
    enemyNameText.setPosition(50  , 100  );

    initMessageBox(); // inizializzo la casella di testo per messaggio

    cout << "FG room set up complete " << endl;


}



