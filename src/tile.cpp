#include "../include/basic.h"



Tile::Tile() : Stable()
{
	type = TileType::BRICK_1;
	clock.restart().asSeconds();
}



Tile::~Tile()
{
	;
}



TileType Tile::getTileType() 
{ 
	return this->type;
}



Tile Tile::getTile(short tileCode)
{
	
	Tile tile;
	tile.type = TileType(tileCode);
	sf::Texture * txr = new sf::Texture;
	
	
	switch (TileType(tileCode))
	{
	case TileType::BLANK:
	{
		ID = 0;
		interaction = NONE;
		collidable = true;
		interactable = false;
		break;
	}
	case TileType::BRICK_1:
	{
		ID = 3;
		txr->loadFromFile(Resources::getBrick1Texture());
		tile.sprite.setTexture(*txr);
		interaction = STOP;
		collidable = false;
		interactable = false;
		break;
	}
	case TileType::LAVA_1:
	{
		ID = 5;
		txr->loadFromFile(Resources::getLava11Texture());
		tile.sprite.setTexture(*txr);
		interaction = DAMAGE;
		collidable = false;
		interactable = false;
		break;
	}
	case TileType::LAVA_2:
	{
		ID = 6;
		txr->loadFromFile(Resources::getLava2Texture());
		tile.sprite.setTexture(*txr);
		interaction = DAMAGE;
		collidable = false;
		interactable = false;
		break;
	}
	case TileType::WATER_1:
	{
		ID = 7;
		txr->loadFromFile(Resources::getWater1Texture());
		sprite.setTexture(*txr);
		interaction = NONE;
		collidable = true;
		interactable = false;
		break;
	}
	case TileType::EXIT_DOOR:
	{
		ID = 9;
		txr->loadFromFile(Resources::getExitDoorsTexture());
		tile.sprite.setTexture(*txr);
		interaction = TELEPORT;
		collidable = true;
		interactable = true;
		break;
	}
	case TileType::MARBLE_1:
	{
		ID = 12;
		tile.texture->loadFromFile(Resources::getMarble1Texture());
		tile.sprite.setTexture(*texture);
		interaction = NONE;
		collidable = false;
		interactable = false;
		break;
	}
	default:
		break;
	}

	return tile;
}



Tile * Tile::getTilePointer(short tileCode)
{
	
	Tile * tile = new Tile;
	tile->type = TileType(tileCode);
	sf::Texture * txr = new sf::Texture;

	
	switch (TileType(tileCode))
	{
	case TileType::BLANK:
	{
		tile->ID = 0;
		tile->interaction = NONE;
		tile->collidable = true;
		tile->interactable = false;
		break;
	}
	case TileType::BRICK_1:
	{
		tile->ID = 3;
		txr->loadFromFile(Resources::getBrick1Texture());
		tile->sprite.setTexture(*txr);
		tile->interaction = STOP;
		tile->collidable = false;
		tile->interactable = false;
		break;
	}
	case TileType::LAVA_1:
	{
		tile->ID = 5;
		txr->loadFromFile(Resources::getLava11Texture());
		tile->sprite.setTexture(*txr);
		tile->interaction = DAMAGE;
		tile->collidable = true;
		tile->interactable = true;
		break;
	}
	case TileType::LAVA_2:
	{
		tile->ID = 6;
		txr->loadFromFile(Resources::getLava2Texture());
		tile->sprite.setTexture(*txr);
		tile->interaction = DAMAGE;
		tile->collidable = true;
		tile->interactable = true;
		break;
	}
	case TileType::WATER_1:
	{
		tile->ID = 7;
		txr->loadFromFile(Resources::getWater1Texture());
		tile->sprite.setTexture(*txr);
		tile->interaction = NONE;
		tile->collidable = true;
		tile->interactable = false;
		break;
	}
	case TileType::EXIT_DOOR:
	{
		tile->ID = 9;
		txr->loadFromFile(Resources::getExitDoorsTexture());
		tile->sprite.setTexture(*txr);
		tile->interaction = TELEPORT;
		tile->collidable = true;
		tile->interactable = true;
		break;
	}
	case TileType::MARBLE_1:
	{
		tile->ID = 12;
		tile->texture->loadFromFile(Resources::getMarble1Texture());
		tile->sprite.setTexture(*texture);
		tile->interaction = NONE;
		tile->collidable = true;
		tile->interactable = false;
		break;
	}
	default:
		break;
	}

	return tile;
}

