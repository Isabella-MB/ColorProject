#include "ColorSwatch.h"

ColorSwatch::ColorSwatch(float width, float height, sf::Vector2f position, sf::Color color)
: Control(width, height, position)
{
    m_color = color;
    m_swatch.setSize(sf::Vector2f(width, height));
    m_swatch.setPosition(position);
    m_swatch.setFillColor(m_color);
}

ColorSwatch::~ColorSwatch()
{
}

void ColorSwatch::handleEvent(const sf::Event& event)
{
}

void ColorSwatch::draw(sf::RenderWindow& window)
{
    window.draw(m_swatch);
}