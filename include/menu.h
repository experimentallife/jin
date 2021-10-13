#ifndef MENU_H_
#define MENU_H_

#define MAIN_MENU_BUTTONS_QUANTITY 3
#define PLAY_BUTTONS_QUANTITY 5
#define OPTIONS_BUTTONS_QUANTITY 5
#define NEXT_LEVEL_BUTTONS_QUANTITY 2
#define GAMEOVER_BUTTONS_QUANTITY 1
#define ENDGAME_BUTTONS_QUANTITY 4

enum MenuState { MAIN_MENU = 0, PLAY = 1, OPTIONS = 2, EXIT = 3, NEXT = 4, GAME_OVER = 5, OUT = 6};

class Menu
{
	protected:
		int buttonId;
		float deltaTime;
		bool heroSpecSet;

		std::vector<Button*> buttons;
		sf::Texture backgroundT;
		sf::Sprite backgroundS;
		sf::Font font;

		heroSpec whichSpecSet;
		MenuState menuState;

	public:
		Menu();
		virtual ~Menu();

		int getButtonId();
		sf::Font getFont();
		heroSpec getChosenSpec();
		MenuState getMenuState();

		bool isSpecSet();
		void setMenuState(MenuState);

		virtual void moveUp();
		virtual void moveDown(int);

		virtual void run(sf::RenderWindow &) = 0;
		virtual void draw(sf::RenderWindow &) = 0;
};

class MainMenu : public Menu
{
	public:
		MainMenu();
		~MainMenu();

		virtual void run(sf::RenderWindow &) final;
		virtual void draw(sf::RenderWindow &) final;
};

class Play : public Menu
{
	public:
		Play();
		~Play();

		virtual void moveUp();
		virtual void moveDown(int);

		virtual void run(sf::RenderWindow &) final;
		virtual void draw(sf::RenderWindow &) final;
};

class Options : public Menu
{
	public:
		Options();
		~Options();

		virtual void run(sf::RenderWindow &) final;
		virtual void draw(sf::RenderWindow &) final;
};

class NextLevel : public Menu
{
	std::vector <Enemy*> visualisation;

	public:
		NextLevel(int);
		~NextLevel();

		virtual void run(sf::RenderWindow &) final;
		virtual void draw(sf::RenderWindow &) final;
};

class EndGame : public Menu
{
	std::vector <Stable*> stableObjects;

	public:
		EndGame(int, float);
		~EndGame();

		virtual void run(sf::RenderWindow &) final;
		virtual void draw(sf::RenderWindow &) final;
};

#endif