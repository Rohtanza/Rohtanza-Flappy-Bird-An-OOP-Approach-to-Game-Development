//This is a header file for the HUD class in the Team_Error namespace. It includes the necessary SFML graphics library, as well as the DEFINITIONS and Game header files. The HUD class has a constructor, destructor, Draw() function, and UpdateScore() function. It also has a private member variable for the game data reference and a text object for displaying the score. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once during compilation, preventing multiple definitions and potential errors.
#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Team_Error
{
	class HUD
	{
	public:
		HUD(GameDataRef data);
		~HUD();

		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;

		sf::Text _scoreText;

	};
}