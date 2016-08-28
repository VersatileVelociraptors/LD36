#include "PlayState.hpp"

#include <cstring>
#include <string>//for testing

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	
	std::string str = "assets/levels/test.txt";
	char cstr[str.length() - 1];
	std::strcpy(cstr, str.c_str());
	Player* player = new Player();
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	player->set_true((int) window->getSize().x/2,(int) window->getSize().y/2);
	this->level = new Level(cstr, window, player);
	
	player->setLevel(level);
	player->init();
}

PlayState::~PlayState(){
	delete level;
}

void PlayState::update(float dt){
	level->update(dt);
}

void PlayState::render(){
	level->render();
	window->draw(*level->getPlayer());// draw player texture
}
