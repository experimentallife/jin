#include "../include/basic.h"

GameOver::GameOver()
{
	ID = 666;
	collidable = false;
	interactable = false;
	interaction = Interaction::NONE;

	clock.restart().asSeconds();
}

GameOver::~GameOver()
{
	;
}

void GameOver::update(float diff)
{
	if (clock.getElapsedTime().asSeconds() > 0.1f)
	{
		clock.restart().asSeconds();
	}
}

