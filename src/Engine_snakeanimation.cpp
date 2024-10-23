//
// Created by Marco on 17/10/2024.
//
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"

void Engine::snakeAnimation() {

    update(dt);
    window.clear();
    drawSnake();
    if (isFinished() && !isFight()) {
        AnimatingSnake = false;
        R = RM.getRandomRoom();
        reset();
        P->setPosition(100, 200);
    }

}

void Engine::update(float dt) {
    timeElapsed += dt;
    //problemi causati dall'if di controllo che non entrava nella funzione
    timeElapsed -= 1.f / speed;

    // aggiornamento della posizione del serpente
    Vector2f prevPos = head.getPosition();

    head.move(head.getSize().x, 0);


    if (head.getPosition().x > window.getSize().x) {
        head.setPosition(-head.getSize().x / 2.f, head.getPosition().y);
        finished = true;
    }

    for (int i = 0; i < body.size(); i++) {
        Vector2f temp = body[i].getPosition();
        body[i].setPosition(prevPos);
        prevPos = temp;
    }
}

void Engine::drawSnake() {
    window.draw(head);
    for (const auto & i : body) {
        window.draw(i);
    }
}

void Engine::reset() {
    timeElapsed = 0;
    finished = false;
    body.clear();
    head.setOrigin(head.getSize() / 2.f);
    head.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    // inizializzazione del corpo del serpente
    for (int i = 0; i < numRectangles; i++) {
        RectangleShape rect = head;
        rect.setPosition(head.getPosition().x - i * head.getSize().x, head.getPosition().y);
        body.push_back(rect);
    }
}