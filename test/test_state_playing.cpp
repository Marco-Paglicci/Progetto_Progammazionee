//
// Created by Marco on 18/02/2025.
//
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"
#include "../src/Engine_StatePattern/headers/State_Playing.h"


TEST(StateTransitionTest, TransitionToAnimatingSnake) {

    sf::RenderWindow testWindow(sf::VideoMode(800, 600), "TestWindow", sf::Style::Close);

    Engine engine;
    engine.getR()->setHaveEnemy(true);

    auto& enemyPtr = const_cast<std::unique_ptr<Enemy>&>(engine.getR()->getE());
    enemyPtr = EnemyFactory::createEnemy(1,1);
    enemyPtr->setIsAlive(false);

    auto& entrance = const_cast<sf::RectangleShape&>(engine.getR()->getEntrance());
    entrance.setPosition(110.f, 210.f);               // Posizione scelta per il test
    entrance.setSize(sf::Vector2f(50.f, 50.f));        // Dimensione dell'entrata

    engine.getP()->setPosition(110.f, 210.f);

    engine.changeState(new State_Playing());

    engine.getCurrentState()->draw(engine);

    EXPECT_TRUE(engine.isAnimatingSnake());
}