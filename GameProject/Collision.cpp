#include "Collision.h"

Collision::Collision(sf::RectangleShape& body) :
    body(body)
{
}

Collision::~Collision()
{
}

bool Collision::CheckCollision(Collision other, sf::Vector2f& direction, float push)
{
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfsize = other.GetHalfsize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfsize = GetHalfsize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfsize.x + thisHalfsize.x);
    float intersectY = abs(deltaY) - (otherHalfsize.y + thisHalfsize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        push = std::min(std::max(push, 0.0f), 1.0f);
        if (intersectX > intersectY)
        {
            if (deltaX > 0.0f)
            {
                Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            }
            else
            {
                Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX * push, 0.0f);

                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f, -intersectY * push);

                direction.x = 0.0f;
                direction.y = 1.0f;
            }
            else
            {
                Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f, intersectY * push);

                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }

        return true;
    }

    return false;
}
