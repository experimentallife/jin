#include "../include/basic.h"

Game::Game()
{
    window.create(sf::VideoMode(WIDTH, HEIGHT), "THE_GAME", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);

	state = GameState::GAME;
	int lastPoints = 0;
	float lastTime = 0;
}

Game::~Game()
{
    ;
}

sf::RenderWindow && Game::getWindow()
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
    while (state != END)
    {
        switch (this->state)
        {
            case GameState::MENU:
                std::cout << "menu..." << std::endl;
                break;
            case GameState::GAME:
                std::cout << "game..." << std::endl;
                break;
            case GameState::END:
                std::cout << "end..." << std::endl;
                break;
            default:
                break;
        }
    }
}

void Game::updateScore(int points_, float time_)
{
    this->lastPoints = points_;
    this->lastTime = time_;
}