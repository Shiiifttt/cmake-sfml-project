#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "IMovement.h"

class Bullet : public Object, public IMovement {

	sf::Vector2f	dir;
	float	lifetime;
	int		damage;

public:
	Bullet(const float& x, const float& y, sf::Texture* tex, const float& movespeed, const sf::Vector2f& dir, const float& lifetime, const int& damage);

	void update(const float& deltaTime) override;
	bool	collisionCheck();

};