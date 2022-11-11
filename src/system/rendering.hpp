#pragma once

#include"components.hpp"
#include"media.hpp"
#include"state.hpp"

#include<entt/entt.hpp>
#include<SFML/Graphics.hpp>

/**
 * @brief Handle the camera and draw the entities.
 * 
 * Used components:
 * - player (read-only)
 * - position (read-only)
 * - texture (read-only)
 * 
 * @ingroup system
 */
class RenderingSystem {
public:
    void operator()(Context&);

    static void changeColor(sf::RectangleShape& sprite, color const&);

    static void changePosition(
        sf::RectangleShape& sprite,
        rectangle const& position
    );

    static void changeSize(
        sf::RectangleShape& sprite,
        rectangle const& position
    );

    static void changeTexture(
        sf::RectangleShape& sprite,
        sf::Texture const&
    );

    static void drawBackground(Context&);

    /// @brief Draw all entities to the screen.
    static void drawEntities(Context&);

    /// @brief Center the view on the players.
    static void filmPlayers(Context&);

    /// @brief Reset the view to match the coordinates of the window.
    static void filmWindow(Context&);

    static rectangle playersView(entt::DefaultRegistry& entities);
};
