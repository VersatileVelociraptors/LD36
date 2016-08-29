#ifndef PLAYER_HPP
#define PLAYER_HPP


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Mob.hpp"

#define DIMENSION_CHANGE_DELAY .5 // in seconds

#define PLAYER_WIDTH 128
#define PLAYER_HEIGHT 128
#define GRAVITY -0.5
#define PI 3.14159265359

class Player : public Mob
{
public:
	Player();
	Player(Level *level);
	~Player();
	void move(float x, float y);
	int getDir();
	void update(float dt);
	void setLevel(Level *level);
	void init();
	int currentTileType();

	// grid based collision methods

	void set_true(float x, float y);
	sf::Vector2i get_true();
	void set_grid();
	sf::Vector2i get_grid();

	Level* get_level();

	void spawn();

	
private:
	sf::RenderWindow *window;
	std::vector<sf::Vector2i> walls;
	sf::Clock dimension_timer;
	
	bool switchHeld;
	
	// grid based collision variables

	int xDirection = 0; // integer value representing the direction the player is facing
	int yDirection = 0;
	int true_x=0; //x value of player origin relative to level 0,0
	int true_y=0; //y value of player origin relative to level 0,0
	int grid_x=0; // tile grid x value of player location
	int grid_y=0; // tile grid y value of player location

	int y_velocity = -3;

	bool freefalling=true;
	float rot;
	float total_time=0;

	bool jump=false;

	void teleport(int x, int y); //moves player to gridspace

};

#endif //PLAYER_HPP
