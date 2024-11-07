#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "IMovement.hpp"

class Enemy : public Object, public IMovement
{

	int	health;
	int	maxHealth;

	static const float chaseTreshold;
	Object* target;

public:
	Enemy(const sf::Vector2f& position, sf::Texture* tex, const float& movespeed, const int& maxHealth);

	void	update(const float& deltaTime) override;
	void	setTarget(Object* obj);
	void	takeDamage(const int& damage);
	void	onDeath();

};