#ifndef GAME_H_
#define GAME_H_


enum GameState
{
	MENU = 0,
	GAME = 1,
	END = 2
};


class Game
{
	public:
		void run();
		void updateScore(int, float);

		sf::RenderWindow &getWindow();
		GameState getState();
		void setState(GameState);

		Game();
		~Game();

	protected:
		sf::RenderWindow window;
		GameState state;
		int lastPoints;
		float lastTime;
};

#endif
