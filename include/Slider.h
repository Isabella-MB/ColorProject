#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Control.h"
#include "DebugLogger.h"

class Slider : public Control
{
public:
    Slider(float width, float height, sf::Vector2f position, sf::Color color);
    ~Slider() = default;

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

private:
    bool m_horizontal = true;
    bool m_dragging = false;

    float m_min = 0.0f;
    float m_max = 1.0f;

    sf::RectangleShape m_handle;
    sf::RectangleShape m_slider;
};