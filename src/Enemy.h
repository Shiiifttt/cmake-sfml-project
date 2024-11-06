#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "IMovement.h"

class Enemy : public Object, public IMovement
{

	int	health;
	int	maxHealth;

	static const float chaseTreshold;
	Object* target;

public:
	Enemy(const float& x, const float& y, sf::Texture* tex, const float& movespeed, const int& maxHealth);
	void update(const float& deltaTime) override;

	void	setTarget(Object* obj);
	void	takeDamage(const int& damage);

};