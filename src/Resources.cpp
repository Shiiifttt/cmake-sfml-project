#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.hpp"
#include "Object.hpp"
#include <iostream>
#include "Utils.hpp"
#include "IDamage.hpp"
#include "Enemy.hpp"

const std::string Resources::player_spr = "../../../assets/images/blue.png";
const std::string Resources::enemy_spr = "../../../assets/images/red.png";
const std::string Resources::bullet_spr = "../../../assets/images/yellow.png";
const std::string Resources::font_ttf = "../../../assets/fonts/Roboto-Bold.ttf";
const std::string Resources::hit_wav = "../../../assets/audio/hitHurt.wav";
const std::string Resources::explode_wav = "../../../assets/audio/explosion.wav";

Resources::Resources() : soundBufferIndex(0) {

	for (int i = 0; i < 4; i++)
		soundBuffer[i].setVolume(50);

}

Resources::~Resources() {

	clean();

}

bool	Resources::loadResources() {

	if (!player_tex.loadFromFile(player_spr))
		return false;
	std::cout << "Loaded " << player_spr << std::endl;

	if (!enemy_tex.loadFromFile(enemy_spr))
		return false;
	std::cout << "Loaded " << enemy_spr << std::endl;

	if (!bullet_tex.loadFromFile(bullet_spr))
		return false;
	std::cout << "Loaded " << bullet_spr << std::endl;

	if (!font.loadFromFile(font_ttf))
		return false;
	std::cout << "Loaded " << font_ttf << std::endl;

	if (!hit_sfx.loadFromFile(hit_wav))
		return false;
	std::cout << "Loaded " << hit_wav << std::endl;

	if (!explode_sfx.loadFromFile(explode_wav))
		return false;
	std::cout << "Loaded " << explode_wav << std::endl;

	return true;
}

sf::Texture*	Resources::getPlayerTex() {
	return &player_tex;
}

sf::Texture*	Resources::getEnemyTex() {
	return &enemy_tex;
}

sf::Texture*	Resources::getBulletTex() {
	return &bullet_tex;
}

sf::Font*	Resources::getFont() {
	return &font;
}

void	Resources::registerObject(Object* obj) {

	std::cout << "register obj" << std::endl;
	scene_objects.push_back(obj);

}

void	Resources::unregisterObject(Object* obj) {

	scene_objects.erase(std::remove(scene_objects.begin(), scene_objects.end(), obj), scene_objects.end());

}

void	Resources::registerDamageInterface(IDamage* interface) {
	
	damage_interfaces.push_back(interface);

}

void	Resources::unregisterDamageInterface(IDamage* interface) {

	damage_interfaces.erase(std::remove(damage_interfaces.begin(), damage_interfaces.end(), interface), damage_interfaces.end());

}

void	Resources::clean() {

	std::cout << "clean resources" << std::endl;

	while (scene_objects.size() > 0)
		scene_objects.pop_back();

	//for (auto o : sceneObjects)
	//	delete o;

}

std::vector<Object*>	Resources::getSceneObjects() {

	return scene_objects;

}

std::vector<IDamage*>	Resources::getDamageInterfaces() {

	return damage_interfaces;

}

void	Resources::playSound(const sf::SoundBuffer& buffer) {
	int	i = soundBufferIndex++ % 4;
	soundBuffer[i].setBuffer(buffer);
	soundBuffer[i].setPitch(1.f + (rand() % 100 / 100.f));
	soundBuffer[i].play();
}

void	Resources::playHitSound() {

	playSound(hit_sfx);

}

void	Resources::playExplodeSound() {

	playSound(explode_sfx);

}