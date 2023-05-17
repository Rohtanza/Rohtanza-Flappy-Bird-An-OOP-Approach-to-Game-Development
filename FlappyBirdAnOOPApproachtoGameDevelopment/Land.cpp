/* This is the implementation file for the `Land` class. It includes the header file `Land.hpp` and
`DEFINITIONS.hpp`, and defines the member functions of the `Land` class. The `Land` class is
responsible for managing the land sprites in the game, moving them to the left, and drawing them on
the screen. It also provides a function to get the vector of land sprites. */

#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Team_Error
{
	Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(this->_data->assets.GetTexture("Land"));

		sprite.setPosition(0, this->_data->window.getSize().y - sprite.getLocalBounds().height);
		sprite2.setPosition(sprite.getLocalBounds().width, this->_data->window.getSize().y - sprite2.getLocalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::LandMove(float delta)
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			sf::Vector2f position = _landSprites.at(i).getPosition();
			float movement = PIPE_MOVEMENT_SPEED * delta;

			_landSprites.at(i).move(-movement, 0.0f);

			if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getLocalBounds().width)
			{
				sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);

				_landSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::LandDraw()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			this->_data->window.draw(_landSprites.at(i));
		}
	}

	const std::vector<sf::Sprite> &Land::GetSprites() const
	{
		return _landSprites;
	}
}