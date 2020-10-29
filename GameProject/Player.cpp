#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	canJump = true;
	faceRight = true;
	bullet = false;

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setPosition(540.0f, 360.0f);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime) 
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed * 2.0f ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed * 2.0f ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		bullet = true;
		//velocity.y += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump==true)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 1500.0f * jumpHeight);
	}

	velocity.y += 1500.0f * deltaTime;

	if (velocity.x == 0)
	{
		row = 0;
	}
	else
	{
		if (velocity.x > 0.0f)
		{
			row = 3;
			faceRight = true;
		}
		if (velocity.x < 0)
		{
			row = 2;
			faceRight = false;
		}
	}

	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window) 
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f) {

		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {

		velocity.y = 0.0f;

	}
}
