//This is a C++ header file defining a class called `InputManager` in the namespace `Team_Error`. The class has two public member functions: `IsSpriteClicked` and `GetMousePosition`. The `IsSpriteClicked` function takes a `sf::Sprite` object, a `sf::Mouse::Button` button, and a reference to a `sf::RenderWindow` object as arguments and returns a boolean value indicating whether the sprite was clicked with the specified mouse button. The `GetMousePosition` function takes a reference to a `sf::RenderWindow` object as an argument and returns a `sf::Vector2i` object representing the current position of the mouse cursor in the window. The `#pragma once` directive at the beginning of the file is a preprocessor directive that ensures the header file is only included once in a compilation unit, preventing multiple definitions of the same class.
#pragma once

#include "SFML\Graphics.hpp"

namespace Team_Error
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}