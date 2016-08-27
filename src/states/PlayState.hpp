#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "State.hpp"

class PlayState : public State{
	
public:
	void update();
	void render(float dt);
	
};

#endif // PLAYSTATE_HPP
