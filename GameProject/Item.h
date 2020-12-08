#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collision.h"

class Item
{
public:

    Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Item();
    void update(float deltaTime, Player player);
   
    void draw(sf::RenderWindow& window);
    Collision GetCollider() { return Collision(body); }

   int getpoint()
    {
        if (countpoint == 100) {
            countpoint-=100;
            return 1;
        }
    }


private:
    int row;
    int countpoint;
    int collide;
    bool faceRight;
    sf::RectangleShape body;
    Animation animation;
};