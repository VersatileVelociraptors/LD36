#ifndef LEVEL_HPP
#define LEVEL_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.hpp"
//#include "../entities/Player.h"
#include "../audio/SoundManager.hpp"

//class Player;

class Level
{
public:
	Level(char* path, sf::RenderWindow *window);
	~Level();
	int getXOffset();
	int getYOffset();
	void setXOffset(int offset);
	void setYOffset(int offset);
	void loadLevel(char* path);
	void update(float dt);
	void render();
	bool inSolid(int x, int y);
	int tileType(int x, int y);
	std::vector<sf::Vector2i> getWalls();
	sf::Vector2i getTileCoordinates(int index);
	int getWidthInPixels();
	int getHeightInPixels();
	int getWidthInTiles();
	int getHeightInTiles();
//	Player* getPlayer();
//	void setPlayer(Player *player);
	sf::RenderWindow* getWindow();
	SoundManager* getSoundManager();

private:
	sf::RenderWindow *window;
	int width, height;
	int *tileMap;
	int xOffset, yOffset;
	Tile *tiles;
//	Player *player;
	sf::Clock clock;
	SoundManager *soundManager;

	
};

#endif //LEVEL_HPP