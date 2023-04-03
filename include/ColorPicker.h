#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.h"
#include "Slider.h"
#include "ColorSwatch.h"

class ColorPicker : public Control
{
public:
    ColorPicker(float width, float height, sf::Vector2f position, sf::Color color);
    ~ColorPicker();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

protected:
    sf::Color m_primaryColor;
    sf::Color m_secondaryColor;
    sf::RectangleShape m_colorPicker;

    ColorSwatch* m_primarySwatch;
    ColorSwatch* m_secondarySwatch;

    Slider* m_redSlider;
    Slider* m_greenSlider;
    Slider* m_blueSlider;
    Slider* m_alphaSlider;
};