#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.hpp"

class Control
{
public:
    Control(float width, float height, sf::Vector2f position)
    : m_width(width)
    , m_height(height)
    , m_position(position)
    {
    }
    virtual ~Control() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    float m_width;
    float m_height;
    sf::Vector2f m_position;
};