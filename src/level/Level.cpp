#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Level.hpp"

using std::ifstream;
using std::string;
using std::vector;

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

void Level::loadLevel(char *path){
	ifstream level(path);

	if(!level){
		window->close();
		return;
	}

	string line;
	std::getline(level, line);
	std::getline(level, line);
	width = atoi(line.substr(line.find("=")+1).c_str());
	height = atoi(line.substr(line.find("=")+1).c_str());

	// read in tiles for map
	tileMap = new int[width * height];
	while(line.find("data=") == string::npos){
		std::getline(level, line);
	}
	std::getline(level, line);
	
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width*2; j+=2){
			tileMap[i * width + j/2] = atoi(&line.at(j)) -1;
		}

		std::getline(level, line);
	}
}

void Level::update(float dt){
	player->update(dt);
}

void Level::render(){
	int xp, yp;// player's position
	for(int i = 0; i < width * height; ++i){
		xp = TILE_SIZE*(i%width) + xOffset;
		yp = TILE_SIZE*(i/width) + yOffset;
		if(xp + TILE_SIZE < 0 || xp >= (int) window->getSize().x) continue;
		if(yp + TILE_SIZE < 0 || yp >= (int) window->getSize().y) continue;
		int tileNumber = tileMap[i];
		if (changedDimension) {
			// increment by number of normal tile types to use alternate tile textures
			tileNumber += TILE_TYPES;
		}
		tiles->render(tileNumber, xp, yp);// render the tile
	}
}

bool Level::inSolid(int x, int y){
	return (tileType(x,y) == WALL_TILE);
}

int Level::tileType(int x, int y){
	int index = (x - xOffset) / TILE_SIZE % width + (y - yOffset) / TILE_SIZE * width;
	if(index < 0 || index >= width * height)
		return -1;
	else
		return tileMap[index];
}

vector<sf::Vector2i> Level::getWalls(){
	vector<sf::Vector2i> indicies;
	for(int i = 0; i < width * height; i++){
		if(tileMap[i] == WALL_TILE)
			indicies.push_back(getTileCoordinates(i));
	}
	return indicies;
}

sf::Vector2i Level::getTileCoordinates(int index){
	sf::Vector2i position;
	int x = index%width;
	int y = index/width;

	position.x = x*TILE_SIZE-xOffset;
	position.y = y*TILE_SIZE-yOffset;
	return position;
}

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
