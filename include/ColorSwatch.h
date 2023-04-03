#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "DebugLogger.h"

class ColorSwatch : public Control
{
public:
    ColorSwatch(float width, float height, sf::Vector2f position, sf::Color color);
    ~ColorSwatch();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);
    
    sf::Color getColor() const { return m_color; }

private:
    sf::RectangleShape m_swatch;
    Button* m_button;
};