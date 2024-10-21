#pragma once

#include <box2d/box2d.h>
#include <SFML/System/Vector2.hpp>

class Room;
namespace sf{class RenderWindow;class Texture;}

class Furniture {
public:
    Furniture(Room & room, sf::Texture * texture, sf::Vector2f position);
    virtual void update() = 0;
    void render(sf::RenderWindow & window);
protected:
    sf::Texture * texture;
    b2BodyId body;
};