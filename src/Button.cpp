// Button.cpp
#include "Button.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "DebugLogger.h"

Button::Button(float width, float height, sf::Vector2f position, sf::Color color)
: Control(width, height, position), m_color(color)
{
    // Set the button properties
    m_button.setSize(sf::Vector2f(width, height));
    m_button.setPosition(position);
    m_button.setFillColor(color);
}

void Button::handleEvent(const sf::Event &event)
{
    // Check if the button was clicked
    if (event.type == sf::Event::MouseButtonPressed &&
        m_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        // The button was clicked, do something here
        DebugLogger::getInstance().log("button was pressed");
    }
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(m_button);
}