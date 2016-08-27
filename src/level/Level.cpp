#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Level.hpp"

Level::Level(char *path, sf::RenderWindow *window){
	this->window = window;
	tiles = new Tile(window);
	loadLevel(path);

	xOffset = -getWidthInPixels()/2;
	yOffset = -getHeightInPixels()/2;

	this->soundManager = new SoundManager(this->window);
	soundManager->addAllSoundInAssets();
}

Level::~Level(){
	delete[] tileMap;
	delete tiles;
	delete soundManager;
}

void Level::loadLevel(char *path){
	std::ifstream level(path);

	if(!level){
		window->close();
		return;
	}

	std::string line;
	
	// load sublevel A
	sublevelA = new int[SUBLEVEL_SIZE];
	loadFlareMapText("assets/levels/sublevel-a.txt", sublevelA, false);
	
	// load sublevel B
	sublevelB = new int[SUBLEVEL_SIZE];
	loadFlareMapText("assets/levels/sublevel-b.txt", sublevelB, true);
	
	std::getline(level, line);
	std::getline(level, line);
	width = atoi(line.substr(line.find("=")+1).c_str());
	height = atoi(line.substr(line.find("=")+1).c_str());

	// read in tiles for map
	tileMap = new int[width * height];
	loadFlareMapText(std::string(path), tileMap, false);
}

/**
 * Load level map from a flare text file
 * @param fileName name of flare text file
 * @param map level map array
 * @param alternateDimension whether or not the map is a secondary sublevel
 */
void Level::loadFlareMapText(std::string fileName, int *map, bool alternateDimension){
	std::ifstream stream(fileName);
	std::string line;
	
	std::getline(stream, line);
	std::getline(stream, line);
	int mapWidth = atoi(line.substr(line.find("=")+1).c_str());
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
			if (alternateDimension) {
				map[index] += TILE_TYPES;
			}
		}

		std::getline(stream, line);
	}
}

void Level::update(float dt){
	player->update(dt);
}

void Level::render(){
	int xp, yp;// tile position
	int changingTileIndex = 0;
	for(int i = 0; i < width * height; ++i){
		xp = TILE_SIZE*(i%width) + xOffset;
		yp = TILE_SIZE*(i/width) + yOffset;
		if(xp + TILE_SIZE < 0 || xp >= (int) window->getSize().x) continue;
		if(yp + TILE_SIZE < 0 || yp >= (int) window->getSize().y) continue;
		int tileNumber = tileMap[i];
		if (tileNumber == DIMENSION_TILE) {
			int *sublevel = currentSublevelMap();// sub level B tile after change
			tileNumber = sublevel[changingTileIndex++];
		} else if (changedDimension) {
			// increment by number of normal tile types to use alternate tile textures
			tileNumber += TILE_TYPES;
		}
		tiles->render(tileNumber, xp, yp);// render the tile
	}
}

bool Level::inSolid(int x, int y){
	int tile = tileType(x,y);
	if (tile == DIMENSION_TILE) {
		int subtileCount = 0;
		// find the number of subtiles after this one
		for (int i = tileIndex(x,y) + 1; i < width * height; i++) {
			if (tileMap[i] == DIMENSION_TILE) {
				subtileCount++;
			}
		}
		int subtileIndex = SUBLEVEL_SIZE -1 - subtileCount;
		int *sublevel = currentSublevelMap();// sub level B tile after change
		tile = sublevel[subtileIndex];
		if (changedDimension) {
			tile -= TILE_TYPES;
		}
	}
	return tile == WALL_TILE;
}

int Level::tileType(int x, int y){
	int index = tileIndex(x, y);
	if(index < 0 || index >= width * height)
		return -1;
	else
		return tileMap[index];
}

/// find map index of a tile based on its position
int Level::tileIndex(sf::Vector2i position){
	return tileIndex(position.x, position.y);
}

int Level::tileIndex(int xPosition, int yPosition){
	return (xPosition - xOffset) / TILE_SIZE % width + (yPosition - yOffset) / TILE_SIZE * width;
}

/// return array for current sublevel
int *Level::currentSublevelMap(){
	return changedDimension ? sublevelB : sublevelA;
}

/// change the dimension the user is in
void Level::changeDimensions(){
	changedDimension = !changedDimension;
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
