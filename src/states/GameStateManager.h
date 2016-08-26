#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H


#include "State.h"
#include "../audio/MusicManager.h"

#include <stack>
#include <SFML/Graphics.hpp>

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow *window);
	~GameStateManager();

	void set(int state);
	void push(int state);
	void pop();
	State* peek();
	void render();
	void update(float dt);
	sf::RenderWindow* getWindow();
	MusicManager* getMusicManager();

private:
	std::stack<State*> states;
	sf::RenderWindow *window;
	MusicManager *musicManager;
	
};


#endif //GAMESTATEMANAGER_H