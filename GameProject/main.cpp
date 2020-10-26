#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Mali Meaow",sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setPosition(540.0f, 360.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("catwalk1.png");
	//player.setTexture(&playerTexture);

	sf::RectangleShape background(sf::Vector2f(5000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("BG.png");
	background.setTexture(&space);

	Player player(&playerTexture, sf::Vector2u(5, 4), 0.3f, 100.0f, 200.0f);

	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(500.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 700.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
			}
			
		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		//for (int i = 0; i < platforms.size(); i++) {
		//	Platform& platform = platforms[i];
		//}

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		//platform1.GetCollider().CheckCollision(player.GetCollider(), 0.5f);
		//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

		window.draw(background);
		player.Draw(window);

		for (Platform& platform : platforms)
			platform.Draw(window);
		//platform2.Draw(window);
		//window.draw(player);
		window.display();
	}
	return 0;
}