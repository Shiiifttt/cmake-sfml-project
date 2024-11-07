#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Resources.hpp"
#include "Utils.hpp"
#include "Camera.hpp"

int main() {

    auto window = sf::RenderWindow({800u, 600u}, "A game of all time");
    window.setFramerateLimit(144);

	sf::Clock clock;

	Resources& resources = Resources::getInstance();
	if (!resources.loadResources())
		return EXIT_FAILURE;

	Camera camera = Camera(sf::Vector2f(800, 600), 128);
	camera.setPosition(sf::Vector2f(400, 300));

    Player*	player = new Player(sf::Vector2f(400, 300), resources.getPlayerTex(), 200.f);
    Enemy*	enemy = new Enemy(sf::Vector2f(64,64), resources.getEnemyTex(), 50.f, 10);
	enemy->setTarget(player);

	sf::Text text = newText(sf::Vector2f(400, 24), "Use WASD to move!", resources.getFont(), 24, sf::Color::White, sf::Text::Bold, font_align::H_CENTER);

	const float	spawn_internval = 2.f;
	float	spawn_timer = 0.f;

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		float deltaTime = clock.restart().asSeconds();

		spawn_timer += deltaTime;
		if (spawn_timer >= spawn_internval)
		{
			//Enemy* enemy = new Enemy(sf::Vector2f(64, 64), resources.getEnemyTex(), 50.f, 10);
			//enemy->setTarget(player);
			spawn_timer = 0;
		}

		for (auto obj : resources.getSceneObjects()) {
			if (obj->isEnabled())
				obj->update(deltaTime);
		}

        window.clear();

		for (auto obj : resources.getSceneObjects()) {
			if (camera.pointInsideView(obj->getPosition()))
				obj->drawSprite(window);
		}

		window.draw(text);
        window.display();
    }

	resources.clean();

	return EXIT_SUCCESS;
}

#ifdef _WIN32

#include "windows.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	return main();
}

#endif