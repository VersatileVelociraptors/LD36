#include "PlayState.hpp"

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	this->level = new Level("assets/levels/level01.txt", window);
}

PlayState::~PlayState(){
	delete level;
}

void PlayState::update(float dt){
	level->update(dt);
}

void PlayState::render(){
	level->render();
}
