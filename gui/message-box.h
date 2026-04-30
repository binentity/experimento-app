#ifndef EXPERIMENTO_APP_MESSAGE_BOX_H
#define EXPERIMENTO_APP_MESSAGE_BOX_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class MessageBox : public sf::CircleShape {
    sf::RectangleShape box;
    sf::Font font;
    sf::Text text;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    void setText(const std::string &str);
    explicit MessageBox(const std::string& fontPath);
    ~MessageBox() override = default;
};

#endif //EXPERIMENTO_APP_MESSAGE_BOX_H
