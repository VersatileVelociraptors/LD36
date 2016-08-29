#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "GameStateManager.hpp"
#include "../level/Level.hpp"

class GameStateManager;

class PlayState : public State{
	
public:
	PlayState(sf::RenderWindow* window, GameStateManager* manager);
	~PlayState();
	void start();
	void update(float dt);
	void render();
private:
	Level* level;
	sf::RenderWindow* window;
	GameStateManager* manager;
};

#endif // PLAYSTATE_HPP
