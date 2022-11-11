#include"input.hpp"

#include"components.hpp"

#include<SFML/Window.hpp>

void Input::operator()(Context& context) {
    auto& entities = context.entities();
    for(auto e : entities.view<controls, player>()) {
        auto const& ctrl = entities.get<controls>(e);
        auto& play = entities.get<player>(e);

        play.intend_dash = sf::Keyboard::isKeyPressed(ctrl.dash);
        play.intend_down = sf::Keyboard::isKeyPressed(ctrl.down);
        play.intend_left = sf::Keyboard::isKeyPressed(ctrl.left);
        play.intend_right = sf::Keyboard::isKeyPressed(ctrl.right);
        play.intend_up = sf::Keyboard::isKeyPressed(ctrl.up);
    }
}
