//
// Created by Marco on 17/10/2024.
//
#include "../headers/Engine.h"

void Engine::input() {
    Event event{};

    while (window.pollEvent(event)) {

        /*-------------EVENTO CHIUSURA-------------*/

        if (event.type == Event::Closed)
            window.close();

        //controlliamo input (controllo input da tastiera)
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
        if (startMenu) {
            if (event.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed((Keyboard::Enter))) {
                    startMenu = false;
                    scelta_personaggio = true;

                }
            }
        }

        /*----------------SCELTA PERSONAGGIO---------------*/



        if (scelta_personaggio) {
            if (event.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed((Keyboard::Num1))) {
                    scelta_personaggio = false;
                    Engine::classe = "knight";
                    choise_done = true;
                }
                if (Keyboard::isKeyPressed((Keyboard::Num2))) {
                    scelta_personaggio = false;
                    Engine::classe = "thief";
                    choise_done = true;
                }
                if (Keyboard::isKeyPressed((Keyboard::Num3))) {
                    scelta_personaggio = false;
                    Engine::classe = "Mage";
                    choise_done = true;
                }

                if (Keyboard::isKeyPressed((Keyboard::Escape))) {
                    window.close();

                }
            }
        }

        /*---------------COMBATTIMENTO------------------*/
        if (fight) {
            if (event.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed(Keyboard::F)) {
                    fight = false;
                }
            }
        }

    }
}


