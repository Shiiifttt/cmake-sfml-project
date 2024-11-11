#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "IMovement.hpp"
#include "IDamage.hpp"

class Enemy : public Object, public IMovement, public IDamage
{

	int	health;
	int	maxHealth;

	static const float chaseTreshold;
	Object* target;

public:
	Enemy(const sf::Vector2f& position, sf::Texture* tex, const float& movespeed, const int& maxHealth);
	~Enemy();

	void	update(const float& deltaTime) override;
	void	setTarget(Object* obj);
	void	onDeath();

	void	takeDamage(const int& damage) override;

};