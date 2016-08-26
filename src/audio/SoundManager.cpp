#include "SoundManager.h"

#ifdef _WIN32
#include "../dirent/dirent.h"
#else
#include <dirent.h>
#endif

#include <iostream>
#include <cstring>

using std::vector;
using std::string;
using std::unordered_map;

SoundManager::SoundManager(sf::RenderWindow *window){
	this->window = window;
	sounds = new unordered_map<string, Sounds*>();
}

SoundManager::~SoundManager(){

	for( unordered_map<string, Sounds*>::iterator i = sounds->begin(); i != sounds->end(); ++i ){
		delete i->second;
	}

	delete sounds;

}

void SoundManager::addAllSoundInAssets(){
	DIR *dir;
	struct dirent *ent;

	if((dir = opendir(this->ASSETS_SOUND_PATH)) != NULL){
		while((ent = readdir(dir)) != NULL){ 
			int len = strlen(ent->d_name);
			if(len > 4){
				const char* extension = &ent->d_name[len - 4];
				if(strcmp(extension, ".wav") == 0){
					char name[len-4 + 1];
					memcpy(name, &ent->d_name[0], (len-4)*sizeof(char));
					name[len-4] = '\0';
					char path[80];
					strcpy(path, this->ASSETS_SOUND_PATH);
					strcat(path, ent->d_name);
					addSound(string(name), path);
				}
			}
		}
		closedir(dir);
	} else {
		std::cout << "Error opening directory " << this->ASSETS_MUSIC_PATH << std::endl;
		window->close();
	}

}

void SoundManager::addSound(string name, sf::SoundBuffer sound_buffer){
	sf::SoundBuffer *sb = new sf::SoundBuffer(sound_buffer);
	sf::Sound *sound = new sf::Sound();
	sound->setBuffer(*sb);
	Sounds *temp = new Sounds(sb, sound);
	(*sounds)[name] = temp;
}

void SoundManager::addSound(string name, char* path){
	sf::SoundBuffer *sb = new sf::SoundBuffer();
	if(!sb->loadFromFile(path)){
		delete sb;
		window->close();
	}
	sf::Sound *sound = new sf::Sound();
	sound->setBuffer(*sb);
	Sounds *temp = new Sounds(sb, sound);
	(*sounds)[name] = temp; 
}

void SoundManager::play(string name){
	if(sounds->find(name) == sounds->end()){
		std::cout << "Sound not found! " << name << std::endl;
		window->close();
		return;
	}
	sf::Sound *sound = sounds->find(name)->second->sound;
	sound->play();
}

void SoundManager::loop(string name){
	if(sounds->find(name) == sounds->end()){
		std::cout << "Sound not found! " << name << std::endl;
		window->close();
		return;
	}

	sf::Sound *sound = sounds->find(name)->second->sound;
	if(sound->getStatus() != sf::SoundSource::Playing)
		sound->setLoop(true);
}

void SoundManager::stop(string name){
	if(sounds->find(name) == sounds->end()){
		std::cout << "Sound not found! " << name << std::endl;
		window->close();
		return;
	}

	sf::Sound *sound = sounds->find(name)->second->sound;
	if(sound->getStatus() != sf::SoundSource::Playing)
		sound->stop();
}

void SoundManager::stop(){
	for( std::unordered_map<string, Sounds*>::iterator i = sounds->begin(); i != sounds->end(); ++i ){
		i->second->sound->stop();
	}
}

vector<string> SoundManager::getSoundsNames(){
	std::vector<string> names;
	for( std::unordered_map<string, Sounds*>::iterator i = sounds->begin(); i != sounds->end(); ++i ){
		names.push_back(i->first);
	}
	return names;
}

vector<sf::SoundBuffer*> SoundManager::getSounds(){
	std::vector<sf::SoundBuffer*> sound;
	for( std::unordered_map<string, Sounds*>::iterator i = sounds->begin(); i != sounds->end(); ++i ){
		sound.push_back(i->second->sb);
	}	
	return sound;
}