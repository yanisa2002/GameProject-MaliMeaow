#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include "Platform2.h"
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

	//HP
	float playerHP = 80000;
	sf::RectangleShape HP(sf::Vector2f(playerHP / 250.0f, 30));
	HP.setPosition(sf:: Vector2f(450, 46));
	HP.setFillColor(sf::Color::Red);
	HP.setSize(sf::Vector2f(playerHP / 320.f, 15));

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

	//BG2
	sf::RectangleShape background2(sf::Vector2f(5000.0f, 720.0f));
	background2.setPosition(10000.0f, 0.0f);
	sf::Texture space2;
	space2.loadFromFile("p/BG2.png");
	background2.setTexture(&space2);

	//Moving Platform 
	sf::Texture MovPlat;
	MovPlat.loadFromFile("p/gress.png");
	std::vector <Platform2> MovPlatVector;

	//Snail Enemy
	sf::Texture snail;
	snail.loadFromFile("p/snail.png");
	std::vector <Enemy> SnailVector;

	//Coin
	srand(time(NULL));
	sf::Texture ITEM;
	ITEM.loadFromFile("p/coin.png");
	std::vector <Item> itemVector;

	//Moving Platform
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 1510.0f, 305.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 2477.0f, 290.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 4050.0f, 350.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 10415.0f, 360.0f));

	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, (rand() % 1000 + 20), 560.0f));
	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, (rand() % 1000 + 20), 400.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 641.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 691.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 741.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 791.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 900.0f, 280.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 950.0f, 280.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1000.0f, 280.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1050.0f, 280.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2535.0f, 600.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2585.0f, 600.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2635.0f, 600.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2685.0f, 600.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2735.0f, 600.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 3170.0f, 265.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 3220.0f, 265.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 3270.0f, 265.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 3320.0f, 265.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 3566.0f, 430.0f));

	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1843.0f, 513.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1880.0f, 480.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1920.0f, 450.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1960.0f, 420.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2000.0f, 390.0f));

	//Snail
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 691.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 831.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 1520.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 2700.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 3650.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 4000.0f, 650.0f));
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
	platforms.push_back(Platform(nullptr, sf::Vector2f(275.0f, 37.0f), sf::Vector2f(991.0f, 340.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(186.0f, 109.0f), sf::Vector2f(1800.0f, 602.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(326.0f, 109.0f), sf::Vector2f(2325.0f, 602.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(275.0f, 37.0f), sf::Vector2f(2915.0f, 514.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 23.0f), sf::Vector2f(3236.0f, 332.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(92.0f, 110.0f), sf::Vector2f(3473.0f, 601.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(92.0f, 180.0f), sf::Vector2f(3565.0f, 565.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 33.0f), sf::Vector2f(1242.0f, 672.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(159.0f, 33.0f), sf::Vector2f(2023.0f, 584.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 33.0f), sf::Vector2f(3261.0f, 672.0f)));
	//platforms.push_back(Platform(&Gress, sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(2500.0f, 800.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1172.0f, 64.0f), sf::Vector2f(586.0f, 688.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1878.0f, 64.0f), sf::Vector2f(2250.0f, 688.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1670.0f, 64.0f), sf::Vector2f(4165.0f, 688.0f)));
	//platforms.push_back(Platform(&Gress, sf::Vector2f(2500.0f, 200.0f), sf::Vector2f(2500.0f, 800.0f)));
	//platforms.push_back(Platform(&Din, sf::Vector2f(500.0f, 1000.0f), sf::Vector2f(-200.0f, 360.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(275.0f, 37.0f), sf::Vector2f(10734.0f, 461.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(210.0f, 37.0f), sf::Vector2f(11065.0f, 303.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(207.0f, 138.0f), sf::Vector2f(11170.0f, 583.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(280.0f, 23.0f), sf::Vector2f(11605.0f, 426.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(11430.0f, 403.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(11780.0f, 403.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(280.0f, 23.0f), sf::Vector2f(12411.0f, 371.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(12249.0f, 348.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(12577.0f, 348.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(11948.0f, 618.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(136.0f, 138.0f), sf::Vector2f(12053.0f, 583.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(210.0f, 37.0f), sf::Vector2f(12844.0f, 500.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(5000.0f, 64.0f), sf::Vector2f(12500.0f, 688.0f)));

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
		
	
	/*if (view.getCenter().x + 540.0f >= 5000.0f)
	{
		view.setCenter(4460.0f, 360.0f);
	}
	*/
	player.Update(deltaTime);

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

	for (int i = 0; i < SnailVector.size(); i++){
		
		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(SnailVector[i].GetCollider(), direction, 1.0f))
				SnailVector[i].OnCollision(direction,deltaTime);
	}
	
	for (int i = 0; i < SnailVector.size(); i++) {

		for (Platform2& platform2 : MovPlatVector)
			if (platform2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);
	}
	window.clear();
	//window.clear(sf::Color(221, 248, 255));
	
	//window.draw(background2);
	for (Platform& platform : platforms)
		platform.Draw(window);
	window.draw(background);
	window.draw(background2);

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
	//platform.GetCollider().CheckCollision(player.GetCollider()
	for (int i = 0; i < SnailVector.size(); i++) {
		if (SnailVector[i].GetCollider().CheckCollision(player.GetCollider())) {

			//std::cout << "............................";
			playerHP -= 50;
			HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
			if (playerHP < 0) {

				playerHP = 0;

			}

		}
	}


	if (player.GetPosition().x < 2107 && player.GetPosition().x > 1948 && player.GetPosition().y == 500)
	{  
		playerHP -= 100;
		HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
		if (playerHP < 0) {

			playerHP = 0;

		}
	}

	if (player.GetPosition().x < 3330 && player.GetPosition().x > 3183 && player.GetPosition().y == 588)
	{
		playerHP -= 100;
		HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
		if (playerHP < 0) {

			playerHP = 0;

		}
	}

	if (player.GetPosition().x < 1311 && player.GetPosition().x > 1170 && player.GetPosition().y == 588)
	{
		playerHP -= 100;
		HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
		if (playerHP < 0) {
		
			playerHP = 0;
		  
		}
	}
	
	for (int i = 0; i < MovPlatVector.size(); i++) {
		MovPlatVector[i].draw(window);
	}
	
	for (int i = 0; i < MovPlatVector.size(); i++) {
		MovPlatVector[i].updateY(deltaTime);
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

	view.setCenter(player.GetPosition().x, 360.0f);

	if (view.getCenter().x - 540.0f <= 0.0f)
	{
		view.setCenter(540.0f, 360.0f);
	}
	/*if (view.getCenter().x + 540.0f >= 5000.0f)
	{
		view.setCenter(4460.0f, 360.0f);
	}*/
	if (player.GetPosition().x >= 10000) {
		if (view.getCenter().x - 540.0f <= 10000.0f) {
			view.setCenter(10540.0f, 360.0f);
		}
	}
	if (view.getCenter().x + 540.0f >= 15000.0f) {
		view.setCenter(14460.0f, 360.0f);
	}



	Score.setPosition({ view.getCenter().x - 200 ,60 });

	HP.setPosition({ view.getCenter().x - 200 ,20 });

	//platform1.GetCollider().CheckCollision(player.GetCollider(), 0.5f);
	//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

	//view.setCenter(player.GetPosition());
	window.setView(view);
	//bullet1.draw(window);
	player.Draw(window);
	window.draw(Score);
	window.draw(HP);
	//platform2.Draw(window);
	//window.draw(player);
	window.display();
	}
	return 0;
}