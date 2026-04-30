#include "message-box.h"

#include <SFML/Graphics/RenderTarget.hpp>

MessageBox::MessageBox(const std::string& fontPath)
    : box(sf::RectangleShape(sf::Vector2f(400.f, 100.f)))
    , font(sf::Font(fontPath))
    , text(font)
{
    box.setPosition(sf::Vector2f(100.f, 100.f));
    box.setFillColor(sf::Color(100, 100, 100));
    text.setPosition(box.getPosition() + sf::Vector2f(10.f, 10.f));
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(36);
    text.setString("Hello world");
}

void MessageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box);
    target.draw(text);
}

void MessageBox::setText(const std::string &str)
{
    this->text.setString(str);
}