#pragma once
#include <SFML/Graphics.hpp>
#include "DebugLogger.h"
#include "Control.h"

/// @brief A button control that can be used to trigger an action
class Button : public Control
{
public:
	Button(float width, float height, sf::Vector2f position, sf::Color color);

	void handleEvent(const sf::Event &event);
	void draw(sf::RenderWindow &window);

private:

	sf::Color m_color;
	sf::RectangleShape m_button;
	std::function<void()> m_callback;
};
