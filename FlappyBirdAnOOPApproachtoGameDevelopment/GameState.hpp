//This is a header file for the GameState class, which is a derived class of the State class. It includes necessary SFML libraries and other header files for the class. The class contains member variables and functions for handling game logic, input, updating, and drawing. It also includes objects for the game's background, pipes, land, bird, collision detection, flashing effects, and HUD. Additionally, it includes sound buffers and sound objects for playing sound effects during gameplay. The `#pragma once` directive is a header guard that ensures the header file is only included once during compilation.
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace Team_Error
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Initialize();

		void InputHandle();
		void Update(float delta);
		void Draw(float delta);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Pipe *pipe;
		Land *land;
		Bird *bird;
		Collision collision;
		Flash *flash;
		HUD *hud;

		sf::Clock clock;

		int _gameState;

		sf::RectangleShape _gameOverFlash;
		bool _flashOn;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;

		sf::Sound _hitSound;
		sf::Sound _wingSound;
		sf::Sound _pointSound;

	};
}