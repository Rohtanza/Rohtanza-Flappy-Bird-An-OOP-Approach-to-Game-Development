//This is a header file for a class called "Flash" in the namespace "Team_Error". The class has a constructor, destructor, and two member functions: "Show" and "Draw". It also has three private member variables: "_data" of type "GameDataRef", "_shape" of type "sf::RectangleShape", and "_flashOn" of type "bool". The header file includes the necessary SFML graphics library, as well as two other header files: "Game.hpp" and "DEFINITIONS.hpp". The "#pragma once" statement is a preprocessor directive that ensures the header file is only included once in the compilation process, even if it is included in multiple source files.
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Team_Error
{
	class Flash
	{
	public:
		Flash(GameDataRef data);
		~Flash();

		void Show(float delta);
		void Draw();

	private:
		GameDataRef _data;

		sf::RectangleShape _shape;

		bool _flashOn;

	};
}