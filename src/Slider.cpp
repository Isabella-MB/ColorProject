#include "Slider.hpp"

Slider::Slider(float width, float height, sf::Vector2f position, sf::Color startColor, sf::Color endColor) 
    : Control(width, height, position)
{
    m_slider.setSize(sf::Vector2f(m_width, m_height));
    m_slider.setPosition(m_position);

    m_shader = new sf::Shader();
    m_shader->loadFromFile("shaders/gradient.frag", sf::Shader::Fragment);
    m_shader->loadFromFile("shaders/gradient.vert", sf::Shader::Vertex);

    m_handle.setSize(sf::Vector2f(1, m_height));
    m_handle.setPosition(m_position);
    m_handle.setFillColor(sf::Color::White);
}

Slider::~Slider()
{
    delete m_shader;
}

void Slider::updateHandlePosition()
{
    float x = m_position.x + m_width * m_value / 255;
    m_handle.setPosition(x, m_position.y);
}

void Slider::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed &&
        m_slider.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        m_dragging = true;
        int value = (int)((event.mouseButton.x - m_position.x) / m_width * 255);
        value = std::clamp(value, 0, 255);
        setValue(value);
        DebugLogger::getInstance().log("slider was pressed");
    }
    if (event.type == sf::Event::MouseButtonReleased && m_dragging)
    {
        m_dragging = false;
        DebugLogger::getInstance().log("slider was released");
    }
    if (m_dragging && event.type == sf::Event::MouseMoved)
    {
        int value = (int)((event.mouseMove.x - m_position.x) / m_width * 255);
        value = std::clamp(value, 0, 255);
        setValue(value);
    }
}

void Slider::draw(sf::RenderWindow& window)
{
    window.draw(m_slider, m_shader);
    window.draw(m_handle);
}