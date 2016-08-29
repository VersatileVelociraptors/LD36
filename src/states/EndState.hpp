#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP

#include "State.hpp"
#include "GameStateManager.hpp"
#include "../ui/ExitButton.hpp"

class GameStateManager;

class EndState : public State{

public:
	EndState(GameStateManager* manager);
	~EndState();
	void update(float dt);
	void render();

private:
	GameStateManager* manager;
	sf::RenderWindow* window;
	ExitButton* exitButton;
};

#endif // ENDSTATE_HPP
