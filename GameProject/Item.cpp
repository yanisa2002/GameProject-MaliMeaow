#include "Item.h"
#include<iostream>
Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    Cstar = 0;
    collide = 0;
    row = 0;
    body.setSize(sf::Vector2f(35.0f, 44.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Item::~Item()
{
    //delete this;
}

void Item::update(float deltaTime, Player player)
{
    animation.updateItem(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider())) {
        Cstar++;
        body.setPosition(-100, 80);
        //delete this;
    }
}

void Item::draw(sf::RenderWindow& window)
{
    window.draw(body);
}