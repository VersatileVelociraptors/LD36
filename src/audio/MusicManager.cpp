#include "MusicManager.h"


#ifdef _WIN32
#include "../dirent/dirent.h"
#else
#include <dirent.h>
#endif

#include <iostream>
#include <cstring>

using std::vector;
using std::string;

MusicManager::MusicManager(sf::RenderWindow *window){
	this->window = window;
	musics = new std::unordered_map<string, sf::Music*>();
}

MusicManager::~MusicManager(){

	for( std::unordered_map<string, sf::Music*>::iterator i = musics->begin(); i != musics->end(); ++i ){
		delete i->second;
	}

	delete musics;

}

void MusicManager::addAllMusicInAssets(){
	DIR *dir;
	struct dirent *ent;

	if((dir = opendir(this->ASSETS_MUSIC_PATH)) != NULL){
		while((ent = readdir(dir)) != NULL){ 
			int len = strlen(ent->d_name);
			if(len > 4){
				const char* extension = &ent->d_name[len - 4];
				if(strcmp(extension, ".wav") == 0){
					char name[len-4 + 1];
					memcpy(name, &ent->d_name[0], (len-4)*sizeof(char));
					name[len-4] = '\0';
					char path[80];
					strcpy(path, this->ASSETS_MUSIC_PATH);
					strcat(path, ent->d_name);
					addMusic(string(name), path);
				}
			}
		}
		closedir(dir);
	} else {
		std::cout << "Error opening directory " << this->ASSETS_MUSIC_PATH << std::endl;
		window->close();
	}

}

void MusicManager::addMusic(string name, sf::Music *music){
	(*musics)[name] = music;
}

void MusicManager::addMusic(string name, char* path){

	sf::Music *music = new sf::Music();
	if(!music->openFromFile(path))
		window->close();
	(*musics)[name] = music;
}

void MusicManager::play(string name){

	if(musics->find(name) == musics->end()){
		std::cout << "Music not found! " << name << std::endl;
		window->close();
		return;
	}

	sf::Music* music = musics->find(name)->second;
	if(music->getStatus() != sf::SoundSource::Playing)
		music->play();

}

void MusicManager::loop(string name){

	if(musics->find(name) == musics->end()){
		std::cout << "Music not found!" << std::endl;
		window->close();
		return;
	}

	sf::Music* music = musics->find(name)->second;
	
	music->setLoop(true);

}

void MusicManager::stop(string name){

	sf::Music* music = musics->find(name)->second;
	if(music == musics->end()->second){
		std::cout << "Music not found!" << std::endl;
		window->close();
		return;
	}

	music->stop();

}

void MusicManager::stop(){

	for( std::unordered_map<string, sf::Music*>::iterator i = musics->begin(); i != musics->end(); ++i ){
		i->second->stop();
	}

}

vector<string> MusicManager::getMusicsNames(){
	std::vector<string> names;
	for( std::unordered_map<string, sf::Music*>::iterator i = musics->begin(); i != musics->end(); ++i ){
		names.push_back(i->first);
	}
	return names;
}

vector<sf::Music*> MusicManager::getMusics(){
	std::vector<sf::Music*> music;
	for( std::unordered_map<string, sf::Music*>::iterator i = musics->begin(); i != musics->end(); ++i ){
		music.push_back(i->second);
	}	
	return music;
}

