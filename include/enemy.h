#ifndef ENEMY_H_
#define ENEMY_H_

#define ENEMIES_QUANTITY 1
#define OFFSET_MOVEMENT_4 4

class Enemy : public Character
{
	protected:
		sf::Vector2f startPos;
		sf::Vector2f endPos;
		sf::Vector2f backPos;

		float totalTime;
		float switchTime;
		int imageNumber;

	public:
		Enemy();
		Enemy(sf::Vector2u, float);
		Enemy(sf::Texture *, sf::Vector2u, float);
		virtual ~Enemy();

		void setStartPos(sf::Vector2f);
		void setEndPos(sf::Vector2f);
		void setBackPos(sf::Vector2f);
		void setSize(sf::Vector2f);
		void setDirection(bool);
		void setMoveSpeed(float);

		sf::Vector2f getStartPos();
		sf::Vector2f getEndPos();
		sf::Vector2f getBackPos();

		//virtual void update(float);
};

#define ZOMBIE_BONUS 500

class Zombie : public Enemy
{
	public:
		Zombie();
		Zombie(sf::Vector2u, float);
		Zombie(sf::Texture *, sf::Vector2u, float);
		~Zombie();

		virtual void update(float);
};

#define VILLAIN_BONUS 100

class Villain : public Enemy
{
	public:
		Villain();
		Villain(sf::Vector2u, float);
		Villain(sf::Texture *, sf::Vector2u, float);
		~Villain();

		virtual void update(float);
};

#endif