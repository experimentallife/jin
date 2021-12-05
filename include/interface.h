#ifndef INTERFACE_H_
#define INTERFACE_H_

#define INTERFACE_BUTTONS_QUANTITY 8
#define INTERFACE_GRAPHICS_QUANTITY 2


class Interface
{
	sf::Font font; 
	Hero *& hero; 

	std::vector <Button*> buttons; 
	std::vector <sf::Texture*> textures; 
	std::vector <sf::Sprite> sprites; 
	
public:
	Interface (Hero *&);
	~Interface();

	void draw(sf::RenderWindow &); 
	void update(sf::Time, float); 
};

#endif