#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "Object.hpp"
#include <iostream>
#include "Utils.hpp"

const std::string Resources::player_spr = "assets/images/blue.png";
const std::string Resources::enemy_spr = "assets/images/red.png";
const std::string Resources::bullet_spr = "assets/images/yellow.png";
const std::string Resources::font_ttf = "assets/fonts/Roboto-Bold.ttf";

Resources::Resources() {

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

	scene_objects.push_back(obj);

}

void	Resources::unregisterObject(Object* obj) {

	scene_objects.erase(std::remove(scene_objects.begin(), scene_objects.end(), obj), scene_objects.end());

}

void	Resources::clean() {

	//for (auto o : sceneObjects)
	//	delete o;

}

std::vector<Object*>	Resources::getSceneObjects() {

	return scene_objects;

}
