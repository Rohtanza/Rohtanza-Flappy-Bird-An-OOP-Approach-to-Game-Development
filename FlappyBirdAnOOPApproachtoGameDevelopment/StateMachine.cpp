/* This is the implementation of a State Machine class in C++. It defines several methods for adding,
removing, and processing state changes in the state machine. The `#include "StateMachine.hpp"`
statement is including the header file for the State Machine class. The code is enclosed in the
`Team_Error` namespace. */


#include "StateMachine.hpp"

namespace Team_Error
{
	void StateMachine::AddState(StateRef newState, bool replace)
	{
		this->_add = true;
		this->_replace = replace;

		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->_remove = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (this->_remove && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			this->_remove = false;
		}

		if (this->_add)
		{
			if (!this->_states.empty())
			{
				if (this->_replace)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}

			this->_states.push(std::move(this->_newState));
            this->_states.top()->Initialize();
			this->_add = false;
		}
	}

	StateRef &StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}