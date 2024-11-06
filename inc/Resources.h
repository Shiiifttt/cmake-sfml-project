#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Resources {

	static const std::string	player_spr;
	static const std::string	enemy_spr;
	static const std::string	bullet_spr;
	static const std::string	font_ttf;

	sf::Font	font;
	sf::Texture	player_tex;
	sf::Texture	enemy_tex;
	sf::Texture	bullet_tex;

	std::vector<Object*>	sceneObjects;

public:

	Resources();
	Resources(const Resources& r) = delete;
	Resources& operator=(const Resources& r) = delete;
	~Resources();

	bool	loadResources();
	sf::Texture*	getPlayerTex();
	sf::Texture*	getEnemyTex();
	sf::Texture*	getBulletTex();
	sf::Font*	getFont();

	void	registerObject(Object* obj);
	void	unregisterObject(Object* obj);
	void	Resources::clean();
	std::vector<Object*>	getSceneObjects();

	static Resources& getInstance() {
		static Resources instance;
		return instance;
	};

};