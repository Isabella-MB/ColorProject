#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Button.hpp"
#include "DebugLogger.hpp"

/// @brief A color swatch that represents a color in a color picker
class ColorSwatch : public Control
{
public:
    ColorSwatch(float width, float height, sf::Vector2f position, sf::Color color);
    ~ColorSwatch();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    void setColor(sf::Color color) { m_color = color; m_swatch.setFillColor(m_color); }
    sf::Color getColor() const { return m_color; }

private:
    sf::Color m_color;
    sf::RectangleShape m_swatch;
};