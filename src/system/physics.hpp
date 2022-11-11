#pragma once

#include"state.hpp"

#include<entt/entt.hpp>

/**
 * @brief Description pertinente.
 *
 * Used components:
 * - platform
 * - position
 * - velocity
 *
 * @ingroup system
 */
class Physics {
public:
    void operator()(Context&);

    /**
     * @brief Prevents collisions between [position / velocity]
     * and [position / solid].
     *
     * The velocity of the moving object is modified
     * so that it will noy overlap with any solid.
     * - Collision detection isn't forwarded.
     * - Tunneling is handled.
     */
    static void preventOverlapping(entt::DefaultRegistry& entities);

    /**
     * @brief On [position / velocity].
     */
    static void updatePositions(entt::DefaultRegistry& entities);

    /**
     * @brief On [velocity].
     */
    static void updateVelocities(
        entt::DefaultRegistry& entities,
        int framerate
    );
};
