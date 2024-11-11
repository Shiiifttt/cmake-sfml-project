#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Resources.hpp"
#include "Object.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Camera.hpp"
#include <thread>
#include <iostream>
#include <cmath>

void	renderLoop(Game* game) {

	game->getWindow().setActive(true);
	Resources& resources = Resources::getInstance();

	sf::Text	text = newText(sf::Vector2f(400, 24), "Use WASD to move!", resources.getFont(), 24, sf::Color::White, sf::Text::Bold, font_align::H_CENTER);
	sf::Text	pause = newText(sf::Vector2f(400, 300), "Game is paused (space)", resources.getFont(), 24, sf::Color::White, sf::Text::Bold, font_align::H_CENTER);

	float spawn_timer = 0.f;
	float spawn_interval = 2.f;
	float timeElapsed = 0.f;
	const double pi = 3.14159265358979323846;
	const float frequency = 0.5f;

	while (game->isRunning()) {

		if (game->getGameState() == GameState::Play) {

			float deltaTime = game->getClock().restart().asSeconds();
			timeElapsed += deltaTime;

			spawn_timer += deltaTime;
			if (spawn_timer >= spawn_interval)
			{
				sf::Vector2f	position;

				do {
					position = sf::Vector2f(rand() % 800, rand() % 600);
				} while (distance(game->getPlayer()->getPosition(), position) < 400.f);

				Enemy* enemy = new Enemy(position, resources.getEnemyTex(), 50.f, 10);
				enemy->setTarget(game->getPlayer());
				spawn_timer = 0;
			}

			for (auto obj : resources.getSceneObjects()) {
				if (obj->isEnabled())
					obj->update(deltaTime);
			}

		}

		game->getWindow().clear();

		for (auto obj : resources.getSceneObjects()) {
			if (game->getCamera().pointInsideView(obj->getPosition()))
				obj->drawSprite(game->getWindow());
		}

		game->getWindow().draw(text);

		if (game->getGameState() == GameState::Pause)
			game->getWindow().draw(pause);

		game->getWindow().display();

	}

}

int main() {

	sf::RenderWindow window = sf::RenderWindow({ 800u, 600u }, "A game of all time");
	window.setFramerateLimit(144);
	window.setActive(false);

	Game	game(window);

	if (!game.initSuccess()) {
		std::cout << "Press Enter to exit...";
		std::cin.get(); // Waits for the user to press Enter
		return EXIT_FAILURE;
	}

	std::thread	render(renderLoop, &game);

    while (game.getWindow().isOpen())
    {
        for (auto event = sf::Event(); game.getWindow().pollEvent(event);)
        {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					game.closeGame();
					break;
				}
				else if (event.key.code == sf::Keyboard::Space) {
					GameState state = game.getGameState();
					if (state == GameState::Play) {
						std::cout << "pause" << std::endl;
						game.setGameState(GameState::Pause);
					} else {
						game.unpause();
						std::cout << "unpause" << std::endl;
						game.setGameState(GameState::Play);
					}
				}
			}
            if (event.type == sf::Event::Closed) {
				game.closeGame();
				break;
			}
        }

    }

	render.join();

	std::cout << "Press Enter to exit...";
	std::cin.get(); // Waits for the user to press Enter
	return EXIT_SUCCESS;
}

#ifdef _WIN32

#include "windows.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	return main();
}

#endif