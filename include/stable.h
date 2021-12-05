#ifndef STABLE_H_
#define STABLE_H_

enum Interaction { NONE = 0, STOP = 1, BONUS = 2, DAMAGE = 3, HEAL = 4, TELEPORT};

#define BONUS_POINTS 25

class Stable : public Entity
{
protected:
	bool collidable; 
	bool interactable; 
	Interaction interaction; 

public:
	Stable();
	virtual ~Stable();

	bool isCollidable(); 
	bool isInteractable(); 

	virtual Interaction getInteraction(); 

	virtual void draw(sf::RenderWindow &); 
	virtual bool collision(Entity *); 
	virtual void update(float); 
};




class Coin : public Stable
{

public:
	Coin();
	~Coin();

	virtual bool collision(Entity *);
};



#endif