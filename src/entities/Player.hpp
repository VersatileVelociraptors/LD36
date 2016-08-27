#ifndef PLAYER_HPP
#define PLAYER_HPP


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Mob.hpp"


#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 64



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


	//new stuff

	void set_true(int x, int y); 
	sf::Vector2i get_true();
	void set_grid(); 
	sf::Vector2i get_grid();	
private:
	sf::RenderWindow *window;
	std::vector<sf::Vector2i> walls;
	int dir;	
	int timer;
	int box_timer;

	//new stuff

	int direction; // integer value representing the direction the player is facing
	int true_x; //x value of player origin relative to level 0,0
	int true_y; //y value of player origin relative to level 0,0
	int grid_x; // tile grid x value of player location
	int grid_y; // tile grid y value of player location
	bool freefalling; //is gravity on
};

#endif //PLAYER_HPP
