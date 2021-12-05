#ifndef LEVEL_H_
#define LEVEL_H_

#define STARTING_LEVEL_NUMBER 1
#define LEVELS_QUANTITY 2
#define TILE_WIDTH 32
#define TILE_HEIGHT 32

class Stats
{
	public:
		int pts;
		float tm;

		Stats() : pts(0), tm(0) {};
		~Stats() {};
};

class Level
{
	static int points;
	static float time;

	protected:
		int width; 
		int height; 
		int visibleWidth; 
		int visibleHeight; 
		short levelNumber; 
		float startX; 
		float startY; 
		float totalTime; 
		float switchTime; 
		float delta; 
		bool isActive; 
		bool isCompleted; 

		std::string levelName; 
		std::vector <sf::Texture*> textures; 
		std::vector <Stable*> stableObjects; 
		std::vector <Moveable*> moveableObjects; 
		std::vector <std::vector <sf::Sprite>> sprites; 
		std::vector <std::vector <Tile>> tiles; 
		std::vector <Tile*> obstacles; 
		std::vector <Enemy*> enemies; 
		std::vector <Spell*> spells; 

		sf::View camera; 
		sf::Clock clock; 
		sf::Texture backgroundT; 
		sf::Sprite backgroundS; 

		sf::RenderWindow & window; 
		Hero *& hero; 
		Spell * spell; 
		Interface interface; 

	public:
		Level(sf::RenderWindow &, Hero *&);
		virtual ~Level();

		void setLevelSize(unsigned int, unsigned int); 
		void setLevelNumber(unsigned short); 
		void setLevelName(const std::string &); 
		void setLevelBackGround(sf::Texture *); 
		void setLevel(sf::RenderWindow &, const std::string &); 

		void resetPoints(); 
		void resetTime(); 

		sf::Time getCurrentTime(); 
		sf::Vector2i checkCollisions(Entity *, Direction); 
		int getPoints(); 
		float getTime(); 
		void awardPoint(int); 

		void updateLevel(float); 
		void checkCollisions(); 
		void update(); 
		void draw(); 

		virtual bool play(sf::RenderWindow &, Hero *&); 

	private:
		bool loadFromFile(const std::string &); 
};

class Level_01 : public Level
{
	public:
		Level_01(sf::RenderWindow &, Hero *&);
		virtual ~Level_01();
};

class Level_02 : public Level
{
	public:
		Level_02(sf::RenderWindow &, Hero *&);
		virtual ~Level_02();	
};

class Level_03 : public Level
{
	public:
		Level_03(sf::RenderWindow &, Hero *&);
		virtual ~Level_03();	
};

#endif