#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main() {
    sf::RenderWindow window{{1280, 720}, "Die Chemer"};

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, -10.0f};
    b2WorldId worldId = b2CreateWorld(&worldDef);

    b2BodyDef groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = (b2Vec2){0.0f, -10.0f};
    
    b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);
    b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
    b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();

    }
  
    return 0;
}