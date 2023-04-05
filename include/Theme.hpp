#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Theme
{
    public:
        static Theme& getInstance()
        {
            static Theme instance;
            return instance;
        }

        Theme(Theme const&) = delete;
        void operator=(Theme const&) = delete;

        sf::Font& getFont() { return font; }

    private:
        Theme() { font.loadFromFile("fonts/arial.ttf"); }

        sf::Font font;
};