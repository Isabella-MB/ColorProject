#include "ImageUtils.hpp"

sf::Color ImageUtils::lerp(sf::Color start_color, sf::Color end_color, float t)
{
    sf::Color color;
    color.r = start_color.r + (end_color.r - start_color.r) * t;
    color.g = start_color.g + (end_color.g - start_color.g) * t;
    color.b = start_color.b + (end_color.b - start_color.b) * t;
    color.a = start_color.a + (end_color.a - start_color.a) * t;
    return color;
}

sf::Image ImageUtils::createGradientImage(int width, int height, sf::Color start_color, sf::Color end_color)
{
    sf::Image image;
    image.create(width, height, sf::Color::Transparent);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float t = (float)x / width;
            sf::Color color = lerp(start_color, end_color, t);
            image.setPixel(x, y, color);
        }
    }

    return image;
}