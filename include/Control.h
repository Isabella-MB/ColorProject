#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.h"

class Control
{
public:
    virtual ~Control() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    float m_width;
    float m_height;
    sf::Vector2f m_position;
    sf::Color m_color;
    sf::RectangleShape m_control;
};