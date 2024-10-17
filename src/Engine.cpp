//
// Created by Marco on 17/10/2024.
//

#include "../headers/Engine.h"

Engine::Engine() {

    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Test",Style::Default);
    window.setFramerateLimit(FPS);

    /*SnakeAnimation*/
    head.setFillColor(Color::Green);
    head.setSize(Vector2f(20, 20));
    head.setOrigin(head.getSize() / 2.f);
    head.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // inizializzazione del corpo del serpente
    for (int i = 0; i < numRectangles; i++) {
        RectangleShape rect = head;
        rect.setPosition(head.getPosition().x - i * head.getSize().x, head.getPosition().y);
        body.push_back(rect);
    }


    //stanza e variabili di appoggio per il suo funzionamento
    Room room(800, 400);
}



void Engine::run() {

    sf::Texture background;
    background.loadFromFile("../assets/background/background.png");
    Sprite sprite;
    sprite.setTexture(background);
    sprite.setScale(4, 4);

    /*----------------------GAMELOOP-----------------*/
   while(window.isOpen())
   {

       if (startMenu) {

           if (clock.getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
           {
               visible = !visible; // invertiamo la visibilità del testo
               clock.restart(); // riavviamo l'orologio
           }
           if (visible)
               Engine_menu.draw();
           input();

       }


    //todo aggiungere snake animation dentro un while, e ricorda di fare window.display alla fine
   }


}

bool Engine::isFinished() const {
    return finished;
}

const RenderWindow &Engine::getWindow() const {
    return window;
}