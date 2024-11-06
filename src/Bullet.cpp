
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Bullet.h"
#include "IMovement.h"
#include "Resources.h"
#include "Enemy.h"
#include "Utils.h"

#include <iostream>

Bullet::Bullet(const float& x, const float& y, sf::Texture* tex, const float& movespeed, const sf::Vector2f& dir, const float& lifetime, const int& damage) : Object(x, y, tex), dir(dir), lifetime(lifetime), damage(damage) {
	setMovespeed(movespeed);
};

void	Bullet::update(const float& deltaTime) {

	if (!isEnabled())
		return;

	if (collisionCheck())
		return;

	lifetime -= deltaTime;

	if (lifetime <= 0.f)
	{
		// TODO: Pool this instead of delete
		delete this;
		return;
	}

	move(dir * getMovespeed() * deltaTime);
}

bool	Bullet::collisionCheck() {

	Enemy* target = nullptr;

	Resources& resources = Resources::getInstance();
	std::vector<Object*> allObjects = resources.getSceneObjects();

	sf::Vector2f	pos = getPosition();
	sf::Vector2f	target_pos;

	for (auto obj : allObjects) {
		if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {

			// Make better overlap check
			target_pos = enemy->getPosition();

			if (distance(pos, target_pos) < 16.f) {
				target = enemy;
				break;
			}
		}
	}

	if (target == nullptr)
		return false;

	target->takeDamage(damage);

	// TODO: Pool this instead of delete
	delete this;
	return true;

}