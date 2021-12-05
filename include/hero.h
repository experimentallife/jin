#ifndef HERO_H_
#define HERO_H_


enum heroSpec { unknown = 0, warlock = 1, mage = 2, priest = 3 };


class Hero : public Character
{
protected:
	heroSpec spec; 
	bool spellCast; 
	sf::Clock lastCast; 

public:
	Hero(heroSpec);
	Hero(heroSpec, sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	virtual  ~Hero();

	void setSpec(heroSpec); 
	bool isSpecSet(); 
	bool isSpellCast(); 
	float getLastCast(); 

	Hero * getHero(); 

	virtual void update(float); 
								
	virtual bool castSpell() = 0;
	virtual Spell * getSpell() = 0;
	virtual void manaRefill() = 0;
};

class Warlock : public Hero
{
	int spellPower;

public:
	Warlock();
	Warlock(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	~Warlock() {}

	virtual bool castSpell() final;
	virtual Spell * getSpell() final;
	virtual void manaRefill() final;
};

#endif