//This is a C++ header file for a class called `SplashState` which is a derived class of `State`. It includes the necessary headers for SFML graphics and the `State` class. The `SplashState` class has several public and private member functions and variables, including an initialization function, input handling function, update function, and draw function. It also has a private member variable `_data` of type `GameDataRef` and a clock and sprite for displaying a background image. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once during compilation, even if it is included multiple times in different files.

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Team_Error
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Initialize();

		void InputHandle();
		void Update(float delta);
		void Draw(float delta);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}