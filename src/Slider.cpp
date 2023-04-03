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

    m_handle.setSize(sf::Vector2f(m_width / 10, m_height));
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
    // TODO: Account for the extents of the slider handle rect
    if (m_dragging && event.type == sf::Event::MouseMoved)
    {
        float x = event.mouseMove.x;
        float extent = m_handle.getSize().x / 2;
        if (x < m_position.x - extent)
        {
            x = m_position.x - extent;
        }
        else if (x > m_position.x + m_width - extent)
        {
            x = m_position.x + m_width - extent;
        }
        m_handle.setPosition(x, m_position.y);
    }
}

void Slider::draw(sf::RenderWindow& window)
{
    window.draw(m_slider);
    window.draw(m_handle);
}