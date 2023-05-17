/* This is the implementation file for the `Flash` class. It defines the member functions of the class,
including the constructor, destructor, `Show`, and `Draw` functions. The `#include "Flash.hpp"`
statement at the beginning of the file includes the header file for the `Flash` class, which
contains the class declaration. The `namespace Team_Error` statement indicates that the `Flash`
class is defined within the `Team_Error` namespace. */

#include "Flash.hpp"

namespace Team_Error
{
	Flash::Flash(GameDataRef data) : _data(data)
	{
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize().x, _data->window.getSize().y));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));

		_flashOn = true;
	}

	Flash::~Flash()
	{
	}

	void Flash::Show(float delta)
	{
		if (_flashOn)
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * delta);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * delta);

			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}

	void Flash::Draw()
	{
		_data->window.draw(_shape);
	}
}