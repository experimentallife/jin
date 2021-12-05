#ifndef SPELL_H_
#define SPELL_H_

#define SPELL_COOLDOWN 1

class Spell : public Moveable
{
protected:
	int manaCost; 
	int power; 
	float speed; 
	float distance; 
	float maxDistance; 
	bool isMovingRight; 

	Animation animation; 
	bool first, second, third; 
	int row; 
	sf::Vector2f startingPos; 

public:
	Spell();
	virtual ~Spell();

	void setDirection(bool); 
	void setStartingPos(sf::Vector2f); 
	bool getDirection(); 

	virtual void draw(sf::RenderWindow &); 
	virtual bool collision(Entity *); 
	virtual void update(float); 
};




class Fireball : public Spell
{
public:
	Fireball();
	~Fireball();
};




class Frostbolt : public Spell
{
public:
	Frostbolt();
	~Frostbolt();
};




class Shadowbolt : public Spell
{
public:
	Shadowbolt();
	~Shadowbolt();
};



#endif