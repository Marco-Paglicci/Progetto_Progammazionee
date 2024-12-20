//
// Created by Marco on 20/12/2024.
//
#include <SFML/Graphics.hpp>
#include <string>
#include "../headers/Engine.h"

void Engine::game_over() {

    window.clear(sf::Color::Black);

    Font font;
    font.loadFromFile("../assets/Thor.ttf");
    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    Font font2;
    font2.loadFromFile("../assets/spqri.ttf");
    Text subtext;
    subtext.setFont(font2);
    subtext.setCharacterSize(22);
    subtext.setFillColor(sf::Color::White);
    subtext.setStyle(sf::Text::Bold);

    float y = 160.f;

    text.setString("Game Over");

    FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(window.getSize().x / 2.f, y);
    window.draw(text);

    subtext.setString("Press Enter to retry");

    y += 75.f;
    bounds = subtext.getLocalBounds();
    subtext.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    subtext.setPosition(window.getSize().x / 2.f, y);
    window.draw(subtext);

    window.display();

}