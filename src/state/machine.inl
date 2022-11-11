    template<class StateType, class ... Args>
void StateMachine::push(Args ... args) {
    auto ptr = State::Ptr{new StateType{_context, *this, args ...}};
    _stack.push_front(std::move(ptr));
}
