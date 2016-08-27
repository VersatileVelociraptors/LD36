#include "PlayState.hpp"

#include <cstring>

PlayState::PlayState(sf::RenderWindow* window){
	this->window = window;
	
	std::string str = "assets/levels/level02.txt";
	char cstr[str.length() - 1];
	std::strcpy(cstr, str.c_str());
	this->level = new Level(cstr, window);
	
	Player* player = new Player(level);
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	level->setPlayer(player);
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
