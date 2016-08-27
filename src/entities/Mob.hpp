#ifndef MOB_HPP
#define MOB_HPP

#include "Entity.hpp"

class Mob : public Entity
{
public:
	Mob();
	~Mob();
	void takeDamage(double damage);
	double getHealth();
	void update(float dt);
protected:
	void setHealth(double health);
private:
	double health;
	
};

#endif //MOB_HPP
