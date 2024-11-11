
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Bullet.hpp"
#include "IMovement.hpp"
#include "Resources.hpp"
#include "Enemy.hpp"
#include "Utils.hpp"
#include "IDamage.hpp"

#include <iostream>

Bullet::Bullet(const sf::Vector2f& position, sf::Texture* tex, const float& movespeed, const sf::Vector2f& dir, const float& lifetime, const int& damage) : Object(position, tex), dir(dir), lifetime(lifetime), damage(damage) {

	setMovespeed(movespeed);

};

void	Bullet::update(const float& deltaTime) {

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
	sf::Vector2f	pos = getPosition();

	Resources& resources = Resources::getInstance();
	std::vector<IDamage*> dmgInterfaces = resources.getDamageInterfaces();

	if (dmgInterfaces.empty())
		return false;

	sf::Vector2f	target_pos;

	for (auto obj : dmgInterfaces) { // O(n^2), find a better way
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
	resources.playHitSound();

	// TODO: Pool this instead of delete
	delete this;
	return true;

}