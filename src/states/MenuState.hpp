#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State{

public:
	void update();
	void render(float dt);

};

#endif // MENUSTATE_HPP
