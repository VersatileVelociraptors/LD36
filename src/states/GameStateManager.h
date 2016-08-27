#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H


#include "State.h"
#include "../audio/MusicManager.h"

#include <SFML/Graphics.hpp>

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow *window);
	~GameStateManager();

	void set(int state);
	void push(int state);
	void pop();
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


#endif //GAMESTATEMANAGER_H
