#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Item.h"

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(1080.0f* aspectRatio, 720.0f);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Mali Meaow", sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setPosition(540.0f, 360.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("p/catwalk3.png");
	Player player(&playerTexture, sf::Vector2u(10, 3), 0.3f, 150.0f, 200.0f);
	//player.setTexture(&playerTexture);

	//bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("p/bullet.png");
	Bullet bullet1(&BULLET, sf::Vector2u(6, 1), 0.15f, 600.0f, player.GetPosition());

	sf::RectangleShape background(sf::Vector2f(5000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("p/BG.png");
	background.setTexture(&space);

	sf::Texture Gress;
	Gress.loadFromFile("p/Gress.png");
	
	sf::Texture Din;
	Din.loadFromFile("p/grassCenter_rounded.png");

	sf::Texture Item;
	Item.loadFromFile("p/cat.png");
	std::vector<Item> ItemVector;

	/*for (int posi = 0; posi < 1550; posi += 60)
	{
		ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 800.0f + posi, 550.0f));
	}
	for (int posi = 0; posi < 200; posi += 60)
	{
		ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 2630.0f + posi, 370.0f));
	}*/
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 2850.0f, 320.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 2900.0f, 300.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 2950.0f, 280.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 3000.0f, 300.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 3050.0f, 320.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 3100.0f, 370.0f));
	ItemVector.push_back(Item(&Item, sf::Vector2u(9, 1), 0.08f, 3150.0f, 370.0f));

	std::vector<Platform> platforms;

	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(500.0f, 450.0f)));
	platforms.push_back(Platform(&Gress, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(550.0f, 480.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(&Gress, sf::Vector2f(5000.0f, 100.0f), sf::Vector2f(2500.0f, 700.0f)));
	platforms.push_back(Platform(&Din, sf::Vector2f(100.0f, 400.0f), sf::Vector2f(25.0f, 720.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));

	int count,Bul=0;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {

		count = player.GetPosition().x;

		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';

		std::cout << "Hello";

		/*deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
*/
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				//printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);
				break;
				//case sf::Event::TextEntered:
					//if (evnt.text.unicode < 128) {
						//printf("%c\n", evnt.text.unicode);
				//}
		}

	}
		/*view.setCenter(player.GetPosition());//x=y
		if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(540.0f, 360.0f);//window
			}
			if (view.getCenter().y + 360.0f >= 720.0f)
			{
				view.setCenter(540.0f, 360.0f);//window
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 720.0f)
			{
				view.setCenter(540.0f, player.GetPosition().y);
			}

		}
		if (view.getCenter().x + 540.0f >= 5000.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(708.0f, 360.0f);//window 1248-540 collision right 
			}
			if (view.getCenter().y + 360.0f >= 1329.0f)
			{
				view.setCenter(708.0f, 969.0f);//window 1248-540
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1329.0f)
			{
				view.setCenter(708.0f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1248.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(player.GetPosition().x, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 1329.0f)
			{
				view.setCenter(player.GetPosition().x, 969.0f);
			}
		}*/
	view.setCenter(player.GetPosition().x , 360.0f);
	if (view.getCenter().x - 540.0f <= 0.0f)
	{
		view.setCenter(540.0f, 360.0f);

	}
	if (view.getCenter().x + 540.0f >= 5000.0f)
	{
		view.setCenter(4460.0f, 360.0f);
	}

	player.Update(deltaTime);

	sf::Vector2f direction;
	Collision playerCollision = player.GetCollider();

	//for (int i = 0; i < platforms.size(); i++) {
	//	Platform& platform = platforms[i];
	//}

	for (Platform& platform : platforms)
		if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);

	window.clear();
	window.draw(background);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{

		bullet1.attack(pos);
		Bul = 1;
	}
	if (Bul == 1)
	{  
		bullet1.update(deltaTime);
		bullet1.draw(window);
		
	}
	if (player.GetPosition().x - bullet1.GetPosition().x <= -1000.0f)
	{
		Bul = 0;
		bullet1.isAvaliable();
	}

	//platform1.GetCollider().CheckCollision(player.GetCollider(), 0.5f);
	//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

	view.setCenter(player.GetPosition());
	window.setView(view);
	//bullet1.draw(window);
	player.Draw(window);
	

	for (Platform& platform : platforms)
		platform.Draw(window);
	//platform2.Draw(window);
	//window.draw(player);
	window.clear(sf::Color(135, 206, 250));
	window.display();
	}
	return 0;
}