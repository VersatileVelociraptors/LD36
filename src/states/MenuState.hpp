#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "../ui/StartButton.hpp"
#include "../ui/ExitButton.hpp"
#include "GameStateManager.hpp"
#include <string>


class GameStateManager;

class MenuState : public State{

public:
	MenuState(GameStateManager* manager);
	~MenuState();
	void update(float dt);
	void render();

private:
	StartButton* startButton;
	ExitButton* exitButton;
	GameStateManager* manager;
	sf::RenderWindow* window;

	sf::Text line1;
	sf::Text line2;
	sf::Font font;

};

#endif // MENUSTATE_HPP
