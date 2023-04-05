#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <sstream>
#include <iomanip>
#include "DebugLogger.hpp"
#include "Slider.hpp"
#include "ColorSwatch.hpp"
#include "Theme.hpp"
#include "Label.hpp"
#include "Spectrum.hpp"

/// @brief A color picker control that can be used to select a color
class ColorPicker : public Control
{
public:
    ColorPicker(float width, float height, sf::Vector2f position, sf::Color color);
    ~ColorPicker();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);
    void updateSliders(sf::Color color);
    void updateLabels();

protected:
    sf::RectangleShape m_colorPicker;

    Spectrum* m_spectrum;

    ColorSwatch* m_primarySwatch;
    ColorSwatch* m_secondarySwatch;

    Label* m_primarySwatchLabel;
    Label* m_secondarySwatchLabel;

    Slider* m_redSlider;
    Slider* m_greenSlider;
    Slider* m_blueSlider;
    Slider* m_alphaSlider;
};