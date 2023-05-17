/* This is the implementation of the `Game` class in C++. It includes the header files for `Game` and
`SplashState`, as well as the standard library headers for `stdlib` and `time`. The `Game`
constructor initializes the random number generator and creates a window with the specified
dimensions and title. It also adds a new `SplashState` to the state machine and calls the `Run`
method. */
#include "Game.hpp"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>


namespace Team_Error
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= delta)
			{
                this->_data->machine.GetActiveState()->InputHandle();
				this->_data->machine.GetActiveState()->Update(delta);

				accumulator -= delta;
			}

			interpolation = accumulator / delta;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}