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
	if(!this->texture.loadFromFile("assets/images/pizzaplayer.png"))
		level->getWindow()->close();
	
	this->setTexture(this->texture);

	this->diag = (int) this->speed * sqrt(2)/2;
	
	sf::IntRect texture_rect = this->getTextureRect();
	this->setOrigin(texture_rect.width/2, texture_rect.height/2);
	this->setScale(1.0f, 1.0f);

}

// use grid based collision

void Player::set_true(float x, float y){
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
	float dts = dt/1000000.0; 
	if (dimension_timer.getElapsedTime().asSeconds() > DIMENSION_CHANGE_DELAY &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {
		// change dimensions
		level->changeDimensions();
		dimension_timer.restart();
	}


	xDirection = 0;
	yDirection = 1;
	set_grid();

	// keyboard input for movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		xDirection = -1;
		rot-= ((float)speed)/PLAYER_HEIGHT*180/PI;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		xDirection = 1;
		rot+= ((float)speed)/PLAYER_HEIGHT*180/PI;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		yDirection = -1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		yDirection = 1;
	}
	
	if(xDirection==-1){
		if(level->tile_solid_grid(get_grid().x-1,get_grid().y)){
			if(true_x-PLAYER_WIDTH/2<=(get_grid().x)*TILE_SIZE){
			}else{
				move(speed, 0);
			}
		}else{
			move(speed,0);
		}
	}else if(xDirection==1){
		if(level->tile_solid_grid(get_grid().x+1,get_grid().y)){
			if(true_x+PLAYER_WIDTH/2>=(get_grid().x+1)*TILE_SIZE){
			}else{
				move(-speed, 0);
			}
			
		}else{
			move(-speed,0);
		}
	}


	if(freefalling){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			y_velocity = 5;
			//freefalling=true;
		}
		//y_velocity-=GRAVITY;
		total_time += dts*20;
		dy = y_velocity*total_time+0.5*GRAVITY*total_time*total_time;
		std::cout << dy << std::endl;
		if(dy<0){
			if(level->tile_solid_grid(get_grid().x,get_grid().y+1)){
				if(true_y-PLAYER_HEIGHT/2+dy<=(get_grid().y)*TILE_SIZE){
					//freefalling=false;
					total_time=0;
					y_velocity = 0;
					level->positionPlayer(true_x,(get_grid().y+0.5)*TILE_SIZE);
				}else{
					move(0,dy);
				}
			}else{
				move(0,dy);
			}
		}else if(dy>0){
			if(level->tile_solid_grid(get_grid().x,get_grid().y) ){
				if(true_y+PLAYER_HEIGHT/2+dy>=(get_grid().y)*TILE_SIZE){
					//freefalling=false;
					total_time = 0;
					y_velocity = 0;
					level->positionPlayer(true_x,(get_grid().y)*TILE_SIZE);
				}else{
					move(0,dy);
				}
				
			}else{
				move(0,dy);
			}
		}
	}else{
		total_time = 0;
	}

	setRotation(rot);
}


void Player::move(float x, float y){
	level->setXOffset(level->getXOffset() + x);
	level->setYOffset(level->getYOffset() + y);
	set_true(get_true().x-x, get_true().y-y);
}
