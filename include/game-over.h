#ifndef GAMEOVER_H_
#define GAMEOVER_H_
#include "stable.h"


class GameOver : public Stable
{
	sf::Clock clock; 

public:
	GameOver();
	virtual ~GameOver();

	virtual void update(float) final; 
};

#endif