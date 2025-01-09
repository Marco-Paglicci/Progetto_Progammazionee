//
// Created by Marco on 22/10/2024.
//

#include <iostream>
#include "../headers/State_CharacterSelection.h"
#include "../headers/State_Playing.h"

void State_CharacterSelection::handleInput(Engine &engine) {

    Event event{};
    while(engine.getWindow().pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed((Keyboard::Num1))) {
                engine.setClasse("knight");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();

                playEffect(engine);

                engine.changeState(new State_Playing());
            }
            if (Keyboard::isKeyPressed((Keyboard::Num2))) {
                engine.setClasse("thief");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();

                playEffect(engine);

                engine.changeState(new State_Playing());

            }
            if (Keyboard::isKeyPressed((Keyboard::Num3))) {
                engine.setClasse("mage");
                engine.setSceltaPersonaggio(false);
                engine.setSceltaEffettuata(true);
                engine.class_setup();

                playEffect(engine);

                engine.changeState(new State_Playing());

            }
            if (Keyboard::isKeyPressed((Keyboard::Escape))) {
                engine.getWindow().close();

            }
        }
    }

}

void State_CharacterSelection::draw(Engine &engine) {
    if (engine.getClock().getElapsedTime().asSeconds() > 0.5f) // impostiamo un intervallo di 0,5 secondi
    {
        engine.setVisible(!engine.isVisible());
        engine.ResetClock(engine.getClock());
    }
    if (engine.isVisible())
        engine.scelta();
    handleInput(engine);

}

void State_CharacterSelection::enter(Engine &engine)
{
    if (!engine.chose_soundtrack.openFromFile("./assets/audio/soundtracks/chose_soundtrack.ogg")) {
        cout << "Errore: impossibile caricare la traccia audio del menu!" << endl;
    } else {
        engine.chose_soundtrack.setLoop(false); // Riproduzione in loop
        engine.chose_soundtrack.setVolume(100); // Volume al 50%
        engine.chose_soundtrack.play();        // Avvia la musica
        cout << "Playing soundtrack" << endl;
    }

}

void State_CharacterSelection::exit(Engine &engine)
{
    engine.chose_soundtrack.stop();
}

void State_CharacterSelection::playEffect(Engine &engine) {

    engine.soundBuffer.loadFromFile("./assets/audio/effects/enter_sound.ogg");
    engine.chosed.setBuffer(engine.soundBuffer);
    engine.chosed.play();

    // Ottieni la durata del suono
    sf::Time soundDuration = engine.chosed.getBuffer()->getDuration();

    // Aspetta finché il suono non termina
    sf::Clock clock;
    while (clock.getElapsedTime() < soundDuration) {
        // Continua a eseguire il ciclo per mantenere il programma attivo
    }


}
