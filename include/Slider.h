#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Control.h"
#include "DebugLogger.h"

class Slider : public Control
{
public:
    Slider(float width, float height, sf::Vector2f position, sf::Color start_color, sf::Color end_color);
    ~Slider() = default;

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    void updateHandlePosition();
    void setValue(const sf::Uint8 value) { 
        m_value = value; updateHandlePosition(); }
    float getValue() const { return m_value; }

    bool isDragging() const { return m_dragging; }
    
private:
    bool m_horizontal = true;
    bool m_dragging = false;

    sf::Uint8 m_value = 0;

    sf::RectangleShape m_handle;
    sf::RectangleShape m_slider;
};