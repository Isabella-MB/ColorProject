#include "ColorSwatch.h"

ColorSwatch::ColorSwatch(float width, float height, sf::Vector2f position, sf::Color color)
: Control(width, height, position, color)
{
    m_swatch.setSize(sf::Vector2f(width, height));
    m_swatch.setPosition(position);
    m_swatch.setFillColor(m_color);

    m_button = new Button(width, height, position, m_color);
}

ColorSwatch::~ColorSwatch()
{
    delete m_button;
}

void ColorSwatch::handleEvent(const sf::Event& event)
{
    m_button->handleEvent(event);
}

void ColorSwatch::draw(sf::RenderWindow& window)
{
    window.draw(m_swatch);
    m_button->draw(window);
}