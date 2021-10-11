#include "../include/basic.h"

Game::Game()
{
    window.create(sf::VideoMode(WIDTH, HEIGHT), "THE_GAME", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);

	state = GameState::MENU;
	int lastPoints = 0;
	float lastTime = 0;
}