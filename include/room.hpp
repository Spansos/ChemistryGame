#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>
#include "item.hpp"
#include "furniture.hpp"

class Room {
public:
    Room(sf::Vector2f size) : size(size) {
        // create world
        b2WorldDef world_def = b2DefaultWorldDef();
        world_def.gravity = (b2Vec2){0.0f, -10.0f};
        world_def.enableSleep = false;
        world = b2CreateWorld(&world_def);

        // create walls (boxed in space)
        b2BodyDef body_def = b2DefaultBodyDef();
        body_def.type = b2_staticBody;
        body_def.position = (b2Vec2){0.0f, 0.0f};
        room = b2CreateBody(world, &body_def);

        b2ShapeDef shape_def = b2DefaultShapeDef();
        
        b2Polygon top    = b2MakeOffsetBox(size.x/2, 0.5f, (b2Vec2){0.0f,  size.y/2.0f+0.5f}, b2MakeRot(0.0f));
        b2Polygon bottom = b2MakeOffsetBox(size.x/2, 0.5f, (b2Vec2){0.0f, -size.y/2.0f-0.5f}, b2MakeRot(0.0f));
        b2Polygon left   = b2MakeOffsetBox(0.5f, size.y/2, (b2Vec2){-size.x/2.0f-0.5f, 0.0f}, b2MakeRot(0.0f));
        b2Polygon right  = b2MakeOffsetBox(0.5f, size.y/2, (b2Vec2){ size.x/2.0f+0.5f, 0.0f}, b2MakeRot(0.0f));

        b2CreatePolygonShape(room, &shape_def, &top);
        b2CreatePolygonShape(room, &shape_def, &bottom);
        b2CreatePolygonShape(room, &shape_def, &left);
        b2CreatePolygonShape(room, &shape_def, &right);
    }
    
    void update(sf::RenderWindow & window) {
        float timestep = 1.0 / 60.0;
        int sub_step_count = 4;

        for (auto & item : items)
            item->update(window);

        b2World_Step(world, timestep, sub_step_count);
    }

    void render(sf::RenderWindow & window) const {
        sf::Vector2u win_size = window.getSize();

        float win_ratio = (float)win_size.y / win_size.x;
        float room_ratio = size.y / size.x;

        if (win_ratio > room_ratio)
            window.setView(sf::View{{0, 0}, {size.x, win_ratio*-size.x}});
        else
            window.setView(sf::View{{0, 0}, {1/win_ratio*size.y, -size.y}});


        window.clear();

        sf::RectangleShape shape{size};
        shape.setOrigin(size/2.0f);
        shape.setFillColor(sf::Color{0x406080});
        window.draw(shape);

        for (const auto & item : items)
            item->render(window);

        for (const auto & furn : furniture)
            furn->render(window);

        window.display();
    }

    b2WorldId get_world() const {
        return world;
    }

    void add_item(std::unique_ptr<Item> item) {
        items.push_back(std::move(item));
    }

    void add_furniture(std::unique_ptr<Furniture> furn) {
        furniture.push_back(std::move(furn));
    }

    const sf::Vector2f size;
private:
    b2WorldId world;
    b2BodyId room;
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<Furniture>> furniture;
};