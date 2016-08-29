#ifndef LEVEL_HPP
#define LEVEL_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "../entities/Player.hpp"
#include "../audio/SoundManager.hpp"

#define LEVEL_COUNT 6

#define MESSAGE_TIME 4 // in seconds
#define MESSAGE_FADE 25 // increases how quickly messages become tranparent
#define MESSAGE_1 "Press Shift to alternate dimensions"
#define MESSAGE_2 "Press E to flip switches"

class Level
{
public:
	Level(sf::RenderWindow *window);
	~Level();
	int getXOffset();
	int getYOffset();
	void setXOffset(int offset);
	void setYOffset(int offset);
	void loadLevel(std::string name);
	void loadFlareMapText(std::string fileName, int *map);
	void nextLevel();
	void update(float dt);
	void render();
	int tileIndex(sf::Vector2i position);
	int tileIndex(int xPosition, int yPosition);
	int getWidthInPixels();
	int getHeightInPixels();
	int getWidthInTiles();
	int getHeightInTiles();
	sf::RenderWindow* getWindow();
	SoundManager* getSoundManager();
	int *currentMap();
	void changeDimensions();
	std::vector<sf::Vector2i> getWalls();
	sf::Vector2i getTileCoordinates(int index);
	sf::Font getFont();
	bool getSwitchActivated();
	void setSwitchActivated(bool switchState);
	void changeMessage(std::string text);
	sf::Vector2i getSpawnTile();
	int getCurrentLevel();

	void setChangedDimension(bool cd);

	// grid based collision
	int tile_type_grid(int x, int y);//returns tile type based on grid x/y
	bool tile_solid_grid(int x, int y);

private:
	sf::RenderWindow *window;
	int width, height;
	int *tileMap;
	int *alternateMap;
	int xOffset = 0, yOffset = 0;
	Tile *tiles;
	sf::Clock clock;
	SoundManager *soundManager;
	bool changedDimension = false;
	sf::Font font;
	bool switchActivated;
	sf::Text message;
	sf::Clock messageTimer;
	sf::Vector2i spawnTile;
	unsigned int currentLevel;
};

#endif //LEVEL_HPP
