/* This is the implementation file for the HUD class. It includes the header file "HUD.hpp" and the
standard library header file "string". It defines the constructor, destructor, Draw() and
UpdateScore() functions for the HUD class. The constructor initializes the HUD object with the given
GameDataRef object, sets the font, text, size, color, origin and position of the score text. The
destructor does nothing. The Draw() function draws the score text on the game window. The
UpdateScore() function updates the score text with the given score value. */


#include "HUD.hpp"

#include <string>

namespace Team_Error
{
	HUD::HUD(GameDataRef data) : _data(data)
	{
		_scoreText.setFont(this->_data->assets.GetFont("Flappy Font")); 

		_scoreText.setString("0");

		_scoreText.setCharacterSize(128);

		_scoreText.setFillColor(sf::Color::White);

		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));

		_scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 5));
	}

	HUD::~HUD()
	{
	}

	void HUD::Draw()
	{
		_data->window.draw(_scoreText);
	}

	void HUD::UpdateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	}
}