/* This is the implementation file for the `SplashState` class. It includes the necessary header files,
defines the functions declared in the header file, and implements the logic for the splash screen
state of the game. The `Initialize()` function loads the background texture for the splash screen,
the `InputHandle()` function handles user input, the `Update()` function updates the state of the
game, and the `Draw()` function draws the game objects on the screen. */


//#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Team_Error
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Initialize()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::InputHandle()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float delta)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

		this->_data->window.display();
	}
}