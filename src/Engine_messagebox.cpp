//
// Created by Marco on 27/11/2024.
//
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


void Engine::initMessageBox() {
    if (!font.loadFromFile("../assets/Thor.ttf")) {
        throw std::runtime_error("Font not loaded!");
    }
    messageBox.setFont(font);
    messageBox.setCharacterSize(20);
    messageBox.setFillColor(sf::Color::White);
    messageBox.setPosition(50, 50); // Posiziona sopra il personaggio
}

void Engine::addMessage(const std::string& message) {
    messages.push(message);
}

void Engine::updateMessages() {
    // Controlla se è passato abbastanza tempo per mostrare il prossimo messaggio
    if (!messages.empty() && messageTimer.getElapsedTime().asSeconds() >= messageDelay) {
        messageBox.setString(messages.front()); // Mostra il messaggio corrente
        messages.pop();                         // Rimuove il messaggio dalla coda
        messageTimer.restart();                 // Reset del timer
    }
}

void Engine::drawMessages(sf::RenderWindow& window) {
    if (!messages.empty()) {
        window.draw(messageBox);
    }
}

