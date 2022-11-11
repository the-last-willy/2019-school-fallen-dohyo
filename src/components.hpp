#pragma once

#include"generic.hpp"
#include"generic.hpp"
#include"media.hpp"

#include<SFML/Window.hpp>

/**
 * @defgroup component Components
 * @brief Components to make entities.
 */

/**
 * @brief 24-bits RGB color.
 * @ingroup component
 */
struct color {
    color() = delete;
    
    color(unsigned char red, unsigned char green, unsigned char blue) 
        : red{red}, green{green}, blue{blue}
    {}

    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

/**
 * @brief Controls of a player.
 * @ingroup component
 */
struct controls {
    sf::Keyboard::Key dash = sf::Keyboard::Space;
    sf::Keyboard::Key down = sf::Keyboard::S;
    sf::Keyboard::Key left = sf::Keyboard::Q;
    sf::Keyboard::Key right = sf::Keyboard::D;
    sf::Keyboard::Key up = sf::Keyboard::Z;
};

/**
 * @brief State of a player.
 * @ingroup component
 */
struct player {
    bool against_floor = false;
    bool against_wall = false;
    bool dashing = false;
    bool facing_left = false;
    bool facing_right = false;
    bool intend_dash = false;
    bool intend_down = false;
    bool intend_left = false;
    bool intend_right = false;
    bool intend_up = false;
    bool jumping = false;

    int move_speed = 80;
    
    int dash_cd = 0, dash_duration = 1, dash_timer = 0, dash_speed;

    vector impulsion = {0, 0};

    vector dir;
    vector dash_acceleration;
};

/**
 * @brief Position of an entity.
 * 
 * The position is represented as an axis-aligned rectangle
 * instead of a single point.
 * 
 * @ingroup component
 */
struct position {
    position() = delete;
    position(rectangle const& bounds) : bounds(bounds) {}

    rectangle bounds;
};

/**
 * @brief Tag component.
 * @ingroup component
 */
struct solid {};

/**
 * @brief Texture component.
 * @ingroup component
 */
struct texture {
    texture(media::Texture::ID id) 
        : id(id)
    {}

    media::Texture::ID id;
};

/**
 * @brief Velocity of an entity.
 * @ingroup component.
 */
struct velocity {
    velocity() 
        : error{vector::null}
        , per_second{vector::null}
        , this_frame{vector::null}
    {}

    vector error; // incremental error term
    vector per_second;
    vector this_frame; // precalculated value
};
