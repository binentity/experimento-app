#include <iostream>
#include <SFML/Graphics.hpp>

constexpr unsigned int WIDTH = 2550;
constexpr unsigned int HEIGHT = 1440;

constexpr sf::Vector2u screenVector(WIDTH, HEIGHT);

const std::string WINDOW_TITLE = "Happiness";

int main()
{

    std::cout << "hello world" << std::endl;

    const sf::VideoMode mode(screenVector);
    sf::RenderWindow window(mode, WINDOW_TITLE);

    while (window.isOpen()) {

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Green);

        window.display();
    }
    return 0;
}