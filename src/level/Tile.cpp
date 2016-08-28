#include "Tile.hpp"

Tile::Tile(sf::RenderWindow *window){
	this->window = window;

	if(!textures[OFF_SWITCH_TILE].loadFromFile("assets/images/grass.png"))
		this->window->close();

	if(!textures[CLOSED_DOOR_TILE].loadFromFile("assets/images/dirt.png"))
		this->window->close();

	if(!textures[FLOOR_TILE].loadFromFile("assets/images/floor.png"))
		this->window->close();

	if(!textures[WALL_TILE].loadFromFile("assets/images/wall.png"))
		this->window->close();

	if(!textures[BOX_TILE].loadFromFile("assets/images/box.png"))
		this->window->close();
	
	// textures for activated switches and doors
	if(!textures[ON_SWITCH_TILE].loadFromFile("assets/images/dogg.png"))
		this->window->close();
		
	if(!textures[OPEN_DOOR_TILE].loadFromFile("assets/images/box.png"))
		this->window->close();
	
	// textures for alternate dimension
	if(!textures[OFF_SWITCH_TILE + TILE_TYPES].loadFromFile("assets/images/floor.png"))
		this->window->close();
	
	if(!textures[CLOSED_DOOR_TILE + TILE_TYPES].loadFromFile("assets/images/dogg.png"))
		this->window->close();
	
	if(!textures[FLOOR_TILE + TILE_TYPES].loadFromFile("assets/images/dirt.png"))
		this->window->close();

	if(!textures[WALL_TILE + TILE_TYPES].loadFromFile("assets/images/box.png"))
		this->window->close();
	
	if(!textures[BOX_TILE + TILE_TYPES].loadFromFile("assets/images/grass.png"))
		this->window->close();
	
	if(!textures[ON_SWITCH_TILE + TILE_TYPES].loadFromFile("assets/images/wall.png"))
		this->window->close();
	
	if(!textures[OPEN_DOOR_TILE + TILE_TYPES].loadFromFile("assets/images/grass.png"))
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
