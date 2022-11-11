#pragma once

#include"context.hpp"

#include<memory>

#include<SFML/Window.hpp>

class Context;
class StateMachine;

/**
 * @brief Base state
 * @ingroup state
 */
class State {
public:
    using Ptr = std::unique_ptr<State>;

    State(Context&, StateMachine&);

    virtual ~State() = default;

    virtual void handle(sf::Event const&) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    Context& _context;
    StateMachine& _stateMachine;
};