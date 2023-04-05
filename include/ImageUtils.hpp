#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.hpp"

namespace ImageUtils
{
    sf::Color lerp(sf::Color start_color, sf::Color end_color, float t);
    sf::Image createGradientImage(int width, int height, sf::Color start_color, sf::Color end_color);
}