#include "../include/basic.h"



Interface::Interface(Hero * & hero_) :
	hero (hero_)
{
	if (!font.loadFromFile(Resources::getMenuBackgroundFont())) 
	{
		
		return;
	}

	for (int i = 0; i < INTERFACE_BUTTONS_QUANTITY; ++i)
	{
		Button * tmp = new Button;
		tmp->setFont(Interface::font);
		tmp->setColor(sf::Color::Green);
		tmp->setSize(30);
		switch (i)
		{
		case 0: 
		{
			tmp->setName("HP: "); 
			tmp->setPos(sf::Vector2f(60, 690));
			break;
		}
		case 1:
		{
			tmp->setName("x ");
			tmp->setPos(sf::Vector2f(230, 690));
			break;
		}
		case 2:
		{
			tmp->setName("3");
			tmp->setPos(sf::Vector2f(270, 690));
			break;
		}
		case 3:
		{
			tmp->setName("Score:"); 
			tmp->setPos(sf::Vector2f(360, 690));
			break;
		}
		case 4:
		{
			tmp->setName("x ");
			tmp->setPos(sf::Vector2f(610, 690));
			break;
		}
		case 5:
		{
			tmp->setName("0");
			tmp->setPos(sf::Vector2f(640, 690));
			break;
		}
		case 6:
		{
			tmp->setName("Time:"); 
			tmp->setPos(sf::Vector2f(740, 690));
			break;
		}
		case 7:
		{
			tmp->setName("XX:XX:XX");
			tmp->setPos(sf::Vector2f(970, 690));
		}
		default: break;
		}
		buttons.push_back(tmp);
	}

	for (int i = 0; i < INTERFACE_GRAPHICS_QUANTITY; ++i)
	{
		sf::Texture * texture = new sf::Texture;
		sf::Sprite sprite;

		switch (i)
		{
		case 0:
		{
			texture->loadFromFile(Resources::getHeartTexture());
			sprite.setTexture(*texture);
			sprite.setScale(sf::Vector2f(0.09f, 0.09f));
			sprite.setPosition(sf::Vector2f(170, 680));
			break;
		}
		case 1:
		{
			texture->loadFromFile(Resources::getCoinTexture());
			sprite.setTexture(*texture);
			sprite.setScale(sf::Vector2f(1.2f, 1.2f));
			sprite.setPosition(sf::Vector2f(540, 680));
			break;
		}
		default:
			break;
		}

		textures.push_back(texture);
		sprites.push_back(sprite);
	}
}



Interface::~Interface()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}

	for (std::vector<sf::Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}
}



void Interface::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < INTERFACE_BUTTONS_QUANTITY; ++i)
	{
		buttons[i]->draw(window);
	}

	for (std::vector<sf::Sprite>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		window.draw(*it);
	}
}



void Interface::update(sf::Time time, float points)
{
	
	std::ostringstream ss;
	ss << hero->getHealth();
	buttons[2]->setName(ss.str());

	
	std::ostringstream hh;
	hh << points;
	buttons[5]->setName(hh.str());

	
	std::ostringstream tt;
	tt << time.asSeconds();
	buttons[7]->setName(tt.str());
}

