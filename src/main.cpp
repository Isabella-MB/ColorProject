#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "DebugLogger.h"
#include "Slider.h"
#include "Control.h"
#include "ColorPicker.h"

int main()
{
    // Initialize the game window and other resources
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    Button button(100, 50, sf::Vector2f(100, 100), sf::Color::Green);
    
    ColorPicker colorPicker(200, 200, sf::Vector2f(100, 200), sf::Color(50, 50, 50, 255));

    // Get the logger instance
    auto &logger = DebugLogger::getInstance();

    // Add some log messages
    logger.log("Starting program...");
    logger.log("Initializing resources...");

    // Start the game loop
    while (window.isOpen())
    {
        // Handle input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            button.handleEvent(event);
            logger.handleEvent(event);
            colorPicker.handleEvent(event);
        }

        // Update game logic

        // Clear the window
        window.clear();

        // Draw game objects
        button.draw(window);
        logger.draw(window);
        colorPicker.draw(window);

        // Display the window contents on the screen
        window.display();
    }

    // Clean up and exit
    return 0;
}
