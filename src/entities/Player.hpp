#ifndef PLAYER_HPP
#define PLAYER_HPP


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Mob.hpp"

#define DIMENSION_CHANGE_DELAY 0.25 // in seconds

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

	// grid based collision methods

	void set_true(float x, float y);
	sf::Vector2i get_true();
	void set_grid();
	sf::Vector2i get_grid();

	
private:
	sf::RenderWindow *window;
	std::vector<sf::Vector2i> walls;
	sf::Clock dimension_timer;
	
	// grid based collision variables

	int xDirection = 0; // integer value representing the direction the player is facing
	int yDirection = 0;
	float true_x; //x value of player origin relative to level 0,0
	float true_y; //y value of player origin relative to level 0,0
	int grid_x; // tile grid x value of player location
	int grid_y; // tile grid y value of player location

	int y_velocity;
	float dy;
	float prevDx;

	bool freefalling=true;
	float rot;
	float total_time;

};

#endif //PLAYER_HPP
