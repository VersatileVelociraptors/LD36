#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
	State();
	virtual ~State();
	virtual void render() = 0;
	virtual void update(float dt) = 0;
	
};

#endif //STATE_HPP
