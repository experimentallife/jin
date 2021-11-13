#include "../include/basic.h"

Game::Game()
{
    this->window.create(sf::VideoMode(1280, 760), "Jin", sf::Style::Close);
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);

    this->state = GameState::GAME;
}

Game::~Game()
{
    this->window.clear();
    this->window.close();
}

sf::RenderWindow &Game::getWindow()
{
    return window;
}

GameState Game::getState()
{
    return state;
}

void Game::setState(GameState state_)
{
    this->state = state_;
}

void Game::run()
{
    while(state != END)
    {
        std::cout <<  "pepe" << std::endl;
    }
}