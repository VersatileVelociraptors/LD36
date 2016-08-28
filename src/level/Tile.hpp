#ifndef TILE_HPP
#define TILE_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp>

#define TILE_TYPES 9
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
#define ICE_TILE 2
#define ICE_FILLER 3

// not actually in level file
#define TEMPLE_TILE 4
#define TEMPLE_FILLER 5
#define ON_SWITCH_TILE 6
#define OPEN_DOOR_TILE 7
#define DIMENSION_TILE 8

#define WALL_TILE ICE_TILE


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
