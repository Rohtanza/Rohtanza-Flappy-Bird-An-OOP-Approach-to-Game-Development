//This is a header file for the `Pipe` class in the `Team_Error` namespace. It includes the necessary headers for SFML graphics and the `Game` class. The `Pipe` class has several public functions for appearing, moving, and drawing different types of pipes, as well as getting the sprites and scoring sprites. It also has private member variables for the game data, the pipe sprites, and the scoring pipe sprites, as well as the land height and pipe spawn offset. The `#pragma once` directive is a header guard that ensures the header file is only included once in the compilation process.

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Team_Error
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);

		void AppearBottomPipe();
		void AppearTopPipe();
		void AppearInvisiblePipe();
		void AppearScoringPipe();
		void MovePipes(float dt);
		void DrawPipes();
		void RandomisePipeOffset();

		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;

	};
}