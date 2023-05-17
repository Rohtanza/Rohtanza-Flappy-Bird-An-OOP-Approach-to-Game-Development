//This is a C++ header file for the `Bird` class in the `Team_Error` namespace. It includes the necessary SFML graphics library, as well as other header files for the game's definitions and main game class. The `Bird` class has several public functions for drawing, animating, updating, and tapping the bird sprite, as well as a private data member for the game data reference and other variables for the bird's state and animation. The `#pragma once` directive is a header guard that ensures the header file is only included once during compilation to prevent errors from multiple inclusions.
#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include <vector>

namespace Team_Error
{
	class Bird
	{
	public:
		Bird(GameDataRef data);
		~Bird();

		void Draw();

		void Animate(float delta);

		void Update(float delta);

		void Tap();

		const sf::Sprite &GetSprite() const;

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationLoop;

		sf::Clock _clock;

		sf::Clock _ClockMovement;

		int _birdState;

		float _rotation;

	};
}