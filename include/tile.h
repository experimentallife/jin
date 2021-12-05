#ifndef TILE_H_
#define TILE_H_

enum TileType {
	BLANK = 0, 
	BRICK_1 = 3, 
	LAVA_1 = 5, 
	LAVA_2 = 6,
	WATER_1 = 7, 
	EXIT_DOOR = 9,	
	MARBLE_1 = 12
};

class Tile : public Stable
{
	TileType type; 

public:
	Tile();
	virtual ~Tile();

	TileType getTileType(); 
	Tile * getTilePointer(short); 
	Tile getTile(short); 
						 
};

#endif