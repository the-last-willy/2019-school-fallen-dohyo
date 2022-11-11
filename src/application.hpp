#pragma once

#include"generic.hpp"
#include"media.hpp"
#include"state.hpp"

#include<entt/entt.hpp>
#include<SFML/Graphics.hpp>

class Application {
public:
    Application(unsigned width, unsigned height, int framerate = 60);

    int framerate() const;
    bool running() const;

    void handleEvents();
    void update();
    void draw();

private:
    int _framerate;
    entt::DefaultRegistry _entities;
    sf::Music _music;
    TextureHolder _textures;
    sf::RenderWindow _window;

    Context _context;

    StateMachine _stateMachine;
};

void run(Application&);
