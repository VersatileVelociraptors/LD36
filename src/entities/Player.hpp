#ifndef PLAYER_HPP
#define PLAYER_HPP


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Mob.hpp"

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
private:
	sf::RenderWindow *window;
	std::vector<sf::Vector2i> walls;
	int dir;
	int timer;
	int box_timer;
	
};

#endif //PLAYER_HPP
