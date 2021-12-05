#include "../include/basic.h"



Menu::Menu()
{
	
	if (!font.loadFromFile(Resources::getMenuBackgroundFont())) 
	{
		return;
	}

	
	buttonId = 0;
	deltaTime = 0.1f;
	menuState = MAIN_MENU;
}



Menu::~Menu()
{
	;
}


int Menu::getButtonId()
{ 
	return this->buttonId; 
}



sf::Font Menu::getFont() 
{ 
	return this->font;
}



MenuState Menu::getMenuState()
{ 
	return this->menuState; 
}



void Menu::setMenuState(MenuState new_menuState) 
{ 
	this->menuState = new_menuState; 
}



void Menu::moveUp()
{
	if (buttonId - 1 >= 0)
	{
		buttons[buttonId]->setColor(sf::Color::White);
		buttonId--;
		buttons[buttonId]->setColor(sf::Color::Red);
	}
}



void Menu::moveDown(int maxNumber)
{
	if (buttonId + 1 < maxNumber)
	{
		buttons[buttonId]->setColor(sf::Color::White);
		buttonId++;
		buttons[buttonId]->setColor(sf::Color::Red);
	}
}

MainMenu::MainMenu()
{
	for (int i = 0; i < MAIN_MENU_BUTTONS_QUANTITY; ++i)
	{
		Button * tmp = new Button;
		tmp->setFont(Menu::font);
		tmp->setColor(sf::Color::White);
		tmp->setSize(50);
		switch (i)
		{
		case 0: tmp->setName("Play"); break;
		case 1: tmp->setName("Exit"); break;
		default: break;
		}
		tmp->setPos(sf::Vector2f(static_cast<float>(WIDTH - tmp->getText().getGlobalBounds().width) / 2, 
								 static_cast<float>(HEIGHT / (MAIN_MENU_BUTTONS_QUANTITY + 1) + i * 125)));
		buttons.push_back(tmp);
	}

	buttons[0]->setColor(sf::Color::Red);
	menuState = MAIN_MENU;
}



MainMenu::~MainMenu()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		if (*it != nullptr)
			delete (*it);
	}
}



void MainMenu::run(sf::RenderWindow & whichWindow)
{
	while (whichWindow.isOpen() && this->getMenuState() == MAIN_MENU)
	{
		sf::Event event;

		while (whichWindow.pollEvent(event))
		{
			switch (event.type)	
			{
			case sf::Event::Closed:
			{
				whichWindow.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
				{
					this->moveUp();
					break;
				}
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
				{
					this->moveDown(MAIN_MENU_BUTTONS_QUANTITY);
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (this->getButtonId())
					{
					case 0: { 
						this->setMenuState(MenuState::OUT); 
						return; 
					} 
					case 1: { 
						this->setMenuState(MenuState::EXIT); 
						return; 
					} 
					default: break;
					}
					break;
				}
				case sf::Keyboard::Escape: {  
					return; 
					break; 
				}
				default: break;
				}
			default:
				break;
			}
			}
		}

		whichWindow.clear();
		this->draw(whichWindow);
		whichWindow.display();
	}
}



void MainMenu::draw(sf::RenderWindow & whichWindow)
{

	for (int i = 0; i < MAIN_MENU_BUTTONS_QUANTITY; ++i)
	{
		buttons[i]->draw(whichWindow);
	}
}

NextLevel::NextLevel(int number)
{
	for (int i = 0; i < NEXT_LEVEL_BUTTONS_QUANTITY; ++i)
	{
		Button * tmp = new Button;
		tmp->setName("Level " + convertIntToString(number));
		tmp->setFont(Menu::font);
		tmp->setColor(sf::Color::White);
		tmp->setSize(50);
		tmp->setPos(sf::Vector2f(static_cast<float>(WIDTH - tmp->getText().getGlobalBounds().width) / 2, 
								 static_cast<float>(HEIGHT / 2 - 50)));
		buttons.push_back(tmp);
	}

	deltaTime = 0.02f;
	this->setMenuState(NEXT);
}



NextLevel::~NextLevel()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		if (*it != nullptr)
			delete (*it);
	}
}



void NextLevel::run(sf::RenderWindow & whichWindow)
{
	while (whichWindow.isOpen() && this->getMenuState() == NEXT)
	{
		this->draw(whichWindow);
	}
}



void NextLevel::draw(sf::RenderWindow & whichWindow)
{
	whichWindow.clear();
	
	for (int i = 0; i < NEXT_LEVEL_BUTTONS_QUANTITY; ++i)
	{
		buttons[i]->draw(whichWindow);
	}

	whichWindow.display();
}



EndGame::EndGame(int pts, float tm)
{
	for (int i = 0; i < ENDGAME_BUTTONS_QUANTITY; ++i)
	{
		Button * tmp = new Button;
		tmp->setFont(Menu::font);
		tmp->setColor(sf::Color::White);
		tmp->setSize(40);

		switch (i)
		{
		case 0:
		{
			tmp->setName("Points: " + convertIntToString(pts));
			tmp->setColor(sf::Color::Red);
			tmp->setSize(35);
			tmp->setPos(sf::Vector2f((WIDTH - tmp->getText().getGlobalBounds().width) / 2, 200));
			break;
		}
		case 1:
		{
			tmp->setName("Time: " + convertSecondsToMinutes(tm));
			tmp->setColor(sf::Color::Red);
			tmp->setSize(35);
			tmp->setPos(sf::Vector2f((WIDTH - tmp->getText().getGlobalBounds().width) / 2, 300));
			break;
		}
		case 2:
		{
			tmp->setName("Return");
			tmp->setColor(sf::Color::Red);
			tmp->setSize(40);
			tmp->setPos(sf::Vector2f((WIDTH - tmp->getText().getGlobalBounds().width) / 2, 400));
			break;
		}
		default: 
			break;
		}

		buttons.push_back(tmp);
	}

	GameOver * gameover = new GameOver;
	gameover->setPosition(sf::Vector2f((WIDTH - gameover->getSprite().getGlobalBounds().width )/ 2, 100));
	stableObjects.push_back(gameover);
	buttons[0]->setColor(sf::Color::Red);
	menuState = MenuState::GAME_OVER;

	deltaTime = 0.2f;
	buttonId = 3;
}



EndGame::~EndGame()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		if (*it == nullptr) continue;

		delete *it;
	}

	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		delete *it;
	}
}



void EndGame::run(sf::RenderWindow & whichWindow)
{
	while (whichWindow.isOpen() && this->getMenuState() == GAME_OVER)
	{
		this->draw(whichWindow);

		sf::Event event;

		while (whichWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				whichWindow.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Return:
				{
					switch (this->getButtonId())
					{
					case 3: { 
						this->setMenuState(MenuState::MAIN_MENU); 
						break; 
					}
					default: break;
					}
					break;
				}
				case sf::Keyboard::Escape: { 
					return; 
					break; 
				}
				default: break;
				}
			default:
				break;
			}
			}
		}
	}
}



void EndGame::draw(sf::RenderWindow & whichWindow)
{
	whichWindow.clear();
	
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->draw(whichWindow);
	}

	
	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->update(this->deltaTime);
	}

	
	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		(*it)->draw(whichWindow);
	}

	whichWindow.display();
}

