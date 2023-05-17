// This is a header file for a C++ program that includes necessary libraries and defines a class called `Game` and a struct called `GameData`. It also defines a `typedef` for a shared pointer to `GameData`. The `#pragma once` directive is a non-standard but widely supported preprocessor directive that ensures the header file is only included once during compilation, even if it is included multiple times in different files.
#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Team_Error
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float delta = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}