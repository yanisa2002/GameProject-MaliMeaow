#include "Item.h"
#include<iostream>
Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    countpoint = 0;
    collide = 0;
    row = 0;
    body.setSize(sf::Vector2f(40.0f, 49.0f));
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
    animation.updateItem(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider())) {
        countpoint += 100;
        body.setPosition(-100, 80);
    }
}

void Item::draw(sf::RenderWindow& window)
{
    window.draw(body);
}