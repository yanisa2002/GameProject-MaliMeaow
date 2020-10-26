#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	Collision(sf::RectangleShape& body);
	~Collision();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collision other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfsize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};

