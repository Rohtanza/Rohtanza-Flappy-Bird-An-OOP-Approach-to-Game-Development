/* This is the implementation file for the `MainMenuState` class. It includes necessary header files,
defines the class methods, and initializes the game assets and user interface elements for the main
menu state. It also handles user input and updates and draws the game objects on the screen. */

//#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Team_Error
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Initialize()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::InputHandle()
	{
		/* `sf::Event event;` is declaring a variable named `event` of type `sf::Event`. This variable is
		used to store events that occur in the game window, such as mouse clicks or keyboard presses. It
		is later used in the `InputHandle()` method to handle user input. */
		
		
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Main Menu
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float delta)
	{
		
	}

	void MainMenuState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}