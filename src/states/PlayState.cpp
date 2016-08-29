#include "PlayState.hpp"

#include <cstring>
#include <string>//for testing

PlayState::PlayState(sf::RenderWindow* window, GameStateManager* manager){
	this->window = window;
	
	Player* player = new Player();
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	this->level = new Level(window, player);
	
	player->setLevel(level);
	player->init();
	
	this->manager = manager;
}

PlayState::~PlayState(){
	delete level;
}

void PlayState::start(){
	level->changeMessage(MESSAGE_1);
}

void PlayState::update(float dt){
	level->update(dt);
	
	if (level->getCurrentLevel() >= LEVEL_COUNT) {
		manager->set(END);
	}
}

void PlayState::render(){
	level->render();
	window->draw(*level->getPlayer());// draw player texture
}
