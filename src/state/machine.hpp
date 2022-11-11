#pragma once

#include"context.hpp"
#include"state.hpp"

#include<forward_list>

#include<SFML/Window.hpp>

/**
 * @brief Handle state transition.
 * @ingroup state
 */
class StateMachine {
public:
    StateMachine(Context&);

    /// @brief Empty the stack.
    void clear();

    /// @brief Remove the top state.
    void pop();

    /// @brief Add a state to the stack;
        template<class StateType, class ... Args>
    void push(Args ...);

    bool empty() const;

    void handle(sf::Event const&);
    void update();
    void draw();

private:
    Context& _context;
    std::forward_list<State::Ptr> _stack;
};

#include"machine.inl"
