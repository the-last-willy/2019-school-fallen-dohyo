#pragma once

#include"state.hpp"

#include<entt/entt.hpp>

class player;
class rectangle;
class vector;

/**
 * @brief Update players.
 * 
 * Used components:
 * - platform (read-only)
 * - player
 * - velocity
 * 
 * @ingroup system
 */
class PlayerLogic {
public:
    void operator()(Context&);

    static void dash(player&, vector& velocity, int framerate);

    static void fall(player&, rectangle const& position);

    static void friction(player&, vector& velocity);

    static void gravitate(player const&, vector& velocity);

    static void jump(player&, vector& velocity, int framerate);

    static void lean(
        player&,
        rectangle const& position,
        entt::DefaultRegistry& entities
    );

    static void movement(player&, vector& velocity);
};
