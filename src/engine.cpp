#include "../include/basic.h"

Engine::Engine(sf::RenderWindow & window_) : window(window_)
{
	this->hero = new Warlock();

	this->totalLevels = LEVELS_QUANTITY;
	this->currentLevel = STARTING_LEVEL_NUMBER;
	this->running = false;
	
	Level * const level1 = new Level_01(window, hero);
	this->levels.push_back(level1);
	Level * const level2 = new Level_02(window, hero);
	this->levels.push_back(level2);
	Level * const level3 = new Level_03(window, hero);
	this->levels.push_back(level3);
	
	for (Level * const level : this->levels)
	{
		level->resetPoints();
		level->resetTime();
	}
}

Engine::~Engine()
{
	if (hero != nullptr)
	{
		delete this->hero;
		this->hero = nullptr;
	}
	
	for (std::vector<Level*>::iterator it = levels.begin(); it != levels.end();)
	{
		if ((*it) != nullptr)
		{
			delete (*it);
			(*it) = nullptr;
		}

		if (*it == nullptr)
		{
			it = levels.erase(it);
			continue;
		}

		++it;
	}
}

int Engine::getPoints()
{
	return this->totalStats.pts;
}

float Engine::getTime()
{
	return this->totalStats.tm;
}

bool Engine::play(sf::RenderWindow & window, Level * chosenLevel)
{
	NextLevel * const next = new NextLevel(this->currentLevel);
	this->delay.restart().asSeconds();

	while (this->delay.getElapsedTime().asSeconds() < WAIT_TIME)
	{
		next->draw(window);
	}

	delete next;

	bool shouldContinue = false;

	if (chosenLevel->play(window, this->hero))
	{
		this->currentLevel++;

		shouldContinue = true;
	}
	else
	{
		shouldContinue = false;
	}

	this->totalStats.pts = chosenLevel->getPoints();
	this->totalStats.tm = chosenLevel->getTime();

	return shouldContinue;
}

void Engine::run(sf::RenderWindow & window)
{
	this->running = true;

	for (Level * const level : this->levels)
	{
		if (this->play(window, level) == false)
		{
			break;
		}
	}

	this->running = false;
}

