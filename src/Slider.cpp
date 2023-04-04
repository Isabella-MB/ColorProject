#include "Slider.h"

sf::Color lerp(sf::Color start_color, sf::Color end_color, float t)
{
    sf::Color color;
    color.r = start_color.r + (end_color.r - start_color.r) * t;
    color.g = start_color.g + (end_color.g - start_color.g) * t;
    color.b = start_color.b + (end_color.b - start_color.b) * t;
    color.a = start_color.a + (end_color.a - start_color.a) * t;
    return color;
}

sf::Image createGradientImage(int width, int height, sf::Color start_color, sf::Color end_color)
{
    sf::Image image;
    image.create(width, height, sf::Color::Transparent);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float t = (float)x / width;
            sf::Color color = lerp(start_color, end_color, t);
            image.setPixel(x, y, color);
        }
    }

    return image;
}

Slider::Slider(float width, float height, sf::Vector2f position, sf::Color start_color, sf::Color end_color) 
    : Control(width, height, position)
{
    m_slider.setSize(sf::Vector2f(m_width, m_height));
    m_slider.setPosition(m_position);
    
    auto image = createGradientImage(m_width, m_height, start_color, end_color);
    auto texture = new sf::Texture();
    texture->loadFromImage(image);
    m_slider.setTexture(texture);

    m_handle.setSize(sf::Vector2f(1, m_height));
    m_handle.setPosition(m_position);
    m_handle.setFillColor(sf::Color::White);
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
    window.draw(m_slider);
    window.draw(m_handle);
}