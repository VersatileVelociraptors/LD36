#include "Player.hpp"
#include "../level/Level.hpp"

Player::Player(){

}

Player::Player(Level *level){

	setLevel(level);

	init();

}

Player::~Player(){
	
}

void Player::setLevel(Level *level){
	this->level = level;
}

void Player::init(){
	this->window = level->getWindow();
	if(!this->texture.loadFromFile("assets/images/player.png"))
		level->getWindow()->close();
	
	this->setTexture(this->texture);

	this->diag = (int) this->speed * sqrt(2)/2;

	walls = level->getWalls();
	sf::IntRect texture_rect = this->getTextureRect();
	this->setOrigin(texture_rect.width/2, texture_rect.height/2);
	this->setScale(1.0f, 1.0f);
}
/*
void Player::move(int x, int y){
	level->setXOffset(level->getXOffset() + x);
	level->setYOffset(level->getYOffset() + y);
}
*/
int Player::getDir(){
	return dir;
}
/*
void Player::update(float dt){

	// move around with keyboard input
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			this->setRotation(315);
			move(diag, diag);
			dir = 7;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			this->setRotation(225);
			move(diag, -diag);
			dir = 5;
		}else if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
							&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
			this->setRotation(270);
			move(speed, 0);
			dir = 6;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			this->setRotation(45);
			move(-diag, diag);
			dir = 1;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			this->setRotation(135);
			move(-diag, -diag);
			dir = 3;
		}else if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
							&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
			this->setRotation(90);
			move(-speed, 0);
			dir = 2;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			this->setRotation(315);
			move(diag, diag);
			dir = 7;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			this->setRotation(45);
			move(-diag, diag);
			dir = 1;
		}else if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
							&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
			this->setRotation(0);
			move(0, speed);
			dir = 0;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			this->setRotation(225);
			move(diag, -diag);
			dir = 5;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			this->setRotation(135);
			move(-diag, -diag);
			dir = 3;
		}else if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
							&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
			this->setRotation(180);
			move(0, -speed);
			dir = 4;
		}
	}

	if(level->inSolid(this->getPosition().x, this->getPosition().y)){
		switch(dir){
			case 0:
			move(0, -speed);
			break;
			case 1:
			move(diag, -diag);
			break;
			case 2:
			move(speed, 0);
			break;
			case 3:
			move(diag, diag);
			break;
			case 4:
			move(0, speed);
			break;
			case 5:
			move(-diag, diag);
			break;
			case 6:
			move(-speed, 0);
			break;
			case 7:
			move(-diag, -diag);
			break;
		}
	}
	
	box_timer++;
}*/



// new stuff

void Player::set_true(int x, int y){
	true_x=x;
	true_y=y;
}

void Player::set_grid(){
	grid_x=(true_x*1.0/TILE_SIZE);
	grid_y=(true_y*1.0/TILE_SIZE);
}

sf::Vector2i Player::get_grid(){
	sf::Vector2i value(grid_x,grid_y);
	return value;
}

sf::Vector2i Player::get_true(){
	sf::Vector2i value(true_x,true_y);
	return value;
}


//overwritten stuff

void Player::update(float dt){


	dir =0;
	set_grid();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		this->setScale(-1,1);
		dir = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		this->setScale(1,1);
		dir = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		dir = -2;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		dir = 2;
	}
	if(dir!=0){
		if(dir==-1){
			if(level->tile_solid_grid(get_grid().x-1,get_grid().y)){
				if(true_x-PLAYER_WIDTH<=(get_grid().x)*TILE_SIZE){

				}else{
					move(speed, 0);
				}
			}else{
				move(speed,0);
			}	
		}
		if(dir==1){
			if(level->tile_solid_grid(get_grid().x+1,get_grid().y)){
				if(true_x+PLAYER_WIDTH>=(get_grid().x+1)*TILE_SIZE){

				}else{
					move(-speed, 0);
				}

			}else{
				move(-speed,0);
			}	
		}
		if(dir==-2){
			if(level->tile_solid_grid(get_grid().x,get_grid().y-1)){
				if(true_y-PLAYER_HEIGHT<=(get_grid().y)*TILE_SIZE){

				}else{
					move(0,speed);
				}

			}else{
				move(0,speed);
			}	
		}
		if(dir==2){
			if(level->tile_solid_grid(get_grid().x,get_grid().y+1) ){
				if(true_y+PLAYER_HEIGHT>=(get_grid().y+1)*TILE_SIZE){

				}else{
					move(0, -speed);
				}

			}else{
				move(0, -speed);
			}	
		}
	}
	
	box_timer++;
}


void Player::move(int x, int y){
	level->setXOffset(level->getXOffset() + x);
	level->setYOffset(level->getYOffset() + y);
	set_true(get_true().x-x, get_true().y-y);
}