#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Utils.hpp"

const float Enemy::chaseTreshold = 16.f;

Enemy::Enemy(const sf::Vector2f& position, sf::Texture* tex, const float& movespeed, const int& maxHealth) : Object(position, tex), target(nullptr), maxHealth(maxHealth) {

	setMovespeed(movespeed);
	health = maxHealth;

};

void	Enemy::update(const float& deltaTime) {

	if (target == nullptr)
		return;

	sf::Vector2f	pos = getPosition();
	sf::Vector2f	target_pos = target->getPosition();

	if (distance(pos, target_pos) < chaseTreshold)
		return;

	sf::Vector2f dir = normalize(target_pos - pos);
	move(dir * getMovespeed() * deltaTime);
}

void	Enemy::setTarget(Object* obj) {

	target = obj;

}

void	Enemy::takeDamage(const int& damage) {

	health -= damage;

	if (health <= 0)
		onDeath();

}

void	Enemy::onDeath() {

	// TODO: Pool this instead of delete
	delete this;

}