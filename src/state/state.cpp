#include"state.hpp"

State::State(Context& context, StateMachine& stateMachine)
    : _context{context}
    , _stateMachine{stateMachine}
{}
