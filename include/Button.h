#pragma once
#include <SFML/Graphics.hpp>
#include "DebugLogger.h"
#include "Control.h"

class Button : public Control
{
public:
	Button(float width, float height, sf::Vector2f position, sf::Color color);

	void handleEvent(const sf::Event &event);
	void draw(sf::RenderWindow &window);

private:
	sf::RectangleShape m_button;
	std::function<void()> m_callback;
};
