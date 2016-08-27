#ifndef ENTITY_HPP
#define ENTITY_HPP

#ifndef SFML_STATIC
#define SFML_STATIC
#endif


#include <SFML/Graphics.hpp>

class Level;

class Entity : public sf::Sprite
{
public:
	Entity();
	Entity(sf::Texture image, Level *level);
	~Entity();
	bool isAlive();
	void setAlive(bool isAlive);
	void setSpeed(int speed);
	int getSpeed();
	virtual void update(float dt) = 0;
protected:
	sf::Texture texture;
	Level *level;
	int speed;
	int diag;
	bool living;
};

#endif //ENTITY_HPP
