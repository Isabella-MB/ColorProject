#include "Slider.h"

Slider::Slider(float width, float height, sf::Vector2f position, sf::Color color)
    : m_width(width)
    , m_height(height)
    , m_position(position)
    , m_color(color)
{
    m_slider.setSize(sf::Vector2f(m_width, m_height));
    m_slider.setPosition(m_position);
    m_slider.setFillColor(m_color);
}

void Slider::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed &&
        m_slider.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        DebugLogger::getInstance().log("slider was pressed");
    }
    //handle mouse dragging
    if (event.type == sf::Event::MouseButtonReleased &&
        m_slider.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        DebugLogger::getInstance().log("slider was released");
    }
}

void Slider::draw(sf::RenderWindow& window)
{
    window.draw(m_slider);
}