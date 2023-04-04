#include "ColorPicker.h"

ColorPicker::ColorPicker(float width, float height, sf::Vector2f position, sf::Color color) : Control(width, height, position)
{
    m_colorPicker.setSize(sf::Vector2f(m_width, m_height));
    m_colorPicker.setPosition(m_position);
    m_colorPicker.setFillColor(color);

    m_primarySwatch = new ColorSwatch(m_width / 4, m_height / 4, sf::Vector2f(m_position.x, m_position.y), sf::Color::White);
    m_secondarySwatch = new ColorSwatch(m_width / 4, m_height / 4, sf::Vector2f(m_position.x + m_width - m_width / 4, m_position.y), sf::Color::Black);

    sf::Font &theme_font = Theme::getInstance().getFont();

    m_primarySwatchLabel = new Label(m_width / 4, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height - m_height / 4), sf::Color::White, "Primary", theme_font, 12);
    m_secondarySwatchLabel = new Label(m_width / 4, m_height / 4, sf::Vector2f(m_position.x + m_width - m_width / 4, m_position.y + m_height - m_height / 4), sf::Color::White, "Secondary", theme_font, 12);

    m_redSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height), sf::Color::Black, sf::Color::Red);
    m_greenSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height / 4), sf::Color::Black, sf::Color::Green);
    m_blueSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height / 2), sf::Color::Black, sf::Color::Blue);
    m_alphaSlider = new Slider(m_width, m_height / 4, sf::Vector2f(m_position.x, m_position.y + m_height + m_height * 3 / 4), sf::Color::Black, sf::Color::White);

    updateSliders(sf::Color::White);
}

ColorPicker::~ColorPicker()
{
    delete m_primarySwatch;
    delete m_secondarySwatch;

    delete m_redSlider;
    delete m_greenSlider;
    delete m_blueSlider;
    delete m_alphaSlider;
}

void ColorPicker::updateSliders(sf::Color color)
{
    m_redSlider->setValue(color.r);
    m_greenSlider->setValue(color.g);
    m_blueSlider->setValue(color.b);
    m_alphaSlider->setValue(color.a);
}

void ColorPicker::updateLabels()
{
    std::stringstream sstream;
    sstream << "0x" << std::setfill('0') << std::setw(8) << std::hex << m_primarySwatch->getColor().toInteger();
    std::string primaryText = sstream.str();

    m_primarySwatchLabel->setText(primaryText);
}

void ColorPicker::handleEvent(const sf::Event &event)
{
    m_primarySwatch->handleEvent(event);
    m_secondarySwatch->handleEvent(event);

    m_redSlider->handleEvent(event);
    m_greenSlider->handleEvent(event);
    m_blueSlider->handleEvent(event);
    m_alphaSlider->handleEvent(event);

    auto color = sf::Color(m_redSlider->getValue(), m_greenSlider->getValue(), m_blueSlider->getValue(), m_alphaSlider->getValue());

    if (event.type != sf::Event::MouseMoved)
    {
        return;
    }

    if (m_redSlider->isDragging() || m_greenSlider->isDragging() || m_blueSlider->isDragging() || m_alphaSlider->isDragging())
    {
        m_primarySwatch->setColor(color);
        updateLabels();
    }
}

void ColorPicker::draw(sf::RenderWindow &window)
{
    window.draw(m_colorPicker);

    m_primarySwatchLabel->draw(window);
    m_secondarySwatchLabel->draw(window);

    m_primarySwatch->draw(window);
    m_secondarySwatch->draw(window);

    m_redSlider->draw(window);
    m_greenSlider->draw(window);
    m_blueSlider->draw(window);
    m_alphaSlider->draw(window);
}
