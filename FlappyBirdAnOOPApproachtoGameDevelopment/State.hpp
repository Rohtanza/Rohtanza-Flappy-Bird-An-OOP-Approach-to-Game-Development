//This is a C++ code snippet defining a namespace `Team_Error` and a class `State` with pure virtual functions. The `#pragma once` directive is a non-standard but widely supported preprocessor directive that ensures the header file is only included once during compilation, preventing multiple definitions of the same class or function.

#pragma once

namespace Team_Error
{
	class State
	{
	public:
		virtual void Initialize() = 0;

		virtual void InputHandle() = 0;
		virtual void Update(float delta) = 0;
		virtual void Draw(float delta) = 0;

		virtual void Pause() { }
		virtual void Resume() { }
	};
}