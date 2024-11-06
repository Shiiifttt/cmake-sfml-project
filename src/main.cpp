#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Resources.h"
#include "Utils.h"
#include <string>

int main() {
	// Game init and resource loading

    auto window = sf::RenderWindow({800u, 600u}, "A game of all time");
    window.setFramerateLimit(144);

	sf::Clock clock;

	Resources& resources = Resources::getInstance();
	if (!resources.loadResources())
		return EXIT_FAILURE;

    Player*	player = new Player(400.f, 300.f, resources.getPlayerTex(), 200.f);
    Enemy*	enemy = new Enemy(64.f, 64.f, resources.getEnemyTex(), 50.f, 10);
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
			Enemy* enemy = new Enemy(64.f, 64.f, resources.getEnemyTex(), 50.f, 10);
			enemy->setTarget(player);
			spawn_timer = 0;
		}

		for (auto obj : resources.getSceneObjects()) {
			obj->update(deltaTime);
		}

        window.clear();

		for (auto obj : resources.getSceneObjects()) {
			obj->drawSprite(window);
		}

		window.draw(text);
        window.display();
    }

	resources.clean();

}

#ifdef _WIN32

#include "windows.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	main();
}

#endif