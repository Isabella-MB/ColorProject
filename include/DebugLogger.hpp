#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

class DebugLogger
{
public:
    // Get the singleton instaexecutable, but this command may not be available on all systems. You may want to use the del or erase command instead to ensure that the rule works on all platforms.nce of the logger
    static DebugLogger& getInstance()
    {
        static DebugLogger instance;
        return instance;
    }

    // Add a log message to the stack
    void log(const std::string& message)
    {
        // Push the message to the log stack
        m_logStack.push_back(message);

	std::cout << message;

        // Keep the stack size limited to 8 messages
        if (m_logStack.size() > 8)
        {
            m_logStack.erase(m_logStack.begin());
        }
    }

    // Draw the log messages to the window
    void draw(sf::RenderWindow& window)
    {
    	if (m_visible)
    	{
		// Set the text properties
		m_text.setFont(m_font);
		m_text.setCharacterSize(12);
		m_text.setFillColor(sf::Color::White);
		m_text.setPosition(10, 10);

		// Concatenate the log messages into a single string
		std::string logString;
		for (const auto& message : m_logStack)
		{
		    logString += message + "\n";
		}

		// Set the text string and draw it to the window
		m_text.setString(logString);
		window.draw(m_text);
        }
    }

    // Handle events
    void handleEvent(const sf::Event& event)
    {
        // Check if the tab key was pressed
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
        {
            // Toggle the visibility of the log messages
            m_visible = !m_visible;
        }
    }

private:
    // Private constructor to prevent multiple instances
    DebugLogger()
    {
        m_font.loadFromFile("fonts/arial.ttf");
    }

    // Private copy constructor and assignment operator to prevent copying
    DebugLogger(const DebugLogger&) = delete;
    DebugLogger& operator=(const DebugLogger&) = delete;

    // Font and text objects for drawing the log messages
    sf::Font m_font;
    sf::Text m_text;

    // Vector to store the log messages
    std::vector<std::string> m_logStack;

    // Flag to store the visibility of the log messages
    bool m_visible = true;
};

