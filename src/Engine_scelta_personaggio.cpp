//
// Created by Marco on 17/10/2024.
//
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"

void Engine::scelta() {
    window.clear(sf::Color::Black);
    //Font per il titolo e setting per la scritta
    sf::Font font2;
    font2.loadFromFile("../assets/spqri.ttf");
    sf::Text text;
    text.setFont(font2);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    //font per i nomi dei personaggi
    sf::Font name;
    name.loadFromFile("../assets/Thor.ttf");
    //cavaliere
    sf::Text knight;
    knight.setFont(name);
    knight.setCharacterSize(20);
    knight.setFillColor(sf::Color::White);
    knight.setStyle(sf::Text::Bold);
    knight.setString(Knight);
    //ladro
    sf::Text thief;
    thief.setFont(name);
    thief.setCharacterSize(20);
    thief.setFillColor(sf::Color::White);
    thief.setStyle(sf::Text::Bold);
    thief.setString(Thief);
    //mago
    sf::Text mage;
    mage.setFont(name);
    mage.setCharacterSize(20);
    mage.setFillColor(sf::Color::White);
    mage.setStyle(sf::Text::Bold);
    mage.setString(Mage);

    //archer
    sf::Text archer;
    archer.setFont(name);
    archer.setCharacterSize(20);
    archer.setFillColor(sf::Color::White);
    archer.setStyle(sf::Text::Bold);
    archer.setString(Archer);


    float y = 100.f;

    //posizione di TITLE
    text.setString(scelta_Title);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(window.getSize().x / 2.f, y);
    window.draw(text);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //posizione delle altre stringhe
    bounds = knight.getLocalBounds();
    knight.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    knight.setPosition(100, (window.getSize().y / 5) * 4);
    window.draw(knight);

    bounds = thief.getLocalBounds();
    thief.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    thief.setPosition(window.getSize().x / 4 + 100, (window.getSize().y / 5) * 4);
    window.draw(thief);

    bounds = mage.getLocalBounds();
    mage.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    mage.setPosition(window.getSize().x / 2 + 100, (window.getSize().y / 5) * 4);
    window.draw(mage);

    bounds = archer.getLocalBounds();
    archer.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    archer.setPosition(window.getSize().x - 100, (window.getSize().y / 5) * 4);
    window.draw(archer);

    //gli spostamenti relativi a x sono stati fatti ""a mano"" per gestire la dimensione del formato visivo
    //////////////////////////////////////////////////////////////////////////////////////////////////

    //impostazione immagine e posizione close-ip Knight
    sf::Texture Knight_closeup;
    Knight_closeup.loadFromFile("../assets/Character_Choose/Knight_closeup.png");
    sf::Sprite KNIGHT(Knight_closeup);
    KNIGHT.setScale(10, 10);
    KNIGHT.setPosition(-50, (window.getSize().y / 5));
    window.draw(KNIGHT);

    sf::Texture thief_closeup;
    thief_closeup.loadFromFile("../assets/Character_Choose/thief_closeup.png");
    sf::Sprite THIEF(thief_closeup);
    THIEF.setScale(10, 10);
    THIEF.setPosition(130, (window.getSize().y / 5));
    window.draw(THIEF);

    sf::Texture mage_closeup;
    mage_closeup.loadFromFile("../assets/Character_Choose/mage_closeup.png");
    sf::Sprite MAGE(mage_closeup);
    MAGE.setScale(10, 10);
    MAGE.setPosition(350, (window.getSize().y / 5));
    window.draw(MAGE);

    sf::Texture archer_closeup;
    archer_closeup.loadFromFile("../assets/Character_Choose/archer_closeup.png");
    sf::Sprite ARCHER(archer_closeup);
    ARCHER.setScale(10, 10);
    ARCHER.setPosition(550, (window.getSize().y / 5));
    window.draw(ARCHER);

    window.display();
}