#ifndef EXPERIMENTO_APP_RENDERER_H
#define EXPERIMENTO_APP_RENDERER_H

#include "gui/message-box.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Renderer
{
    std::vector<std::shared_ptr<MessageBox>> shapes;
public:
    void render(const std::shared_ptr<sf::RenderWindow> &device) const;
    explicit Renderer(const std::vector<std::shared_ptr<MessageBox>> &shapes);
};

#endif //EXPERIMENTO_APP_RENDERER_H
