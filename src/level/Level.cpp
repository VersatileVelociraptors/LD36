#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Level.hpp"

using std::ifstream;
using std::string;
using std::vector;

Level::Level(sf::RenderWindow *window, Player *player){
	this->window = window;
	tiles = new Tile(window);
	loadLevel("level01");
	setPlayer(player);

	spawnPlayer();

	this->soundManager = new SoundManager(this->window);
	soundManager->addAllSoundInAssets();

	if (!font.loadFromFile("assets/fonts/arial.ttf"))
		window->close();
	
	message.setFont(font);
	message.setCharacterSize(39);
	message.setColor(sf::Color::White);
	changeMessage(MESSAGE_1);
	
	switchActivated = false;
}

Level::~Level(){
	delete[] tileMap;
	delete[] alternateMap;
	delete tiles;
	delete soundManager;
}

void Level::loadLevel(std::string name){
	std::ifstream level("assets/levels/" + name + ".txt");

	if(!level){
		window->close();
		return;
	}

	std::string line;
	
	std::getline(level, line);
	std::getline(level, line);
	width = atoi(line.substr(line.find("=")+1).c_str());
	std::getline(level, line);
	height = atoi(line.substr(line.find("=")+1).c_str());

	// read in tiles for map
	tileMap = new int[width * height];
	loadFlareMapText("assets/levels/" + name + ".txt", tileMap);
	
	// load the alternate dimension map assumed to be the same size as the normal map
	alternateMap = new int[width * height];
	loadFlareMapText("assets/levels/" + name + "b.txt", alternateMap);
}

/**
 * Load level map from a flare text file
 * @param fileName name of flare text file
 * @param map level map array
 */
void Level::loadFlareMapText(std::string fileName, int *map){
	std::ifstream stream(fileName);
	std::string line;
	
	std::getline(stream, line);
	std::getline(stream, line);
	int mapWidth = atoi(line.substr(line.find("=")+1).c_str());
	std::getline(stream, line);
	int mapHeight = atoi(line.substr(line.find("=")+1).c_str());
	
	while(line.find("data=") == std::string::npos){
		std::getline(stream, line);
	}
	std::getline(stream, line);
	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth*2; j+=2){
			int value = atoi(&line.at(j)) -1;
			int index = i * mapWidth + j/2;
			map[index] = value;
			if(value == SPAWN_TILE){
				spawnTile.x = j;
				spawnTile.y = i;
			}
		}

		std::getline(stream, line);
	}
}

void Level::update(float dt){
	player->update(dt);
	
	if (message.getString() != "") {
		if (messageTimer.getElapsedTime().asSeconds() > MESSAGE_TIME){
			if (message.getString() == MESSAGE_1){
				changeMessage(MESSAGE_2);
			} else if (message.getString() == MESSAGE_2){
				message.setString("");
			}
		} else {
			sf::Color messageColor = message.getColor();
			messageColor.a = 255 - messageTimer.getElapsedTime().asMilliseconds() / MESSAGE_FADE;
			message.setColor(messageColor);
		}
	}
}

void Level::render(){
	int xp, yp;// tile position
	for(int i = 0; i < width * height; ++i){
		xp = TILE_SIZE*(i%width) + xOffset;
		yp = TILE_SIZE*(i/width) + yOffset;
		if(xp + TILE_SIZE < 0 || xp >= (int) window->getSize().x) continue;
		if(yp + TILE_SIZE < 0 || yp >= (int) window->getSize().y) continue;
		int tileNumber = currentMap()[i];
		if (getSwitchActivated()){
			if (tileNumber == OFF_SWITCH_TILE){
				tileNumber = ON_SWITCH_TILE;
			} else if (tileNumber == ON_SWITCH_TILE){
				tileNumber = OFF_SWITCH_TILE;
			} else if (tileNumber == CLOSED_DOOR_TILE){
				tileNumber = OPEN_DOOR_TILE;
			} else if (tileNumber == OPEN_DOOR_TILE) {
				tileNumber = CLOSED_DOOR_TILE;
			}
		}
		// render different textures in alternate dimension
		if (changedDimension){
			if(tileNumber >= 0){
				tileNumber += TILE_TYPES;
			}
		}
		tiles->render(tileNumber, xp, yp);// render the tile
		
		if (message.getString() != "")
			window->draw(message);
				
		//for testing
	
		string coordinate_string="";
		coordinate_string+=std::to_string(i%width)+", "+std::to_string(i/width);
		sf::Text coordinates;
		coordinates.setFont(font);
		coordinates.setCharacterSize(12);
		coordinates.setPosition(xp, yp);
		coordinates.setString(coordinate_string);
		coordinates.setColor(sf::Color::White);
		window->draw(coordinates);
	}
}

void Level::changeMessage(std::string text){
	message.setString(text);
	message.setPosition((window->getSize().x - message.getGlobalBounds().width) / 2, window->getSize().y - 50);
	messageTimer.restart();
}

// grid based collision

int Level::tile_type_grid(int x, int y){
	int index = (y * width) + x;
	if(index < 0 || index >= width * height)
		return -1;
	else
		return currentMap()[index];
}

bool Level::tile_solid_grid(int x, int y){
	int tile = tile_type_grid(x,y);
	return (tile==WALL_TILE || tile==TEMPLE_FLOOR)
		|| (tile == CLOSED_DOOR_TILE && !getSwitchActivated())
		|| (tile == OPEN_DOOR_TILE && getSwitchActivated());
}

sf::Vector2i Level::getTileCoordinates(int index){
	sf::Vector2i position;
	int x = index%width;
	int y = index/width;

	position.x = x*TILE_SIZE-xOffset;
	position.y = y*TILE_SIZE-yOffset;
	return position;
}

/// find map index of a tile based on its position
int Level::tileIndex(sf::Vector2i position){
	return tileIndex(position.x, position.y);
}

int Level::tileIndex(int xPosition, int yPosition){
	return (xPosition - xOffset) / TILE_SIZE % width + (yPosition - yOffset) / TILE_SIZE * width;
}

vector<sf::Vector2i> Level::getWalls(){
	vector<sf::Vector2i> indicies;
	for(int i = 0; i < width * height; i++){
		if(currentMap()[i] == WALL_TILE)
			indicies.push_back(getTileCoordinates(i));
	}
	return indicies;
}

/// return array for current sublevel
int *Level::currentMap(){
	return changedDimension ? alternateMap : tileMap;
}

/// change the dimension the user is in
void Level::changeDimensions(){
	changedDimension = !changedDimension;
}

void Level::setChangedDimension(bool cd){
	changedDimension=cd;
}

bool Level::getSwitchActivated(){
	return switchActivated;
}

void Level::setSwitchActivated(bool switchState){
	switchActivated = switchState;
}

int Level::getWidthInPixels(){
	return width * TILE_SIZE;
}

int Level::getHeightInPixels(){
	return height * TILE_SIZE;
}

int Level::getWidthInTiles(){
	return width;
}

int Level::getHeightInTiles(){
	return height;
}

void Level::positionPlayer(float x, float y){

	player->set_true(x, y);
	this->xOffset = player->getPosition().x - x;
	this->yOffset = player->getPosition().y - y;
}

void Level::spawnPlayer(){
	positionPlayer((spawnTile.x+1)*TILE_SIZE-(PLAYER_WIDTH/2), spawnTile.y*TILE_SIZE);
}

int Level::getXOffset(){
	return xOffset;
}

int Level::getYOffset(){
	return yOffset;
}

void Level::setXOffset(int offset){
	xOffset = offset;
}

void Level::setYOffset(int offset){
	yOffset = offset;
}

Player* Level::getPlayer(){
	return this->player;
}

void Level::setPlayer(Player *player){
	this->player = player;
}

sf::RenderWindow* Level::getWindow(){
	return this->window;
}

SoundManager* Level::getSoundManager(){
	return this->soundManager;
}

sf::Font Level::getFont(){
	return font;
}

sf::Vector2i Level::getSpawnTile(){
	return this->spawnTile;
}
