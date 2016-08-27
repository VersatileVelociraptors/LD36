#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "../level/Level.hpp"

class PlayState : public State{
	
public:
	PlayState(sf::RenderWindow* window);
	~PlayState();
	void update(float dt);
void render();
private:
	Level* level;
	sf::RenderWindow* window;
};

#endif // PLAYSTATE_HPP
