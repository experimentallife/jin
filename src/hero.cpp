#include "../include/basic.h"



Hero::Hero(heroSpec heroSpec_) :
	Character()
{
	this->spec = heroSpec_;
	this->lastCast.restart().asSeconds();
	this->spellCast = false;
}



Hero::Hero(heroSpec heroSpec_, sf::Texture * texture, sf::Vector2u imageCount, float switchTime) :
	Character(texture, imageCount, switchTime) 
{
	this->spec = heroSpec_;
}



Hero::~Hero()
{
	;
}



Hero * Hero::getHero() 
{ 
	return this;
}



void Hero::setSpec(heroSpec spec_)
{
	this->spec = spec_;
}



bool Hero::isSpecSet()
{
	if (this->spec != unknown)
		return true;

	return false;
}



bool Hero::isSpellCast()
{
	return this->spellCast;
}



float Hero::getLastCast()
{
	return this->lastCast.getElapsedTime().asSeconds();
}



void Hero::update(float diff)
{
	if (isSpellCast())
	{
		if (lastCast.getElapsedTime().asSeconds() > SPELL_COOLDOWN)
		{
			lastCast.restart().asSeconds();
			spellCast = false;
		}
	}

	this->Character::update(diff);
}





Warlock::Warlock() : Hero(heroSpec::warlock)
{
	spellPower = 50;

	sf::Texture * txr = new sf::Texture;
	if (!(*txr).loadFromFile(Resources::getWarlockTexture()))
		return;

	this->setTexture(txr);
	this->sprite.setTextureRect(sf::IntRect(0, 96, 32, 48));
};



Warlock::Warlock(sf::Texture * texture, sf::Vector2u imageCount, float switchTime) :
	Hero(heroSpec::warlock, texture, imageCount, switchTime)
{
	spellPower = 50;
};



bool Warlock::castSpell()
{
	if (!spellCast)
	{
		spellCast = true;
		return true;
	}
	else
	{
		return false;
	}
}



Spell * Warlock::getSpell()
{
	Fireball * fireball = new Fireball;
	return fireball;
}



void Warlock::manaRefill()
{
	return;
}
