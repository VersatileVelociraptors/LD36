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

#define SUBLEVEL_SIZE 4 // number of tiles in sublevel

#define MESSAGE_TIME 4 // in seconds
#define MESSAGE_FADE 25 // increases how quickly messages become tranparent
#define MESSAGE_1 "Placeholder"
#define MESSAGE_2 "The text will stay centered even if the string is long."

class Level
{
public:
	Level(char* path, sf::RenderWindow *window, Player *player);
	~Level();
	int getXOffset();
	int getYOffset();
	void setXOffset(int offset);
	void setYOffset(int offset);
	void loadLevel(char* path);
	void loadFlareMapText(std::string fileName, int *map, bool alternateDimension);
	void update(float dt);
	void render();
	bool inSolid(int x, int y);
	int tileType(int x, int y);
	int tileIndex(sf::Vector2i position);
	int tileIndex(int xPosition, int yPosition);
	int getWidthInPixels();
	int getHeightInPixels();
	int getWidthInTiles();
	int getHeightInTiles();
	void positionPlayer(float x, float y);
	Player* getPlayer();
	void setPlayer(Player *player);
	sf::RenderWindow* getWindow();
	SoundManager* getSoundManager();
	int *currentSublevelMap();
	void changeDimensions();
	std::vector<sf::Vector2i> getWalls();
	sf::Vector2i getTileCoordinates(int index);
	sf::Font getFont();
	bool *switchStates();
	void changeMessage(std::string text);

	// grid based collision
	int tile_type_grid(int x, int y);//returns tile type based on grid x/y
	bool tile_solid_grid(int x, int y);

private:
	sf::RenderWindow *window;
	int width, height;
	int *tileMap;
	int *sublevelA;
	int *sublevelB;
	int xOffset = 0, yOffset = 0;
	Tile *tiles;
	Player *player;
	sf::Clock clock;
	SoundManager *soundManager;
	bool changedDimension = false;
	sf::Font font;
	bool *switchActivated;
	sf::Text message;
	sf::Clock messageTimer;
};

#endif //LEVEL_HPP
