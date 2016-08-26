#ifndef STATE_H
#define STATE_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp> 

class State
{
public:
	State();
	virtual ~State();
	virtual void render() = 0;
	virtual void update(float dt) = 0;
	
};

#endif //STATE_H