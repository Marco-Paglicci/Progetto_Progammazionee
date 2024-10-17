//
// Created by Marco on 17/10/2024.
//

#include "../headers/Engine.h"

Engine::Engine() {

    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Test",Style::Default);
    window.setFramerateLimit(FPS);




    //animazione Switch / stanze
    Clock clock;
    SnakeAnimation snake(window, 10, 0.2f);
    float dt = clock.restart().asSeconds();
    bool AnimatingSnake = false;

    //stanza e variabili di appoggio per il suo funzionamento
    Room room(800, 400);
}

const RenderWindow &Engine::getWindow() const {
    return window;
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
               menu.draw();
           input();

       }

   }


}