#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void setPosition(float x, float y);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollider() { return Collision(body); }


private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool bullet;
	bool slide;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

