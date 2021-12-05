#ifndef ENGINE_H_
#define ENGINE_H_

#define WAIT_TIME 3


class Engine
{
public:
	void run(sf::RenderWindow &);
	bool play(sf::RenderWindow &, Level*);

	void updateScore(int);
	void updateTime(float);
	int getPoints();
	float getTime();

	Engine(sf::RenderWindow & window);
	~Engine();

protected:
	Hero * hero;
	std::vector <Level*> levels;
	sf::Clock delay;
	sf::RenderWindow & window;
	Stats totalStats;

	int totalLevels;
	int currentLevel;
	bool running; 
};

#endif