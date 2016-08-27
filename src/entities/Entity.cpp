#include "Entity.hpp"
#include "../level/Level.hpp"
#include <cmath>

Entity::Entity(){
	speed = 10;
	living = true;
}

Entity::Entity(sf::Texture image, Level *level){

	speed = 10;
	living = true;
	texture = image;

	this->level = level;
	this->setTexture(texture);

	diag = (int) speed * sqrt(2)/2;

}

Entity::~Entity(){

}

void Entity::setSpeed(int speed){
	this->speed = speed;
}

int Entity::getSpeed(){
	return this->speed;
}

bool Entity::isAlive(){
	return living;
}

void Entity::setAlive(bool living){
	this->living = living;
}
