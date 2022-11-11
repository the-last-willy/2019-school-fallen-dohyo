#include"machine.hpp"

StateMachine::StateMachine(Context& context)
    : _context{context}
    , _stack{}
{}

void StateMachine::clear() {
    _stack.clear();
}

void StateMachine::pop() {
    _stack.erase_after(_stack.begin());
}

bool StateMachine::empty() const {
    return _stack.empty();
}

void StateMachine::handle(sf::Event const& event) {
    if(not empty()) {
        auto& top = *_stack.front();
        top.handle(event);
    }
}

void StateMachine::update() {
    if(not empty()) {
        auto& top = *_stack.front();
        top.update();
    }
}

void StateMachine::draw() {
    if(not empty()) {
        auto& top = *_stack.front();
        top.draw();
    }
}
