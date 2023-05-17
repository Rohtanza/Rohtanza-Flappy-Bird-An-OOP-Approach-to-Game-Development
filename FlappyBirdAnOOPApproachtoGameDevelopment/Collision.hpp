//This is a header file for a class called `Collision` in the namespace `Team_Error`. The class has two public member functions `CheckSpriteCollision` that take in `sf::Sprite` objects and check for collision between them. The first function checks for collision between two sprites of equal scale, while the second function allows for different scales to be passed in for each sprite. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once in the compilation process, even if it is included in multiple source files. The `SFML/Graphics.hpp` header file is included to provide access to the SFML graphics library.
#pragma once

#include <SFML/Graphics.hpp>

namespace Team_Error
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
		bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);

	};
}