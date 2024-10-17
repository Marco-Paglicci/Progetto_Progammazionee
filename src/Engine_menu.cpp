//
// Created by Marco on 17/10/2024.
//
#include <SFML/Graphics.hpp>
#include <string>
#include "../headers/Engine.h"

void Engine::menu() {

    window.clear(sf::Color::Black);

    sf::Font font;
    font.loadFromFile("../assets/Thor.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    sf::Font font2;
    font2.loadFromFile("../assets/spqri.ttf");
    sf::Text text2;
    text2.setFont(font2);
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold);

    float y = 100.f;

    text.setString(Title);
    text2.setString(Start);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(window.getSize().x / 2.f, y);
    window.draw(text);


    y += 75.f;
    bounds = text2.getLocalBounds();
    text2.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text2.setPosition(window.getSize().x / 2.f, y);
    window.draw(text2);


    window.display();
}