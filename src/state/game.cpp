#include"game.hpp"

#include"components.hpp"
#include"context.hpp"
#include"generic.hpp"

#include"systems.hpp"

GameState::GameState(Context& context, StateMachine& stateMachine)
    : State{context, stateMachine}
{
    auto& entities = context.entities();
    initialise(entities);
    auto& textures = context.textures();
    load(textures);
    auto& music = context.music();
    load(music);
}

void GameState::handle(sf::Event const&) {
    Input{}(_context);
}

void GameState::update() {
    PlayerLogic{}(_context);
    Physics{}(_context);
}

void GameState::draw() {
    RenderingSystem{}(_context);
}

void GameState::initialise(entt::DefaultRegistry& entities) {
    entities.reset();

    auto entity = entities.create();
    entities.assign<controls>(entity);
    entities.assign<player>(entity);
    entities.assign<position>(entity, rectangle::lbwh(100, 700, 82, 132));
    entities.assign<velocity>(entity);
    entities.assign<texture>(entity, media::Texture::playerA);

    entity = entities.create();
    auto& ctrl = entities.assign<controls>(entity);
    ctrl.dash = sf::Keyboard::Numpad0;
    ctrl.down = sf::Keyboard::Down;
    ctrl.left = sf::Keyboard::Left;
    ctrl.right = sf::Keyboard::Right;
    ctrl.up = sf::Keyboard::Up;
    entities.assign<player>(entity);
    entities.assign<position>(entity, rectangle::lbwh(1000, 600, 82, 132));
    entities.assign<velocity>(entity);
    entities.assign<texture>(entity, media::Texture::playerB);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(10, -200, 1270, 1000));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(-5000, -400, 20000, 1));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(-500, 1000, 550, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(200, 1200, 50, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(500, 1300, 50, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(800, 1500, 50, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(500, 1600, 50, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(200, 1500, 50, 500));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(1400, 1500, 100, 50));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(1800, 1600, 1, 1000));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(2000, 1100, 100, 100));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    entity = entities.create();
    entities.assign<position>(entity, rectangle::lbwh(2500, 1300, 100, 100));
    entities.assign<solid>(entity);
    entities.assign<texture>(entity, media::Texture::platform);

    // entity = entities.create();
    // entities.assign<color>(entity, uint8_t{0}, uint8_t{255}, uint8_t{0});
    // entities.assign<position>(entity, rectangle::lbrt(1270, 150, 1310, 600));
    // entities.assign<solid>(entity);

    // entity = entities.create();
    // entities.assign<color>(entity, uint8_t{0}, uint8_t{0}, uint8_t{255});
    // entities.assign<position>(entity, rectangle::lbrt(1270, 10, 1970, 30));
    // entities.assign<solid>(entity);

    // entity = entities.create();
    // entities.assign<color>(entity, uint8_t{0}, uint8_t{0}, uint8_t{255});
    // entities.assign<position>(entity, rectangle::lbrt(-710, 10, 10, 30));
    // entities.assign<solid>(entity);
}

void GameState::load(sf::Music& music) {
    music.openFromFile("media/music/epic.ogg");
    music.play();
}

void GameState::load(TextureHolder& textures) {
    textures.load(media::Texture::background, "media/texture/background.png");
    textures.load(media::Texture::playerA, "media/texture/playerA.png");
    textures.load(media::Texture::playerB, "media/texture/playerB.png");
    textures.load(media::Texture::platform, "media/texture/wood.png");
}
