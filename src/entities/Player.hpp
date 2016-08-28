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

#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 64
#define GRAVITY -1

class Player : public Mob
{
public:
	Player();
	Player(Level *level);
	~Player();
	void move(int x, int y);
	int getDir();
	void update(float dt);
	void setLevel(Level *level);
	void init();

	// grid based collision methods

	void set_true(int x, int y);
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
	int true_x; //x value of player origin relative to level 0,0
	int true_y; //y value of player origin relative to level 0,0
	int grid_x; // tile grid x value of player location
	int grid_y; // tile grid y value of player location

	int y_velocity;

	bool freefalling=false;

};

#endif //PLAYER_HPP
