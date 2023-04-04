#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.h"

/// @brief The root window control that contains all other controls

class Window : public Control
{
public:
    Window(float width, float height, sf::Vector2f position, sf::Color color);
    ~Window();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    void addControl(Control* control);

private:
    std::vector<Control*> m_controls;
};