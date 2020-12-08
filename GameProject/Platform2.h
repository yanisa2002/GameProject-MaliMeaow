#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Collision.h"

class Platform2
{

public:
    Platform2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Platform2();
    void updateX(float deltaTime);
    void updateY(float deltaTime);
    void draw(sf::RenderWindow& window);
    void MOVE();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collision GetCollider() { return Collision(body); }





private:
    float posiX, posiY;
    int row;
    int counthit;
    int count = 100;
    bool hit;
    float speed;
    float direction;
    sf::RectangleShape body;
    sf::Vector2f velocity;
};
