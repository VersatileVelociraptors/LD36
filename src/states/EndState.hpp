#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP

#include "State.hpp"

class EndState : public State{

public:
	void update();
	void render(float dt);

};

#endif // ENDSTATE_HPP
