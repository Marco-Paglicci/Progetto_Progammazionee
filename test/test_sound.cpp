//
// Created by Marco on 18/02/2025.
//

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"
#include "../src/Engine_StatePattern/headers/State_StartMenu.h"


TEST(SoundTest, TranstionSoundStartMenu) {

    Engine engine;
    engine.changeState(new State_StartMenu());
    engine.getCurrentState()->enter(engine);

    ASSERT_EQ(engine.menu_soundtrack.getStatus(), sf::Sound::Playing);
}