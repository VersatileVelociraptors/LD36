#include "Tile.hpp"

Tile::Tile(sf::RenderWindow *window){
	this->window = window;

	if(!textures[GRASS_TILE].loadFromFile("assets/images/grass.png"))
		this->window->close();

	if(!textures[DIRT_TILE].loadFromFile("assets/images/dirt.png"))
		this->window->close();

	if(!textures[FLOOR_TILE].loadFromFile("assets/images/floor.png"))
		this->window->close();

	if(!textures[WALL_TILE].loadFromFile("assets/images/wall.png"))
		this->window->close();

	if(!textures[BOX_TILE].loadFromFile("assets/images/box.png"))
		this->window->close();

	if(!textures[DIMENSION_TILE].loadFromFile("assets/images/dogg.png"))
		this->window->close();
	
	// textures for alternate dimension
	if(!textures[GRASS_TILE + TILE_TYPES].loadFromFile("assets/images/dirt.png"))
		this->window->close();
	
	if(!textures[DIRT_TILE + TILE_TYPES].loadFromFile("assets/images/dogg.png"))
		this->window->close();
	
	if(!textures[FLOOR_TILE + TILE_TYPES].loadFromFile("assets/images/dirt.png"))
		this->window->close();

	if(!textures[WALL_TILE + TILE_TYPES].loadFromFile("assets/images/box.png"))
		this->window->close();
	
	if(!textures[BOX_TILE + TILE_TYPES].loadFromFile("assets/images/grass.png"))
		this->window->close();
	
	if(!textures[DIMENSION_TILE + TILE_TYPES].loadFromFile("assets/images/floor.png"))
		this->window->close();
}

Tile::~Tile(){

}

void Tile::offset(int x, int y){
	this->xOffset = x;
	this->yOffset = y;
}

void Tile::render(int texture, int x, int y){

	sf::Sprite sprite(textures[texture]);
	sprite.setPosition(x, y);
	window->draw(sprite);
}
