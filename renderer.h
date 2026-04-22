#ifndef EXPERIMENTO_APP_RENDERER_H
#define EXPERIMENTO_APP_RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Renderer
{
    std::vector<std::shared_ptr<sf::CircleShape>> shapes;

public:
    void render(const std::shared_ptr<sf::RenderWindow> &device) const;
    explicit Renderer(const std::vector<std::shared_ptr<sf::CircleShape>> &shapes);
};

#endif //EXPERIMENTO_APP_RENDERER_H
