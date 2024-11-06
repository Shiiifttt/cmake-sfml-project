
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include "Bullet.h"
#include "Resources.h"
#include "Enemy.h"

#include <iostream>

Player::Player(const float& x, const float& y, sf::Texture* tex, const float& movespeed) : Object(x, y, tex), face_dir(1), shootInterval(0.2f), shootTimer(0), bulletDamage(1) {
	setMovespeed(movespeed);
};

void	Player::input(const float& deltaTime) {

	float delta_x = 0.f;
	float delta_y = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		delta_x -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		delta_x += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		delta_y -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		delta_y += 1.f;

	sf::Vector2f dir = normalize(sf::Vector2f(delta_x, delta_y));
	this->move(dir * getMovespeed() * deltaTime);

	if (delta_x != 0 && face_dir != delta_x) {
		face_dir = delta_x;
		getSprite()->setScale(sf::Vector2f(face_dir, 1.f));
	}
}

void	Player::update(const float& deltaTime) {

	// if alive

	input(deltaTime);

	shootTimer += deltaTime;
	if (shootTimer >= shootInterval) {
		shoot();
		shootTimer = 0;
	}
}

void	Player::shoot() {

	Enemy*	target = nullptr;
	float	closest = std::numeric_limits<float>::infinity();

	Resources& resources = Resources::getInstance();
	std::vector<Object*> allObjects = resources.getSceneObjects();

	sf::Vector2f	pos = getPosition();
	sf::Vector2f	target_pos;

	for (auto obj : allObjects) {
		if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {

			if (!enemy->isEnabled())
				continue;

			target_pos = enemy->getPosition();
			float dist = distance(pos, target_pos);

			//if (dist > 200.f) Range
			//	continue;

			if (dist < closest) {
				target = enemy;
				closest = dist;
			}
		}
	}

	if (target == nullptr)
		return;

	target_pos = target->getPosition();

	sf::Vector2f	bullet_dir = normalize(target_pos - pos);
	Bullet*	bullet = new Bullet(pos.x, pos.y, resources.getBulletTex(), 600.f, bullet_dir, 2.f, bulletDamage);

}