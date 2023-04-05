#include "Spectrum.hpp"

Spectrum::Spectrum(float width, float height, sf::Vector2f position, sf::Color color)
: Control(width, height, position)
{
    m_color = color;
    m_swatch.setRadius(width / 2);
    m_swatch.setPosition(position);
    // m_swatch.setTexture(&m_texture);
    m_swatch.setOutlineColor(sf::Color::Black);
    m_swatch.setOutlineThickness(1);

    m_handle.setRadius(10);
    m_handle.setFillColor(sf::Color::Black);
    m_handle.setOrigin(m_handle.getRadius(), m_handle.getRadius());
    m_handle.setPosition(position.x + width / 2, position.y + height / 2);
}

Spectrum::~Spectrum()
{
}

void Spectrum::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed &&
        m_swatch.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        m_dragging = true;
        m_handle.setPosition(event.mouseButton.x, event.mouseButton.y);
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
        m_dragging = false;
    }
    else if (event.type == sf::Event::MouseMoved && m_dragging)
    {
        m_handle.setPosition(event.mouseMove.x, event.mouseMove.y);
    }
}

void Spectrum::draw(sf::RenderWindow& window)
{
    window.draw(m_swatch);
    window.draw(m_handle);
}