#include "item.hpp"

#include <SFML/Graphics.hpp>
#include "room.hpp"

Item::Item(const Room & room) {
    // make body
    b2BodyDef body_def = b2DefaultBodyDef();
    body_def.type = b2_dynamicBody;
    body_def.position = (b2Vec2){0.0f, 0.0f};

    body = b2CreateBody(room.get_world(), &body_def);

    // add box shape
    b2Polygon box = b2MakeBox(0.05f, 0.05f);
    b2ShapeDef shape_def = b2DefaultShapeDef();
    shape_def.density = 0.3f;
    shape_def.friction = 0.3f;

    b2CreatePolygonShape(body, &shape_def, &box);
}


void Item::update(sf::RenderWindow & window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        sf::Vector2f mouse_pos{sf::Mouse::getPosition(window)};
        mouse_pos -= sf::Vector2f{window.getSize() / 2u};
        mouse_pos = {mouse_pos.x/window.getSize().x, mouse_pos.y/window.getSize().y};
        mouse_pos.x *= window.getView().getSize().x;
        mouse_pos.y *= window.getView().getSize().y;
        b2Body_ApplyForceToCenter(body, (b2Vec2){mouse_pos.x/4, mouse_pos.y/4}, true);
    }
}

void Item::render(sf::RenderWindow & window) const {
    b2Vec2 pos = b2Body_GetPosition(body);
    b2Rot rot = b2Body_GetRotation(body);
    
    sf::RectangleShape shape;

    shape.setSize({0.1f, 0.1f});
    shape.setOrigin(0.05f, 0.05f);
    shape.setPosition(pos.x, pos.y);
    shape.setRotation(b2Rot_GetAngle(rot)/(2.0f*b2_pi)*360.0f);

    shape.setFillColor(sf::Color::Red);

    window.draw(shape);
}