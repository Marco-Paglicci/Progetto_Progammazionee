//
// Created by Marco on 18/02/2025.
//

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"
#include "../src/Engine_StatePattern/headers/State_StartMenu.h"
#include "../src/Engine_StatePattern/headers/State_Playing.h"
#include "../src/Engine_StatePattern/headers/State_Fighting.h"


TEST(SoundTest, TranstionSoundStartMenu) {

    Engine engine;
    engine.changeState(new State_StartMenu());


    ASSERT_EQ(engine.menu_soundtrack.getStatus(), sf::Sound::Playing);
}

TEST(SoundTest, TranstionSoundChosePlayer) {

    Engine engine;
    engine.changeState(new State_CharacterSelection());

    ASSERT_EQ(engine.chose_soundtrack.getStatus(), sf::Sound::Playing);
}

TEST(SoundTest, TranstionSoundPlaying) {

    Engine engine;
    engine.changeState(new State_Playing());

    ASSERT_EQ(engine.play_soundtrack.getStatus(), sf::Sound::Playing);
}

TEST(SoundTest, TransitionSoundFIghting)
{

    Engine engine;
    engine.changeState(new State_Fighting());

    ASSERT_EQ(engine.fight_soundtrack.getStatus(), sf::Sound::Playing);
}