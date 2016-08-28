#ifndef TILE_HPP
#define TILE_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp>

#define TILE_TYPES 4
#define TILE_SIZE 128
#define SWITCH_COUNT 1

/*#define OFF_SWITCH_TILE 0
#define CLOSED_DOOR_TILE 1
#define FLOOR_TILE 2
#define WALL_TILE 3
#define BOX_TILE 4
#define DIMENSION_TILE 5*/

#define OFF_SWITCH_TILE 0
#define CLOSED_DOOR_TILE 1
#define TEMPLE_FLOOR 2
#define TEMPLE_FILLER 3

// not actually in level file
#define ON_SWITCH_TILE 4
#define OPEN_DOOR_TILE 5
#define HOT_FLOOR 6
#define HOT_FILLER 7
#define DIMENSION_TILE 8

#define WALL_TILE TEMPLE_FLOOR


class Tile
{
public:
	Tile(sf::RenderWindow *window);
	~Tile();
	void offset(int x, int y);
	void render(int texture, int x, int y);

private:
	sf::RenderWindow *window;
	sf::Texture textures[TILE_TYPES * 2];
	int xOffset, yOffset;

};

#endif //TILE_HPP
