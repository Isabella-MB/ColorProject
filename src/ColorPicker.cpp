#include "ColorPicker.h"

ColorPicker::ColorPicker(float width, float height, sf::Vector2f position, sf::Color color):
    Control(width, height, position, color)
{
    m_colorPicker.setSize(sf::Vector2f(m_width, m_height));
    m_colorPicker.setPosition(m_position);
    m_colorPicker.setFillColor(m_color);

    m_redSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height), sf::Color::Red);
    m_greenSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height / 4), sf::Color::Green);
    m_blueSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height / 2), sf::Color::Blue);
    m_alphaSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height * 3 / 4), sf::Color::White);
}

ColorPicker::~ColorPicker()
{
    delete m_redSlider;
    delete m_greenSlider;
    delete m_blueSlider;
    delete m_alphaSlider;
}

void ColorPicker::handleEvent(const sf::Event& event)
{
    m_redSlider->handleEvent(event);
    m_greenSlider->handleEvent(event);
    m_blueSlider->handleEvent(event);
    m_alphaSlider->handleEvent(event);
}

void ColorPicker::draw(sf::RenderWindow& window)
{
    window.draw(m_colorPicker);
    m_redSlider->draw(window);
    m_greenSlider->draw(window);
    m_blueSlider->draw(window);
    m_alphaSlider->draw(window);
}
