#pragma once

#include <box2d/box2d.h>

class Room;
namespace sf{class RenderWindow;}

class Item {
public:
    Item(const Room & room);
    void update(sf::RenderWindow & window);
    void render(sf::RenderWindow & window) const;
public:
    b2BodyId body;
};