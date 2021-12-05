#ifndef ANIMATION_H_
#define ANIMATION_H_



class Animation
{
public:
	void update(int, float, bool);

	sf::IntRect getIntRect();
	void setSwitchTime(float);
	void setSize(sf::Texture);
	void setImageCount(sf::Vector2u);
	bool isForward();

	Animation();
	Animation(sf::Texture *);
	Animation(sf::Vector2u, float);
	Animation(sf::Texture *, sf::Vector2u, float);
	~Animation();

protected:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::IntRect uvRect;

	float totalTime;
	float switchTime;
	bool forward;
};

#endif