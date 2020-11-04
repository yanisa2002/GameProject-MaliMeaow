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

   /* int iscollide()
    {
        if (Cstar == 1) {
            Cstar--;
            return 1;
        }
    }*/

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Cstar;
    int collide;
    bool faceRight;
    sf::RectangleShape body;
    Animation animation;
};