#include "../include/basic.h"

int Level::points = 0;
float Level::time = 0;

Level::Level(sf::RenderWindow & window_, Hero *& hero_) : 
	window(window_), hero(hero_), interface(hero_)
{
	camera.setSize(WIDTH, HEIGHT);
	camera.setCenter(WIDTH / 2, HEIGHT / 2);

	isActive = true;
	isCompleted = false;

	startX = 0.0f;
	startY = 0.0f;

	switchTime = 10.0f;
	totalTime = 0.0f;
	delta = 0.02f;

	backgroundT.loadFromFile(Resources::getBackground4Texture());
	backgroundS.setTexture(backgroundT);

	levelName = "Level 0.";
	levelNumber = 0;
	
	clock.restart().asSeconds();

	sf::Texture * temp = new sf::Texture;
	if (!(temp->loadFromFile(Resources::getBackground5Texture())))
		std::cout << "Blad z odczytem pliku do tekstury!" << std::endl;
	else
		std::cout << "Wczytano poprawnie teksture!!" << std::endl;
	textures.push_back(temp);
}

Level::~Level()
{
	for (std::vector<sf::Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}
	
	textures.clear();

	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}

	stableObjects.clear();

	for (std::vector<Moveable*>::iterator it = moveableObjects.begin(); it != moveableObjects.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}

	moveableObjects.clear();

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}

	enemies.clear();

	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end(); ++it)
	{
		if (*it != nullptr) delete *it;
	}

	spells.clear();
}

void Level::setLevel(sf::RenderWindow & window, const std::string & fileName)
{
	if (!this->loadFromFile(fileName))
	{
		std::cout << "Nie udalo sie zaladowac levela do pamieci!" << std::endl;
		return;
	}

	this->updateLevel(delta);
	window.setView(camera);
}

bool Level::loadFromFile(const std::string & fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (!file.good())
	{
		std::cout << "Blad z odczytem poziomu z pliku = " << fileName << "!" << std::endl;
		return false;
	}

	file >> width >> height; 

	if (width <= 0 || height <= 0)
	{
		std::cout << "Niepoprawny rozmiar mapy z pliku!" << std::endl;
		file.close();
		return false;
	}

	std::cout << "Zczytane wartosci: width = " << width << " ; height = " << height << std::endl;

	std::cout << "Inicjalizuje klase poziom!" << std::endl;

	visibleWidth = (WIDTH / TILE_WIDTH); 
	visibleHeight = (HEIGHT / TILE_HEIGHT);
	std::cout << "VisibleWidth = " << visibleWidth << std::endl;
	std::cout << "VisibleHeight = " << visibleHeight << std::endl;

	sprites.resize(visibleHeight);

	for (int i = 0; i < visibleHeight; ++i)
	{
		sprites[i].resize(visibleWidth);
	}

	std::cout << "Rozmiary zaalokowanego wektora sprite'ow to: [  y = " << sprites.size() << " x = " << sprites[0].size() << " ]" << std::endl;

	tiles.resize(height);

	for (int i = 0; i < height; i++)
	{
		tiles[i].resize(width);
	}

	std::cout << "Rozmiary zaalokowanego wektora tiles'ow to: [  y = " << tiles.size() << " x = " << tiles[0].size() << " ]" << std::endl;

	std::cout << "Zczytuje koordynaty kafelkow." << std::endl;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			Tile tile;
			short numberRead;
			file >> numberRead;
			if (numberRead != 0)
			{
				Tile * obstacleTile = new Tile;
				obstacleTile = obstacleTile->getTilePointer(numberRead);
				obstacleTile->setPosition(sf::Vector2f(static_cast<float>(j*TILE_HEIGHT), static_cast<float>(i*TILE_WIDTH)));
				obstacles.push_back(obstacleTile);
			}
			tiles[i][j] = tile.getTile(numberRead);
		}
	}

	file.clear();

	std::cout << "Poprawnie zczytano koordynaty kafelkow!" << std::endl;

	std::cout << "Zczytuje obiekty specjalne." << std::endl;

	while (!file.eof())
	{
		std::string line, objName;
		sf::Vector2i coords;
		sf::Vector2f position;
		Tile tempTile;

		std::getline(file, line, '\n');
		std::istringstream iss(line); 

		if (!iss.good()) std::cout << "Blad z lancuchem tekstowym!"; 
		iss >> objName >> coords.x >> coords.y;
		position = sf::Vector2f(static_cast<float>(coords.x * TILE_WIDTH), static_cast<float>(coords.y * TILE_HEIGHT));

		if (objName == "Coin")
		{
			Coin * newCoin = new Coin;
			newCoin->setCoords(coords);
			newCoin->setPosition(position);
			stableObjects.push_back(newCoin);
		}

		else if (objName == "Out")
		{
			Tile * newTile = new Tile;
			newTile = tempTile.getTilePointer(9);
			newTile->setCoords(coords);
			newTile->setPosition(position);
			stableObjects.push_back(newTile);
		}

		else if (objName == "Zombie")
		{
			Zombie * zombie = new Zombie;
			zombie->setStartPos(position);
			zombie->setPosition(position);
			enemies.push_back(zombie);
		}

		else if (objName == "Villain")
		{
			Villain * villain = new Villain;
			villain->setStartPos(position);
			villain->setPosition(position);
			enemies.push_back(villain);
		}
	}

	file.close();
	return true;
}

void Level::setLevelSize(unsigned int width_, unsigned int height_)
{
	this->width = width_;
	this->height = height_;
}

void Level::setLevelNumber(unsigned short levelNumber_)
{
	this->levelNumber = levelNumber_;
}


void Level::setLevelName(const std::string & levelName_)
{
	this->levelName = levelName_;
}

void Level::setLevelBackGround(sf::Texture * backgroundT_)
{
	this->backgroundT = (*backgroundT_);
	this->backgroundS.setTexture(this->backgroundT);
}

void Level::resetPoints()
{
	this->points = 0;
}


void Level::resetTime()
{
	this->time = 0;
}

sf::Time Level::getCurrentTime()
{
	return (this->clock.getElapsedTime());
}

int Level::getPoints()
{
	return this->points;
}

float Level::getTime()
{
	return this->time;
}

void Level::awardPoint(int score)
{
	this->points += score;
}


void Level::updateLevel(float delta)
{
	sf::Vector2i fixed(hero->getCoords());
	camera.setCenter(fixed.x*TILE_WIDTH + TILE_WIDTH / 2, HEIGHT / 2);

	sf::Vector2f min = sf::Vector2f(camera.getCenter().x - camera.getSize().x / 2, camera.getCenter().y - camera.getSize().y / 2);

	int leftBorder = min.x / TILE_WIDTH;
	int rightBorder = leftBorder + this->visibleWidth - 2;

	if (min.x < 0)
	{
		int difference = abs(min.x);
		min.x += difference;
		camera.move(difference, 0);

		leftBorder = min.x / TILE_WIDTH;
	}
	else if (leftBorder > 0 && rightBorder - 1 < this->width - 1)
	{
		min.x -= TILE_WIDTH;
		camera.move(-TILE_WIDTH, 0);

		leftBorder = min.x / TILE_WIDTH;
	}

	else if (rightBorder - 1 >= this->width - 1)
	{
		int difference = camera.getCenter().x + camera.getSize().x / 2 - (this->width - 1)*TILE_WIDTH;

		difference = -difference - TILE_WIDTH;
		min.x += difference;

		leftBorder = (min.x) / TILE_WIDTH;

		camera.setCenter((leftBorder + (this->visibleWidth) / 2)*TILE_WIDTH + TILE_WIDTH, camera.getCenter().y);
	}
	else if (leftBorder == 0)
		camera.move(-TILE_WIDTH , 0);

	int upBorder = min.y / TILE_HEIGHT;
	int bottomBorder = upBorder + this->visibleHeight + 1;

	if (min.y < 0)
	{
		int difference = abs(min.y);
		min.y += difference;
		camera.move(0, difference);

		upBorder = min.y / TILE_WIDTH;

	}
	else if (upBorder > 0 && bottomBorder - 1 < this->height - 1)
	{
		min.y -= TILE_HEIGHT;
		camera.move(0, -TILE_HEIGHT);

		upBorder = min.y / TILE_HEIGHT;
	}
	else if (bottomBorder - 1 >= this->height - 1)
	{
		int difference = camera.getCenter().y + camera.getSize().y / 2 - (this->height - 1)*TILE_HEIGHT;

		difference = -difference - TILE_HEIGHT;
		min.y += difference;

		upBorder = (min.y) / TILE_HEIGHT;

		camera.setCenter(camera.getCenter().x, (upBorder + (this->visibleHeight) / 2)*TILE_HEIGHT + TILE_HEIGHT);

		if (bottomBorder - 1 == this->visibleHeight - 1)   
			camera.move(0, -TILE_HEIGHT / 2);
	}
	else if (upBorder == 0)
		camera.move(0, -TILE_HEIGHT / 2);

	if (leftBorder < 0) leftBorder = abs(leftBorder);
	if (upBorder < 0) upBorder = abs(upBorder);	

	for (int y = 0, h = 0; y < this->visibleHeight; y++)		
	{          
		for (int x = 0, v = 0; x < this->visibleWidth; x++)   
		{
			tiles[y][x].setPosition((sf::Vector2f(v*TILE_HEIGHT, h*TILE_WIDTH)));
			v++;
		}
		h++;
	}
}


sf::Vector2i Level::checkCollisions(Entity * entity, Direction direction)
{
	int x = (int)(entity->getSprite().getPosition().x + entity->getSprite().getGlobalBounds().width / 2) / TILE_WIDTH;
	int y = (int)(entity->getSprite().getPosition().y + entity->getSprite().getGlobalBounds().height / 2) / TILE_HEIGHT;

	switch (direction)
	{
	case LEFT:
		x = (int)(entity->getSprite().getPosition().x + entity->getSprite().getGlobalBounds().width) / TILE_WIDTH;
		y = (int)(entity->getSprite().getPosition().y + entity->getSprite().getGlobalBounds().height / 2) / TILE_HEIGHT;
		break;
	case RIGHT:
		x = (int)(entity->getSprite().getPosition().x) / TILE_WIDTH;
		y = (int)(entity->getSprite().getPosition().y + entity->getSprite().getGlobalBounds().height / 2) / TILE_HEIGHT;
		break;
	case UP:
		x = (int)(entity->getSprite().getPosition().x + entity->getSprite().getGlobalBounds().width / 2) / TILE_WIDTH;
		y = (int)(entity->getSprite().getPosition().y) / TILE_HEIGHT;
		break;
	case DOWN:
		x = (int)(entity->getSprite().getPosition().x + entity->getSprite().getGlobalBounds().width / 2) / TILE_WIDTH;
		y = (int)(entity->getSprite().getPosition().y + entity->getSprite().getGlobalBounds().height) / TILE_HEIGHT;
		break;
	}
	
	return sf::Vector2i(x, y);
}


void Level::checkCollisions()
{
	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		if (hero->checkCollision(*it))
		{
			hero->collision(*it);

			if ((*it)->getInteraction() == BONUS)
			{
				this->awardPoint(BONUS_POINTS);
				(*it)->destroy();
			}
			else if ((*it)->getInteraction() == TELEPORT)
			{
				this->isActive = false;
				this->isCompleted = true;
			}
		}
	}

	for (std::vector<Moveable*>::iterator it = moveableObjects.begin(); it != moveableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		if (hero->checkCollision(*it))
		{
			hero->collision(*it);
		}
	}

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (*it == nullptr) continue;

		if (hero->checkCollision(*it))
		{
			hero->collision(*it);
			hero->hurt(1);
		}


		for (std::vector<Spell*>::iterator itt = spells.begin(); itt != spells.end(); ++itt)
		{
			if (*itt == nullptr) continue;

			if ((*itt)->checkCollision(*it))
			{
				this->awardPoint(ZOMBIE_BONUS);
				(*itt)->destroy();

				if (*it == nullptr) continue;

				(*it)->destroy();
			}
		}
	}


	for (std::vector<Tile*>::iterator it = obstacles.begin(); it != obstacles.end(); ++it)
	{
		if (hero->checkCollision(*it))
		{
			hero->collision(*it);
		}

		for (std::vector<Spell*>::iterator itt = spells.begin(); itt != spells.end(); ++itt)
		{
			if (*itt == nullptr) continue;

			if ((*itt)->checkCollision(*it))
			{
				(*itt)->destroy();
			}
		}
	}
}


void Level::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->hero->castSpell())
		{
			Spell * temp = hero->getSpell();
			temp->setStartingPos(hero->getPosition());
			temp->setPosition(sf::Vector2f(hero->getPosition().x, hero->getPosition().y));
			temp->setDirection(hero->isFacingRight());
			spells.push_back(temp);
		}
	}

	hero->setCollisionState(false);

	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end();)
	{
		if ((*it)->isDead())
		{
			delete (*it);
			(*it) = nullptr;
		}

		if (*it == nullptr)
		{
			it = stableObjects.erase(it);
			continue;
		}

		(*it)->update(delta);
		++it;
	}

	for (std::vector<Moveable*>::iterator it = moveableObjects.begin(); it != moveableObjects.end();)
	{
		if ((*it)->isDead())
		{
			delete (*it);
			(*it) = nullptr;
		}

		if (*it == nullptr)
		{
			it = moveableObjects.erase(it);
			continue;
		}

		(*it)->update(delta);
		++it;
	}


	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end();)
	{
		if ((*it)->isDead())
		{
			delete (*it);
			(*it) = nullptr;
		}

		if (*it == nullptr)
		{
			it = enemies.erase(it);
			continue;
		}

		(*it)->update(delta);
		++it;
	}

	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end(); )
	{
		if ((*it)->isDead())
		{
			delete (*it);
			(*it) = nullptr;
		}

		if (*it == nullptr)
		{
			it = spells.erase(it);
			continue;
		}

  		(*it)->update(delta);
		++it;
	}


	hero->update(delta);


	if (hero->getHealth() < MIN_HEALTH)
	{
		this->isActive = false;
		this->isCompleted = false;
	}


	interface.update(this->getCurrentTime(), this->getPoints());
}

void Level::draw()
{
	window.clear(sf::Color(150, 170, 190));

	window.draw(backgroundS);

	for (std::vector<Stable*>::iterator it = stableObjects.begin(); it != stableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->draw(window);
	}

	for (std::vector<Moveable*>::iterator it = moveableObjects.begin(); it != moveableObjects.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->draw(window);
	}

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->draw(window);
	}

	for (std::vector<Tile*>::iterator it = obstacles.begin(); it != obstacles.end(); ++it)
	{
		if (*it == nullptr) continue;

		window.draw((*it)->getSprite());
	}

	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end(); ++it)
	{
		if (*it == nullptr) continue;

		(*it)->draw(window);
	}

	interface.draw(window);
	hero->draw(window);

	window.setView(camera);
	window.display();
}

bool Level::play(sf::RenderWindow & window, Hero *& hero)
{
	this->hero->setPosition(sf::Vector2f(startX, startY));

	this->clock.restart().asSeconds();

	while (window.isOpen() && this->isActive)
	{
		this->checkCollisions();

		this->update();

		this->draw();
	}

	this->time += clock.getElapsedTime().asSeconds();

	return this->isCompleted;
}

Level_01::Level_01(sf::RenderWindow & window, Hero *& hero) :
	Level(window, hero)
{
	std::cout << "============= LEVEL 1 =============" << std::endl;
	startX = 32.0f;
	startY = 620.0f;

	backgroundT.loadFromFile(Resources::getBackground5Texture());
	backgroundS.setTexture(backgroundT);

	this->setLevelName("Level_1");
	this->setLevelNumber(1);

	setLevel(this->window, "../resources/levels/level_01.txt");

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (typeid(**it) == typeid(Zombie))
		{
			(*it)->setBackPos(sf::Vector2f(34 * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setEndPos(sf::Vector2f(45 * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setMoveSpeed(150.0f);
		}
		else if (typeid(**it) == typeid(Villain))
		{
			(*it)->setBackPos(sf::Vector2f((22) * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setEndPos(sf::Vector2f((28) * TILE_WIDTH, (*it)->getStartPos().y));
		}
	}

	this->hero->getSprite().setScale(sf::Vector2f(1.0f, 1.0f));
	this->hero->setPosition(sf::Vector2f(startX, startY));

	std::cout << "Stable objects level 01 = " << this->stableObjects.size() << std::endl;
}


Level_01::~Level_01()
{
	;
}


Level_02::Level_02(sf::RenderWindow & window, Hero *& hero) :
	Level(window, hero)
{
	startX = 32.0f;
	startY = 620.0f;

	backgroundT.loadFromFile(Resources::getBackground5Texture());
	backgroundS.setTexture(backgroundT);

	this->setLevelName("Level_2");
	this->setLevelNumber(2);

	setLevel(this->window, "../resources/levels/level_02.txt");

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (typeid(**it) == typeid(Zombie))
		{
			(*it)->setBackPos(sf::Vector2f(5 * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setEndPos(sf::Vector2f(37 * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setMoveSpeed(300.0f);
		}
		else if (typeid(**it) == typeid(Villain))
		{
			(*it)->setBackPos(sf::Vector2f((13) * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setEndPos(sf::Vector2f((39) * TILE_WIDTH, (*it)->getStartPos().y));
			(*it)->setMoveSpeed(200.0f);
		}
	}

	this->hero->getSprite().setScale(sf::Vector2f(1.0f, 1.0f));
	this->hero->setPosition(sf::Vector2f(startX, startY));
}

Level_02::~Level_02()
{
	;
}
