#ifndef MENU_H_
#define MENU_H_

#define MAIN_MENU_BUTTONS_QUANTITY 2
#define NEXT_LEVEL_BUTTONS_QUANTITY 1
#define GAMEOVER_BUTTONS_QUANTITY 1
#define ENDGAME_BUTTONS_QUANTITY 3


enum MenuState { MAIN_MENU = 0, PLAY = 1, EXIT = 2, NEXT = 3, GAME_OVER = 4, OUT = 5 };


class Menu
{
protected:
	int buttonId; 
	float deltaTime; 
	
	std::vector<Button*> buttons; 
	sf::Font font; 

	MenuState menuState; 

public:
	Menu();
	virtual ~Menu();

	int getButtonId(); 
	sf::Font getFont(); 
	MenuState getMenuState(); 

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

class NextLevel : public Menu
{

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