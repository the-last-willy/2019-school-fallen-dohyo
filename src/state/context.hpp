#pragma once

#include"media.hpp"

#include<entt/entt.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

/**
 * @brief Contains references to all system modules.
 * @ingroup state
 */
class Context {
public:
    Context();

    void canvas(sf::RenderTarget&);
    void entities(entt::DefaultRegistry&);
    void framerate(int);
    void music(sf::Music&);
    void textures(TextureHolder&);
    void window(sf::Window&);

    sf::RenderTarget& canvas();
    entt::DefaultRegistry& entities();
    int framerate();
    sf::Music& music();
    TextureHolder& textures();
    sf::Window& window();

private:

    sf::RenderTarget* _canvas;
    entt::DefaultRegistry* _entities;
    int _framerate;
    sf::Music* _music;
    TextureHolder* _textures;
    sf::Window* _window;
};
