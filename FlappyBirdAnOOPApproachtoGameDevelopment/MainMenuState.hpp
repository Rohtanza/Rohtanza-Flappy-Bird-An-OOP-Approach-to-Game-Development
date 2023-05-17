//This is a C++ header file for the MainMenuState class, which is a derived class of the State class. It includes the necessary headers for SFML graphics and the State and Game classes. The class has public functions for initializing, handling input, updating, and drawing. It also has private member variables for the game data, background sprite, title sprite, and play button sprite. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once during compilation, preventing multiple definitions and potential errors.
#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Team_Error
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Initialize();

		void InputHandle();
		void Update(float delta);
		void Draw(float delta);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
	};
}