#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	//MENU
	sf::RectangleShape MENU(sf::Vector2f(1080.0f, 720.0f));
	MENU.setPosition(0.0f, 0.0f);
	sf::Texture menu1;
	menu1.loadFromFile("p/MENUbg.png");
	MENU.setTexture(&menu1);

	//MENUnomal
	sf::RectangleShape mainMENU(sf::Vector2f(1080.0f, 720.0f));
	mainMENU.setPosition(0.0f, 0.0f);
	sf::Texture menu2;
	menu2.loadFromFile("p/MENU.png");
	mainMENU.setTexture(&menu2);

	//MENUplay
	sf::RectangleShape playMENU(sf::Vector2f(1080.0f, 720.0f));
	playMENU.setPosition(0.0f, 0.0f);
	sf::Texture menu3;
	menu3.loadFromFile("p/play.png");
	playMENU.setTexture(&menu3);

	//MENUscore
	sf::RectangleShape scoreMENU(sf::Vector2f(1080.0f, 720.0f));
	scoreMENU.setPosition(0.0f, 0.0f);
	sf::Texture menu4;
	menu4.loadFromFile("p/highscore.png");
	scoreMENU.setTexture(&menu4);

	//MENUexit
	sf::RectangleShape exitMENU(sf::Vector2f(1080.0f, 720.0f));
	exitMENU.setPosition(0.0f, 0.0f);
	sf::Texture menu5;
	menu5.loadFromFile("p/exit.png");
	exitMENU.setTexture(&menu5);

	//Menu-pause
	sf::RectangleShape pauseGame(sf::Vector2f(1080.0f, 720.0f));
	pauseGame.setPosition(0.0f, 0.0f);
	sf::Texture pause_game;
	pause_game.loadFromFile("p/pauseN.png");
	pauseGame.setTexture(&pause_game);

	//Menu-pause normal
	sf::RectangleShape pauseBGame(sf::Vector2f(1080.0f, 720.0f));
	pauseBGame.setPosition(0.0f, 0.0f);
	sf::Texture pauseB_game;
	pauseB_game.loadFromFile("p/pause.png");
	pauseBGame.setTexture(&pauseB_game);


	//Menu-pause resume
	sf::RectangleShape pauseResumeGame(sf::Vector2f(1080.0f, 720.0f));
	pauseResumeGame.setPosition(0.0f, 0.0f);
	sf::Texture resume_game;
	resume_game.loadFromFile("p/pause_resume.png");
	pauseResumeGame.setTexture(&resume_game);

	//Menu-pause exit to menu
	sf::RectangleShape pauseExitGame(sf::Vector2f(1080.0f, 720.0f));
	pauseExitGame.setPosition(0.0f, 0.0f);
	sf::Texture pauseExit_game;
	pauseExit_game.loadFromFile("p/pause_exit.png");
	pauseExitGame.setTexture(&pauseExit_game);

	//Moving Platform 
	sf::Texture MovPlat;
	MovPlat.loadFromFile("p/bridgeLogs.png");
	std::vector <Platform2> MovPlatVector;

	//Snail Enemy
	sf::Texture snail;
	snail.loadFromFile("p/snail.png");
	std::vector <Enemy> SnailVector;

	//Snail Enemy moving
	sf::Texture snailMov;
	snailMov.loadFromFile("p/snail.png");
	std::vector <Enemy> SnailMovVector;

	//addHP
	//srand(time(NULL));
	sf::Texture LUCK;
	LUCK.loadFromFile("p/luck.png");
	std::vector <Item> luckVector;

	//Coin
	srand(time(NULL));
	sf::Texture ITEM;
	ITEM.loadFromFile("p/coin.png");
	std::vector <Item> itemVector;

	//score endgame
	sf::RectangleShape scoreEndGame(sf::Vector2f(1080.0f, 720.0f));
	scoreEndGame.setPosition(0.0f, 0.0f);
	sf::Texture score_game;
	score_game.loadFromFile("p/score.png");
	scoreEndGame.setTexture(&score_game);

	//-----------------------------------------MUSIC SOUND-----------------------------------------//
	//soundmenu
	sf::Music music;
	music.openFromFile("p/Swinging Pants.ogg");
	music.setLoop(true);
	music.setVolume(20.f);

	//soundclick
	sf::SoundBuffer soundc;
	soundc.loadFromFile("p/click.WAV");
	sf::Sound Soundch;
	Soundch.setBuffer(soundc);

	//sound cat attact
	sf::SoundBuffer soundcat;
	soundcat.loadFromFile("p/cat.WAV");
	sf::Sound Soundcat;
	Soundcat.setBuffer(soundcat);

	//Moving Platform
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 1510.0f, 305.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 2477.0f, 290.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 4050.0f, 350.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 10315.0f, 360.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 13502.0f, 300.0f));
	MovPlatVector.push_back(Platform2(&MovPlat, sf::Vector2u(1, 1), 0.08f, 14200.0f, 310.0f));

	//itemVector.push_back(Item(&ITEM, sf::Vector2u(8, 1), 0.08f, (rand() % 1000 + 20), 560.0f));
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

	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 10828.0f, 401.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 10863.0f, 351.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 10911.0f, 301.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 10940.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11130.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11248.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11312.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 12140.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 12211.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 12375.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 12440.0f, 239.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 12515.0f, 239.0f));

	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1843.0f, 513.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1880.0f, 480.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1920.0f, 450.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 1960.0f, 420.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 2000.0f, 390.0f));

	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11534.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11628.0f, 500.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11691.0f, 500.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 11793.0f, 560.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 13378.0f, 210.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 13495.0f, 210.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 13605.0f, 210.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 13712.0f, 210.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(10, 1), 0.08f, 13809.0f, 210.0f));

	//addHP
	luckVector.push_back(Item(&LUCK, sf::Vector2u(1, 1), 0.08f, 2461.0f, 200.0f));
	luckVector.push_back(Item(&LUCK, sf::Vector2u(1, 1), 0.08f, 4032.0f, 250.0f));
	luckVector.push_back(Item(&LUCK, sf::Vector2u(1, 1), 0.08f, 12841.0f, 200.0f));

	//Snail Moving
	SnailMovVector.push_back(Enemy(&snailMov, sf::Vector2u(2, 1), 0.08f, 11505.0f, 370.0f));
	SnailMovVector.push_back(Enemy(&snailMov, sf::Vector2u(2, 1), 0.08f, 12325.0f, 320.0f));
	SnailMovVector.push_back(Enemy(&snailMov, sf::Vector2u(2, 1), 0.08f, 11310.0f, 605.0f));
	SnailMovVector.push_back(Enemy(&snailMov, sf::Vector2u(2, 1), 0.08f, 12325.0f, 605.0f));

	//Snail
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, (rand() % 1000 + 20), 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, (rand() % 1000 + 20), 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 1520.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 2700.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 3650.0f, 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 4000.0f, 650.0f));

	//SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, 11587.0f, 376.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, (rand() % 1000 + 12000), 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, (rand() % 1000 + 12000), 650.0f));
	SnailVector.push_back(Enemy(&snail, sf::Vector2u(2, 1), 0.08f, (rand() % 1000 + 13000), 650.0f));
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
	platforms.push_back(Platform(nullptr, sf::Vector2f(280.0f, 23.0f), sf::Vector2f(12431.0f, 371.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(12269.0f, 348.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(12597.0f, 348.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 70.0f), sf::Vector2f(11948.0f, 618.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(136.0f, 138.0f), sf::Vector2f(12053.0f, 583.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(210.0f, 37.0f), sf::Vector2f(12870.0f, 500.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(210.0f, 37.0f), sf::Vector2f(13176.0f, 333.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(210.0f, 270.0f), sf::Vector2f(13888.0f, 517.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(5000.0f, 64.0f), sf::Vector2f(12500.0f, 688.0f)));

	int score = 0;
	int q = 0;
	bool checkHP = false;
	bool checkDraw = false;
	bool checkColi = false;
	bool pause = false;
	bool menu = true;
	bool start = false;

	sf::Font font;
	font.loadFromFile("p/kenvector_future.ttf");
	std::ostringstream scoreText;
	sf::Text Score;
	Score.setCharacterSize(60);
	Score.setString(scoreText.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::Red);

	///Score when end////
	sf::Font font1;
	font1.loadFromFile("p/kenvector_future.ttf");
	ostringstream point1;
	sf::Text coinScore;
	coinScore.setCharacterSize(50);
	coinScore.setString(point1.str());
	coinScore.setFont(font1);
	coinScore.setFillColor(sf::Color::White);

	///coin Score
	sf::Font font2;
	font2.loadFromFile("p/kenvector_future.ttf");
	ostringstream point2;
	sf::Text LastScore;
	LastScore.setCharacterSize(70);
	LastScore.setString(point2.str());
	LastScore.setFont(font2);
	LastScore.setFillColor(sf::Color::White);

	int count, Bul = 0;
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock timercoli;

	while (window.isOpen()) {
		music.play();
		while (menu == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;

			deltaTime = clock.restart().asSeconds();
			//if (cheakhighscore == false) {
				window.draw(MENU);
				window.draw(mainMENU);
			//}
			if (sf::Mouse::getPosition(window).x >= 717 &&
				sf::Mouse::getPosition(window).y >= 243 &&
				sf::Mouse::getPosition(window).x <= 1011 &&
				sf::Mouse::getPosition(window).y <= 325)
			{
				window.draw(playMENU);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					menu = false;
					start = true;
					//MemScore = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 717 &&
				sf::Mouse::getPosition(window).y >= 399 &&
				sf::Mouse::getPosition(window).x <= 1011 &&
				sf::Mouse::getPosition(window).y <= 480)
			{
				window.draw(scoreMENU);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//Soundch.play();
					//MENU = false;
					//START = false;
					//Rank = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 717 &&
				sf::Mouse::getPosition(window).y >= 553 &&
				sf::Mouse::getPosition(window).x <= 1011 &&
				sf::Mouse::getPosition(window).y <= 637)
			{
				window.draw(exitMENU);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					window.close();
					break;
				}
			}
			window.display();
		}

		while (start == true) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				pause = true;
			}

			count = player.GetPosition().x;

			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';

			//std::cout << deltaTime;

			/*deltaTime = clock.restart().asSeconds();
			if (deltaTime > 1.0f / 20.0f)
				deltaTime = 1.0f / 20.0f;
	*/
			


			/*if (view.getCenter().x + 540.0f >= 5000.0f)
			{
				view.setCenter(4460.0f, 360.0f);
			}
			*/
			

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

			for (int i = 0; i < SnailVector.size(); i++) {

				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(SnailVector[i].GetCollider(), direction, 1.0f))
						SnailVector[i].OnCollision(direction, deltaTime);
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
				if (itemVector[i].getpoint() == 1) {
					score += 100;


				}
			}
			//platform.GetCollider().CheckCollision(player.GetCollider()
			for (int i = 0; i < SnailVector.size(); i++) {
				if (SnailVector[i].GetCollider().CheckCollision(player.GetCollider())) {
					Soundcat.play();
					//std::cout << "............................";
					playerHP -= 50;
					HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
					checkColi = true;
					q = 0;
					if (playerHP < 0) {
						playerHP = 0;
						checkHP = true;
					}
				}
			}

			for (int i = 0; i < SnailMovVector.size(); i++) {
				if (SnailMovVector[i].GetCollider().CheckCollision(player.GetCollider())) {
					Soundcat.play();
					//std::cout << "............................";
					playerHP -= 50;
					HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
					checkColi = true;
					q = 0;
					if (playerHP < 0) {
						playerHP = 0;
						checkHP = true;
					}
				}
			}

			if (checkHP == false && pause == false) {
				for (int i = 0; i < itemVector.size(); i++)
				{
					itemVector[i].update(deltaTime, player);
				}

				// Alien
				for (int i = 0; i < SnailVector.size(); i++) {
					//SnailVector[i].update1(deltaTime, bullet1);
					SnailVector[i].update2(deltaTime, player);
				}

				for (int i = 0; i < MovPlatVector.size(); i++) {
					MovPlatVector[i].updateY(deltaTime);
				}

				for (int i = 0; i < SnailMovVector.size(); i++) {
					SnailMovVector[i].updateX(deltaTime);
				}

				player.Update(deltaTime);
			}

			for (int i = 0; i < luckVector.size(); i++) {
				if (luckVector[i].GetCollider().CheckCollision(player.GetCollider())) {

					//std::cout << "............................";
					playerHP += 4000;
					HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
					if (playerHP > 80000) {

						playerHP = 80000;
						HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
					}
					luckVector.erase(luckVector.begin() + i);
				}
			}

			// check nharm
			if (player.GetPosition().x < 2107 && player.GetPosition().x > 1948 && player.GetPosition().y >= 500 && player.GetPosition().y <= 502)
			{
				Soundcat.play();
				playerHP -= 100;
				HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
				checkColi = true;
				q = 0;
				if (playerHP < 0) {

					playerHP = 0;
					checkHP = true;
				}
			}

			if (player.GetPosition().x < 3330 && player.GetPosition().x > 3183 && player.GetPosition().y == 588)
			{
				Soundcat.play();
				playerHP -= 100;
				HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
				checkColi = true;
				q = 0;
				if (playerHP < 0) {

					playerHP = 0;
					checkHP = true;
				}
			}

			if (player.GetPosition().x < 1311 && player.GetPosition().x > 1170 && player.GetPosition().y == 588)
			{
				Soundcat.play();
				playerHP -= 100;
				HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
				checkColi = true;
				q = 0;
				if (playerHP < 0) {

					playerHP = 0;
					checkHP = true;
				}
			}

			if (player.GetPosition().x < 10806 && player.GetPosition().x > 10665 && player.GetPosition().y >= 530 && player.GetPosition().y <= 547)
			{
				Soundcat.play();
				playerHP -= 500;
				HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
				checkColi = true;
				q = 0;
				if (playerHP < 0) {

					playerHP = 0;
					checkHP = true;
				}
			}

			if (player.GetPosition().x < 11096 && player.GetPosition().x > 11029 && player.GetPosition().y < 400 && player.GetPosition().y > 395)
			{
				Soundcat.play();
				playerHP -= 500;
				HP.setSize(sf::Vector2f(playerHP / 320.f, 15));
				checkColi = true;
				q = 0;
				if (playerHP < 0) {

					playerHP = 0;
					checkHP = true;
				}
			}

			for (int i = 0; i < MovPlatVector.size(); i++) {
				MovPlatVector[i].draw(window);
			}

			for (int i = 0; i < SnailMovVector.size(); i++) {
				SnailMovVector[i].draw(window);
			}

			for (int i = 0; i < SnailVector.size(); i++) {
				SnailVector[i].draw(window);
			}

			for (int i = 0; i < luckVector.size(); i++) {
				luckVector[i].draw(window);
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

			coinScore.setPosition({ view.getCenter().x - 20 ,view.getCenter().y - 200 });
			LastScore.setPosition({ view.getCenter().x - 100 ,view.getCenter().y - 15 });

			if (checkColi == true) {
				if (q < 10) {
					if (q % 2 == 0 && timercoli.getElapsedTime().asSeconds() >= 0.05) {
						checkDraw = true;
						q++;
						timercoli.restart();
					}
					else if (q % 2 != 0 && timercoli.getElapsedTime().asSeconds() >= 0.05) {
						checkDraw = false;
						q++;
						timercoli.restart();
					}
					if (q == 10) {
						checkColi = false;
					}
				}
			}
			if (checkDraw == false) {
				player.Draw(window);
			}
			
			//platform1.GetCollider().CheckCollision(player.GetCollider(), 0.5f);
			//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

			//view.setCenter(player.GetPosition());
			window.setView(view);
			//bullet1.draw(window);
			//player.Draw(window);
			window.draw(Score);
			window.draw(HP);
			//platform2.Draw(window);
			//window.draw(player);
			if (pause == true) {
				pauseGame.setPosition(view.getCenter().x - 540, 0);
				pauseBGame.setPosition(view.getCenter().x - 540, 0);
				window.draw(pauseGame);
				window.draw(pauseBGame);

				if (sf::Mouse::getPosition(window).x >= 411 &&
					sf::Mouse::getPosition(window).y >= 250 &&
					sf::Mouse::getPosition(window).x <= 668 &&
					sf::Mouse::getPosition(window).y <= 336)
				{
					pauseResumeGame.setPosition(view.getCenter().x - 540, 0);
					window.draw(pauseResumeGame);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						pause = false;
						//menu = false;
						//start = true;
						//MemScore = true;
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 411 &&
					sf::Mouse::getPosition(window).y >= 418 &&
					sf::Mouse::getPosition(window).x <= 668 &&
					sf::Mouse::getPosition(window).y <= 504)
				{
					pauseExitGame.setPosition(view.getCenter().x - 540, 0);
					window.draw(pauseExitGame);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Soundch.play();
						start = false;
						menu = true;
						MENU.setPosition(view.getCenter().x - 540, 0.0f);
						mainMENU.setPosition(view.getCenter().x - 540, 0.0f);
						playMENU.setPosition(view.getCenter().x - 540, 0.0f);
						scoreMENU.setPosition(view.getCenter().x - 540, 0.0f);
						exitMENU.setPosition(view.getCenter().x - 540, 0.0f);
						//Rank = true;
					}
				}
			}

			if (checkHP == true) {
				//window.close();
				window.draw(scoreEndGame);
				scoreEndGame.setPosition(view.getCenter().x - 540, 0);
				point1.str(" ");
				point1 << "  " << score;
				coinScore.setString(point1.str());
				window.draw(coinScore);

				point2.str(" ");
				point2 << "  " << score;
				LastScore.setString(point2.str());
				window.draw(LastScore);
				std::cout << "............................";
				cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
				if (sf::Mouse::getPosition(window).x >= 411 &&
					sf::Mouse::getPosition(window).y >= 484 &&
					sf::Mouse::getPosition(window).x <= 669 &&
					sf::Mouse::getPosition(window).y <= 568)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						window.close();

					}
				}
			}
			window.display();
		}
			
		}
		return 0;
}