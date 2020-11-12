#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Item.h"
#include "time.h"
#include "Enemy.h"

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(1080.0f* aspectRatio, 720.0f);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Mali Meaow", sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	view.setSize(1080.0f, 720.0f);
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setPosition(540.0f, 360.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("p/catwalk3.png");
	Player player(&playerTexture, sf::Vector2u(10, 3), 0.1f, 150.0f, 200.0f);
	//player.setTexture(&playerTexture);

	//bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("p/bullet.png");
	Bullet bullet1(&BULLET, sf::Vector2u(6, 1), 0.15f, 600.0f, player.GetPosition());

	//BG
	sf::RectangleShape background(sf::Vector2f(5000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("p/BG.png");
	background.setTexture(&space);

	//Snail Enemy
	sf::Texture snail;
	snail.loadFromFile("p/snail.png");
	std::vector <Enemy> SnailVector;

	//Coin
	srand(time(NULL));
	sf::Texture ITEM;
	ITEM.loadFromFile("p/cointest.png");
	std::vector <Item> itemVector;

	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, (rand() % 1000 + 20), 560.0f));
	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, (rand() % 1000 + 20), 400.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 651.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 691.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 731.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 771.0f, 560.0f));

	//Snail
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 651.0f, 580.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 691.0f, 580.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 5337.0f, 564.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 6815.0f, 280.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 8928.0f, 564.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 11580.0f, 564.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 15504.0f, 564.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 16943.0f, 280.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 22955.0f, 377.0f));
	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(12, 8), 0.08f, rand() % 50 + 25416.0f, 564.0f));

	std::vector<Platform> platforms;

	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(500.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 23.0f), sf::Vector2f(715.0f, 505.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(275.0f, 37.0f), sf::Vector2f(991.0f, 380.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(186.0f, 109.0f), sf::Vector2f(1800.0f, 602.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(326.0f, 109.0f), sf::Vector2f(2325.0f, 602.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(275.0f, 37.0f), sf::Vector2f(2915.0f, 555.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 23.0f), sf::Vector2f(3236.0f, 408.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(92.0f, 110.0f), sf::Vector2f(3473.0f, 601.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(92.0f, 180.0f), sf::Vector2f(3565.0f, 565.0f)));
	//platforms.push_back(Platform(&Gress, sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(2500.0f, 800.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1172.0f, 64.0f), sf::Vector2f(586.0f, 688.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1878.0f, 64.0f), sf::Vector2f(2250.0f, 688.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1670.0f, 64.0f), sf::Vector2f(4165.0f, 688.0f)));
	//platforms.push_back(Platform(&Gress, sf::Vector2f(2500.0f, 200.0f), sf::Vector2f(2500.0f, 800.0f)));
	//platforms.push_back(Platform(&Din, sf::Vector2f(500.0f, 1000.0f), sf::Vector2f(-200.0f, 360.0f)));

	int score = 0;

	sf::Font font;
	font.loadFromFile("p/kenvector_future.ttf");
	std::ostringstream scoreText;
	sf::Text Score;
	Score.setCharacterSize(60);
	Score.setString(scoreText.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::Red);

	int count,Bul=0;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {

		count = player.GetPosition().x;

		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';

		//std::cout << deltaTime;

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

	Score.setPosition({ view.getCenter().x - 200 ,100 });
	//if (pos.x > 5000) {
	//	Score.setPosition(player.GetPosition().x - 110, 50);
	//}

	scoreText.str(" ");
	scoreText << "SCORE: " << score;
	Score.setString(scoreText.str());

	sf::Vector2f direction;
	Collision playerCollision = player.GetCollider();

	//for (int i = 0; i < platforms.size(); i++) {
	//	Platform& platform = platforms[i];
	//}

	for (Platform& platform : platforms)
		if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);

	window.clear();
	//window.clear(sf::Color(221, 248, 255));

	for (Platform& platform : platforms)
		platform.Draw(window);
	window.draw(background);

	for (int i = 0; i < itemVector.size(); i++)
	{
		itemVector[i].draw(window);
	}

	for (int i = 0; i < itemVector.size(); i++)
	{
		itemVector[i].update(deltaTime, player);
	}
	for (int i = 0; i < itemVector.size(); i++)
	{
		if (itemVector[i].getpoint() == 1) {
			score += 100;
		}
	}

	if (player.GetPosition().x < 2107 && player.GetPosition().x > 1948 && player.GetPosition().y == 588.5)
	{  
		

		score -= 10;
	}







	for (int i = 0; i < SnailVector.size(); i++) {
		SnailVector[i].draw(window);
	}
	// Alien
	for (int i = 0; i < SnailVector.size(); i++) {
		//SnailVector[i].update1(deltaTime, bullet1);
		SnailVector[i].update2(deltaTime, player);
	}

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

	//view.setCenter(player.GetPosition());
	window.setView(view);
	//bullet1.draw(window);
	player.Draw(window);
	window.draw(Score);

	//platform2.Draw(window);
	//window.draw(player);
	window.display();
	}
	return 0;
}