#include"rendering.hpp"

#include"generic.hpp"

#include<cassert>

void RenderingSystem::operator()(Context& context) {
    filmWindow(context);
    drawBackground(context);
    filmPlayers(context);
    drawEntities(context);
}

void RenderingSystem::changeColor(sf::RectangleShape& sprite, color const& c) {
    sprite.setFillColor({c.red, c.green, c.blue});
}

void RenderingSystem::changePosition(
    sf::RectangleShape& sprite, 
    rectangle const& position
) {
    auto x = static_cast<float>(position.left);
    auto y = static_cast<float>(position.bottom);
    sprite.setPosition(x, y);
}

void RenderingSystem::changeSize(
    sf::RectangleShape& sprite, 
    rectangle const& position
) {
    auto h = static_cast<float>(height(position));
    auto w = static_cast<float>(width(position));
    sprite.setSize({w, h});
}

void RenderingSystem::changeTexture(
    sf::RectangleShape& sprite,
    sf::Texture const& texture
) {
    sprite.setTexture(&texture);
}

void RenderingSystem::drawBackground(Context& context) {
    auto& textures = context.textures();
    auto& background = textures.get(media::Texture::background);
    auto sprite = sf::Sprite{background};

    auto& canvas = context.canvas();
    canvas.draw(sprite);
}

void RenderingSystem::drawEntities(Context& context) {
    auto& canvas = context.canvas();
    auto& entities = context.entities();

    for(auto e : entities.view<position, texture>()) {
        sf::RectangleShape sprite;
        auto const& pos = entities.get<position>(e).bounds;
        changePosition(sprite, pos);
        changeSize(sprite, pos);
        auto const& texture = entities.get<::texture>(e).id;
        changeTexture(sprite, context.textures().get(texture));

        canvas.draw(sprite);
    }
}

void RenderingSystem::filmPlayers(Context& context) {
    auto& canvas = context.canvas();
    auto& entities = context.entities();

    auto view = extended(playersView(entities), ratio{16, 9});
    canvas.setView(sf::View{{
        static_cast<float>(view.left - 100), 
        static_cast<float>(view.top + 100), 
        static_cast<float>(width(view) + 200), 
        static_cast<float>(-height(view) - 200)
    }});
}

void RenderingSystem::filmWindow(Context& context) {
    auto& canvas = context.canvas();
    auto defaultView = canvas.getDefaultView();
    canvas.setView(defaultView);
}

rectangle RenderingSystem::playersView(entt::DefaultRegistry& entities) {
    auto players = entities.view<player, position>();
    assert(players.begin() != players.end());

    auto view = entities.get<position>(*players.begin()).bounds;
    for(auto it = ++players.begin(); it != players.end(); ++it) {
        auto const& pos = entities.get<position>(*it).bounds;
        view = bounding_rectangle(view, pos);
    }
    return view;
}
