#include"playerLogic.hpp"

#include"components.hpp"

#include"generic.hpp"

void PlayerLogic::operator()(Context& context) {
    auto& entities = context.entities();
    auto framerate = context.framerate();
    for(auto e : entities.view<player, velocity>()) {
        auto& play = entities.get<player>(e);
        auto const& pos = entities.get<position>(e).bounds;
        auto& vel = entities.get<velocity>(e).per_second;
        lean(play, pos, entities);
        dash(play, vel, framerate);
        jump(play, vel, framerate);
        gravitate(play, vel);
        movement(play, vel);
        friction(play, vel);
    }
}

void PlayerLogic::dash(player& p, vector& velocity, int framerate) {
    p.dash_cd -= 1;
    p.dash_acceleration = {
        -p.intend_left + p.intend_right, 
        -p.intend_down + p.intend_up
    };
    p.dash_speed = 500;

    if(p.dash_cd < 0) {
        p.dash_cd = 0;
    }

    if(p.intend_dash && p.dash_cd == 0 && !null(p.dash_acceleration)) {
        p.dash_timer = p.dash_duration;
        p.dash_cd = 2 * framerate;
    }

    if(p.dash_timer > 0) {
        if(p.against_floor && p.dash_acceleration.y == 0)
            p.dash_speed = 1500;
        else
            p.dash_speed = 800;

        p.dash_timer -= 1;
        p.dash_acceleration *= p.dash_speed;
        velocity += p.dash_acceleration;  
    }
}

void PlayerLogic::fall(player&, rectangle const&) {}

void PlayerLogic::friction(player& p, vector& velocity) {
    if(p.against_floor) {
        velocity.x *= 85;
        velocity.x /= 100;
    }
    else {
        velocity.x *= 90;
        velocity.x /= 100;
    }

    if(p.against_wall) {
        velocity.y *= 85;
        velocity.y /= 100;
    }
}

void PlayerLogic::gravitate(player const&, vector& velocity) {
    auto intensity = 50;
    if(velocity. y > 0)
        intensity = 20;
    else if(velocity.y < 0)
        intensity = 50;
    velocity.y -= intensity;
}

void PlayerLogic::jump(player& p, vector& velocity, int) {
    if(p.against_floor && p.intend_up && !p.jumping) {
        auto vertical_acceleration = (p.intend_up) * 650;
        velocity.y += vertical_acceleration;
        p.jumping = true;
    }

    if(p.jumping && !p.intend_up) {
        velocity.y = 0;
        p.jumping = false;
    }

    if(p.against_wall && p.intend_up && p.facing_left && !p.jumping) {
        p.impulsion = {800, 600};
        velocity = p.impulsion;
        p.jumping = true;
    }
    else if(p.against_wall && p.intend_up && p.facing_right && !p.jumping) {
        p.impulsion = {-800, 600};
        velocity = p.impulsion;
        p.jumping = true;
    }
}

void PlayerLogic::lean(
    player& play, 
    rectangle const& position, 
    entt::DefaultRegistry& entities
) {
    auto bot = false, left = false, right = false;
    for(auto e : entities.view<::position, solid>()) {
        auto const& plat = entities.get<::position>(e).bounds;
        bot = bot or overlap(bottom_side(position), plat);
        left = left or overlap(left_side(position), plat);
        right = right or overlap(right_side(position), plat);
    }
    play.against_floor = bot;
    play.against_wall = left or right;
    // play.facing_left = play.facing_left or right;
    // play.facing_right = play.facing_right or left;
}

void PlayerLogic::movement(player& p, vector& velocity) {
    auto horizontal_acceleration = (p.intend_right - p.intend_left) * p.move_speed;
    velocity += vector{horizontal_acceleration, 0};

    if (velocity.x > 0) {
        p.facing_left = false;
        p.facing_right = true;
    }
    if(velocity.x < 0) {
        p.facing_left = true;
        p.facing_right = false;
    }
}
