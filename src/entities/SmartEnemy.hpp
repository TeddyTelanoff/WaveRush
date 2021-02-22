#pragma once

#include "Entity.hpp"

class SmartEnemy : public Entity
{
private:
    sf::Vector2f m_Position;
    sf::Vector2f m_Speed;
    sf::Vector2f m_Size;
    sf::RectangleShape m_Shape;

public:
    SmartEnemy();

    void ProcessUpdate(const double p_DeltaTime) override;

    void ProcessRender(sf::RenderWindow *p_Window) override;
};