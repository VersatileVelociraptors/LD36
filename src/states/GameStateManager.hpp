#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP


#include "State.hpp"
#include "../audio/MusicManager.h"

#include <SFML/Graphics.hpp>

enum StateEnumeration {
	MENU, PLAY, END
};

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow *window);
	~GameStateManager();

	void set(StateEnumeration state);
	void render();
	void update(float dt);
	sf::RenderWindow* getWindow();
	MusicManager* getMusicManager();
	State* getCurrentState();
	void setCurrentState(State* state);

private:
	State* currentState;
	sf::RenderWindow *window;
	MusicManager *musicManager;
	
};

#endif //GAMESTATEMANAGER_HPP
