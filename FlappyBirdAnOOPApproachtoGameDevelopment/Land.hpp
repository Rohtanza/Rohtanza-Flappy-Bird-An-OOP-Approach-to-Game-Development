//This is a header file for a class called `Land` in the namespace `Team_Error`. It includes the necessary SFML graphics library and the `Game.hpp` header file. The class has a constructor that takes a `GameDataRef` object as a parameter, as well as methods for moving and drawing the land sprites and getting the vector of land sprites. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once during compilation to prevent multiple definitions.
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Team_Error
{
	class Land
	{
	public:
		Land(GameDataRef data);

		void LandMove(float delta);
		void LandDraw();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;

		std::vector<sf::Sprite>_landSprites;

	};
}