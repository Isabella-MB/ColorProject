#include "Slider.h"

Slider::Slider(float width, float height, sf::Vector2f position, sf::Color color) 
    : Control(width, height, position, color)
{
    m_slider.setSize(sf::Vector2f(m_width, m_height));
    m_slider.setPosition(m_position);
    m_slider.setFillColor(m_color);

    m_handle.setSize(sf::Vector2f(1, m_height));
    m_handle.setPosition(m_position);
    m_handle.setFillColor(sf::Color::White);
}

void Slider::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed &&
        m_slider.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        m_dragging = true;
        DebugLogger::getInstance().log("slider was pressed");
    }
    if (event.type == sf::Event::MouseButtonReleased && m_dragging)
    {
        m_dragging = false;
        DebugLogger::getInstance().log("slider was released");
    }
    if (m_dragging && event.type == sf::Event::MouseMoved)
    {
        float x = event.mouseMove.x;
        if (x < m_position.x)
        {
            x = m_position.x;
        }
        else if (x > m_position.x + m_width)
        {
            x = m_position.x + m_width;
        }
        m_handle.setPosition(x, m_position.y);
    }
}

void Slider::draw(sf::RenderWindow& window)
{
    window.draw(m_slider);
    window.draw(m_handle);
}