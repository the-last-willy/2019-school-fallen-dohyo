#include"context.hpp"

#include<stdexcept>

Context::Context()
    : _canvas{nullptr}
    , _entities{nullptr}
    , _framerate{0}
    , _music{nullptr}
    , _textures{nullptr}
    , _window{nullptr}
{}

void Context::canvas(sf::RenderTarget& canvas) {
    _canvas = &canvas;
}

void Context::entities(entt::DefaultRegistry& entities) {
    _entities = &entities;
}

void Context::framerate(int framerate) {
    _framerate = framerate;
}

void Context::music(sf::Music& music) {
    _music = &music;
}

void Context::textures(TextureHolder& textures) {
    _textures = &textures;
}

void Context::window(sf::Window& window) {
    _window = &window;
}

sf::RenderTarget& Context::canvas() {
    #ifdef DEBUG
    if(not _canvas) throw std::runtime_error(
        "Context::canvas - Unspecified."
    );
    #endif

    return *_canvas;
}

entt::DefaultRegistry& Context::entities() {
    #ifdef DEBUG
    if(not _entities) throw std::runtime_error(
        "Context::entities - Unspecified."
    );
    #endif

    return *_entities;
}

int Context::framerate() {
    #ifdef DEBUG
    if(_framerate <= 0) throw std::runtime_error(
        "Context::framerate - Unspecified."
    );
    #endif

    return _framerate;
}

sf::Music& Context::music() {
    #ifdef DEBUG
    if(not _music) throw std::runtime_error(
        "Context::framerate - Unspecified."
    );
    #endif

    return *_music;
}

TextureHolder& Context::textures() {
    #ifdef DEBUG
    if(not _textures) throw std::runtime_error(
        "Context::textures - Unspecified."
    );
    #endif

    return *_textures;
}

sf::Window& Context::window() {
    #ifdef DEBUG
    if(not _window) throw std::runtime_error(
        "Context::window - Unspecified."
    );
    #endif

    return *_window;
}
