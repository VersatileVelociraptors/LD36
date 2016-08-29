#include "Tile.hpp"

Tile::Tile(sf::RenderWindow *window){
	this->window = window;

	if(!textures[OFF_SWITCH_TILE].loadFromFile("assets/images/Switch_off.png"))
		this->window->close();

	if(!textures[CLOSED_DOOR_TILE].loadFromFile("assets/images/Door_closed.png"))
		this->window->close();

	if(!textures[TEMPLE_FLOOR].loadFromFile("assets/images/Temple_floor.png"))
		this->window->close();

	if(!textures[TEMPLE_FILLER].loadFromFile("assets/images/Temple_floor.png"))
		this->window->close();

	// textures for activated switches and doors
	if(!textures[ON_SWITCH_TILE].loadFromFile("assets/images/Switch_on.png"))
		this->window->close();
		
	if(!textures[OPEN_DOOR_TILE].loadFromFile("assets/images/Door_open.png"))
		this->window->close();
	
	// textures for alternate dimension
	if(!textures[OFF_SWITCH_TILE + TILE_TYPES].loadFromFile("assets/images/Switch_off.png"))
		this->window->close();
	
	if(!textures[CLOSED_DOOR_TILE + TILE_TYPES].loadFromFile("assets/images/Door_closed.png"))
		this->window->close();

	if(!textures[TEMPLE_FLOOR + TILE_TYPES].loadFromFile("assets/images/Dark_floor.png"))
		this->window->close();
	
	if(!textures[TEMPLE_FILLER + TILE_TYPES].loadFromFile("assets/images/Dark_floor.png"))
		this->window->close();

	if(!textures[ON_SWITCH_TILE + TILE_TYPES].loadFromFile("assets/images/Switch_on.png"))
		this->window->close();
	
	if(!textures[OPEN_DOOR_TILE + TILE_TYPES].loadFromFile("assets/images/Door_open.png"))
		this->window->close();
}

Tile::~Tile(){

}

void Tile::offset(int x, int y){
	this->xOffset = x;
	this->yOffset = y;
}

void Tile::render(int texture, int x, int y){
	if(texture >= 0){
		sf::Sprite sprite(textures[texture]);
		sprite.setPosition(x, y);
		window->draw(sprite);
	}
}
