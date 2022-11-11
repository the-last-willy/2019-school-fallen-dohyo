#pragma once

#include"state.hpp"

#include<entt/entt.hpp>

/**
 * @brief Main state.
 * @ingroup state
 */
class GameState : public State {
public:
    GameState(Context&, StateMachine&);

    void handle(sf::Event const&) override;
    void update() override;
    void draw() override;

    static void initialise(entt::DefaultRegistry&);

    static void load(sf::Music&);
    static void load(TextureHolder&);
};
