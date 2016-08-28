#ifndef TILE_HPP
#define TILE_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp>

#define TILE_TYPES 5
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
#define TEMPLE_WALL 4

// not actually in level file
#define ON_SWITCH_TILE 5
#define OPEN_DOOR_TILE 6
#define ICE_FLOOR 7
#define ICE_FILLER 8
#define ICE_WALL 9
#define DIMENSION_TILE 10

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
