#include <memory>

#include <SFML/Graphics.hpp>

#include "room.hpp"

int main() {
    sf::RenderWindow window{{1280, 720}, "Die Chemer"};

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // // world
    // b2WorldDef worldDef = b2DefaultWorldDef();
    // worldDef.gravity = (b2Vec2){0.0f, -10.0f};
    // b2WorldId worldId = b2CreateWorld(&worldDef);

    // // ground
    // b2BodyDef groundBodyDef = b2DefaultBodyDef();
    // groundBodyDef.position = (b2Vec2){0.0f, -10.0f};
    
    // b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);
    // b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
    // b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    // b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    // // dynamic body
    // b2BodyDef bodyDef = b2DefaultBodyDef();
    // bodyDef.type = b2_dynamicBody;
    // bodyDef.position = (b2Vec2){0.0f, 4.0f};
    // b2BodyId bodyId = b2CreateBody(worldId, &bodyDef);

    // b2Polygon dynamicBox = b2MakeBox(1.0f, 1.0f);
    // b2ShapeDef shapeDef = b2DefaultShapeDef();
    // shapeDef.density = 1.0f;
    // shapeDef.friction = 0.3f;

    // b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);

    Room room{{16, 8}};
    room.add_item(std::make_unique<Item>(room));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        //     b2Body_ApplyTorque(bodyId, 50.0, true);

        room.update(window);
        room.render(window);
    }
  
    return 0;
}