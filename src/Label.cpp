#include "Label.hpp"

Label::Label(float width, float height, sf::Vector2f position, sf::Color color, std::string text, sf::Font& font, unsigned int fontSize)
: Control(width, height, position), m_font(font)
{
    m_color = color;
    m_background.setSize(sf::Vector2f(width, height));
    m_background.setPosition(position);
    m_background.setFillColor(m_color);

    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(fontSize);
    m_text.setFillColor(sf::Color::Black);
    m_text.setPosition(position);
}

Label::~Label()
{
}

void Label::handleEvent(const sf::Event& event)
{
}

void Label::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
    window.draw(m_text);
}