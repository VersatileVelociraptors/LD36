#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP


#include "State.hpp"
#include "../audio/MusicManager.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics.hpp>

class MenuState;

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
	PlayState* playState;
	MenuState* menuState;
	bool stoppedMusic = false;
};

#endif //GAMESTATEMANAGER_HPP
