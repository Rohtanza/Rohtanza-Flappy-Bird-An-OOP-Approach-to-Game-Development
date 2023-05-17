//This is a C++ header file for a State Machine class. It includes the necessary headers and defines the class and its member functions. The `#pragma once` directive is a header guard that ensures the file is only included once during compilation. The `namespace Team_Error` defines the namespace for the class. The class has member variables `_states`, `_newState`, `_remove`, `_add`, and `_replace`, and member functions `AddState()`, `RemoveState()`, `ProcessStateChanges()`, and `GetActiveState()`. The `typedef std::unique_ptr<State> StateRef` creates an alias for a unique pointer to a `State` object.
#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Team_Error
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() { }
		~StateMachine() { }

		void AddState(StateRef newState, bool replace = true);
		void RemoveState();
		// Run at start of each loop in Game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _remove;
		bool _add, _replace;
	};
}