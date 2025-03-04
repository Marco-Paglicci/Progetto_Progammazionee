//
// Created by Marco on 20/02/2025.
//
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../headers/Engine.h"

TEST(EngineTest, InitMessageBox) {

    Engine engine;
    engine.fight_window_setup();
    Text messageBox = engine.getMessageBox();
    EXPECT_EQ(messageBox.getCharacterSize(), 20);
    EXPECT_EQ(messageBox.getFillColor(), Color::White);

    Vector2 pos = messageBox.getPosition();
    EXPECT_EQ(pos.x, engine.getWindow().getSize().x / 2);
    EXPECT_EQ(pos.y, engine.getWindow().getSize().y / 2);
}

TEST(EngineTest, UpdateMessage)
{
    Engine engine;
    string text = "test message";

    engine.setMessageDelay(0);
    engine.addMessage(text);
    engine.updateMessages();

    Text test = engine.getMessageBox();
    EXPECT_EQ(test.getString(), text);

    EXPECT_EQ(engine.getMessages().size(), 0);

}
TEST(EngineTest,ClearMessage)
{
    Engine engine;
    engine.addMessage("Messaggio 1");
    engine.addMessage("Messaggio 2");

    engine.clearMessages();

    EXPECT_EQ(engine.getMessages().size(), 0);
}

TEST(EngineTest, DrawNoMessage)
{

    sf::RenderWindow testWindow(sf::VideoMode(800, 600), "TestWindow", sf::Style::Close);
    Engine engine;
    engine.drawMessages(testWindow);

    SUCCEED();
}