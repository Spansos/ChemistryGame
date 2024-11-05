#include "furniture.hpp"

#include <SFML/Graphics.hpp>
#include "room.hpp"

Furniture::Furniture(Room & room, sf::Texture * texture, sf::Vector2f position) : texture(texture) {
    // make body
    b2BodyDef body_def = b2DefaultBodyDef();
    body_def.type = b2_staticBody;
    body_def.position = (b2Vec2){position.x, position.y};

    body = b2CreateBody(room.get_world(), &body_def);
}

void Furniture::render(sf::RenderWindow & window) {
    b2Vec2 pos = b2Body_GetPosition(body);
    b2Rot rot = b2Body_GetRotation(body);

    sf::Sprite sprite;

    sprite.setTexture(*texture);
    sprite.setOrigin(sf::Vector2f{texture->getSize()}/2.0f);
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(b2Rot_GetAngle(rot)/(2.0f*b2_pi)*360.0f);
    sprite.setScale(1.0/texture->getSize().x, -1.0/texture->getSize().y);
    sprite.scale(2.5, 2.5);

    window.draw(sprite);
}