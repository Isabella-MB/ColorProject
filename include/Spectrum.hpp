#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DebugLogger.hpp"
#include "Control.hpp"
#include "ImageUtils.hpp"

/// @brief A circular color spectrum with three color poles, a handle can be dragged to change the color
class Spectrum : public Control
{
public:
    Spectrum(float width, float height, sf::Vector2f position, sf::Color color);
    ~Spectrum();

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    sf::Color getColor() const;
    void setColor(sf::Color color)
    {
        m_color = color;
        m_swatch.setFillColor(color);
    }
    void setPoles(const sf::Color pole0, const sf::Color pole1, const sf::Color pole2){
        m_pole0 = pole0;
        m_pole1 = pole1;
        m_pole2 = pole2;
    }

    bool isDragging() const { return m_dragging; }

private:
    sf::Texture m_texture;
    sf::CircleShape m_swatch;
    sf::CircleShape m_handle;
    sf::Color m_pole0;
    sf::Color m_pole1;
    sf::Color m_pole2;
    sf::Color m_color;

    bool m_dragging = false;
};