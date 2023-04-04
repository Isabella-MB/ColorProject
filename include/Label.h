#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "DebugLogger.h"


class Label : public Control
{
public:
    Label(float width, float height, sf::Vector2f position, sf::Color color, std::string text, sf::Font& font, unsigned int fontSize);
    ~Label();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    void setText(std::string text) { m_text.setString(text); }
    std::string getText() const { return m_text.getString(); }

private:
    sf::Color m_color;
    sf::RectangleShape m_background;
    sf::Font& m_font;
    sf::Text m_text;
};