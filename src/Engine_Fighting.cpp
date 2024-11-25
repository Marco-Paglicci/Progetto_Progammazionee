//
// Created by Marco on 23/10/2024.
//
#include <iostream>
#include "../headers/Engine.h"

////////////////////////////////////////////////////////////////////////////////
//Questo file è puramente per la separazione del codice e per una
//pulizia dei vari passaggi di Engine, contiene le funzioni che si occupano
//del setup e del codice grafico della finestra di combattimento
//la sua chiamata e utilizzo è gestito dallo StatePattern
/////////////////////////////////////////////////////////////////////
void Engine::fight_window_draw()
{

    window.clear(sf::Color::Black);

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
    for (int i = 0; i < (P->getHp() / 5); ++i) {

        sf::RectangleShape Bar(sf::Vector2f(30, 20));
        Bar.setPosition((window.getSize().x / 2) + (35 * i), fightText.getPosition().y);
        Bar.setFillColor(sf::Color::Green);
        Health_Bar.push_back(Bar);
    }

    for (auto &HP: Health_Bar) {
        window.draw(HP);
    }

    /*------------------Draw Entites -----------------------*/

    window.draw(Engine::getP()->getSpriteFw());

    window.display();

}
void Engine::fight_window_setup() {

    fight_fontText.loadFromFile("../assets/spqri.ttf");

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

    fightText.setString("fight!");
    runText.setString("RUN!");
    talkText.setString("talk?");
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

    cout << "FG room set up complete " << endl;


}



