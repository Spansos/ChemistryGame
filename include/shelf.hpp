#pragma once

#include "furniture.hpp"
#include <SFML/Graphics.hpp>

class Shelf : public Furniture {
public:
    Shelf(Room & room, sf::Vector2f position) : Furniture(room, new sf::Texture, position) {
        texture->loadFromFile("./assets/a.png");

        // add shapes
        b2ShapeDef shape_def = b2DefaultShapeDef();

        b2Segment a{.point1=b2Vec2{.x=-1.1, .y=1.1}, .point2=b2Vec2{.x=1.1, .y=1.1}};
        b2CreateSegmentShape(body, &shape_def, &a);
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=1.1}, .point2=b2Vec2{.x=-1.1, .y=-1.25}};
        b2CreateSegmentShape(body, &shape_def, &a);
        a = b2Segment{.point1=b2Vec2{.x=1.1, .y=1.1}, .point2=b2Vec2{.x=1.1, .y=-1.25}};
        b2CreateSegmentShape(body, &shape_def, &a);

        float y = 2.5*((330-280)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);
        
        y = 2.5*((330-250)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);

        y = 2.5*((330-203)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);

        y = 2.5*((330-163)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);

        y = 2.5*((330-125)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);

        y = 2.5*((330-72)/330.0f)-1.25;
        a = b2Segment{.point1=b2Vec2{.x=-1.1, .y=y}, .point2=b2Vec2{.x=1.1, .y=y}};
        b2CreateSegmentShape(body, &shape_def, &a);
        
    }
    void update() override {};
private:
};