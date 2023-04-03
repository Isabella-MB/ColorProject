#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.h"

class ColorPicker
{
public:
    ColorPicker(float width, float height, sf::Vector2f position, sf::Color color);

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void updateColor() = 0;

protected:
    float m_width;
    float m_height;
    sf::Vector2f m_position;
    sf::Color m_color;
    sf::RectangleShape m_colorPicker;
};

ColorPicker::ColorPicker(float width, float height, sf::Vector2f position, sf::Color color)
    : m_width(width)
    , m_height(height)
    , m_position(position)
    , m_color(color)
{
    m_colorPicker.setSize(sf::Vector2f(m_width, m_height));
    m_colorPicker.setPosition(m_position);
    m_colorPicker.setFillColor(m_color);
}