#include"physics.hpp"

#include"components.hpp"
#include"generic.hpp"

void Physics::operator()(Context& context) {
    auto& entities = context.entities();
    auto framerate = context.framerate();
    updateVelocities(entities, framerate);
    preventOverlapping(entities);
    updatePositions(entities);
}

void Physics::preventOverlapping(entt::DefaultRegistry& entities) {
    for(auto e : entities.view<position, velocity>()) {
        auto const& pos = entities.get<position>(e).bounds;
        auto& vel = entities.get<velocity>(e).this_frame;
        auto motion_bounds = extended(pos, vel);
        auto response = vector::null;

        for(auto e : entities.view<position, solid>()) {
            auto& solid = entities.get<position>(e).bounds;
            if(not overlap(motion_bounds, solid)) continue;

            if(vel.x > 0)
                response.x = solid.left - motion_bounds.right - 1;
            else
                response.x = solid.right - motion_bounds.left + 1;
            if(vel.y > 0)
                response.y = solid.bottom - motion_bounds.top - 1;
            else 
                response.y = solid.top - motion_bounds.bottom + 1;
        }
        
        if(null(response)) continue;

        if(std::abs(response.x) < std::abs(response.y)) {
            vel.x += response.x;
            entities.get<velocity>(e).per_second.x = 0;
        }
        else {
            vel.y += response.y;
            entities.get<velocity>(e).per_second.y = 0;
        }
    }
}

void Physics::updatePositions(entt::DefaultRegistry& entities) {
    for(auto e : entities.view<position, velocity>()) {
        auto& pos = entities.get<position>(e).bounds;
        auto const& vel = entities.get<velocity>(e).this_frame;
        move(pos, vel);
    }
}

void Physics::updateVelocities(entt::DefaultRegistry& entities, int framerate) {
    for(auto e : entities.view<velocity>()) {
        auto& vel = entities.get<velocity>(e);
        auto corrected = vel.per_second + vel.error;
        vel.this_frame = corrected / framerate;
        vel.error = corrected % framerate;
    }
}
