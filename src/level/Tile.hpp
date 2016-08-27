#ifndef TILE_HPP
#define TILE_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp>

#define TILE_SIZE 128
#define GRASS_TILE 0
#define DIRT_TILE 1 
#define FLOOR_TILE 2 
#define WALL_TILE 3 
#define BOX_TILE 4 
#define SNOOP_TILE 5 

class Tile
{
public:
	Tile(sf::RenderWindow *window);
	~Tile();
	void offset(int x, int y);
	void render(int texture, int x, int y);

private:
	sf::RenderWindow *window;
	sf::Texture textures[6];
	int xOffset, yOffset;

};

#endif //TILE_HPP