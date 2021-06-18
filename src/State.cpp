#include "State.h"

State::State(std::stack<std::unique_ptr<State>>& states)
	:
	states(states)
{
	running = true;
}

void State::EndState()
{
	running = false;
}
