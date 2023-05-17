/* This is the implementation file for the `Bird` class. It defines the member functions of the class,
including the constructor, destructor, and various update and drawing functions. The `Bird` class
represents the bird character in a Flappy Bird game, and this implementation file contains the logic
for animating the bird, updating its position and rotation, and handling user input to make the bird
flap its wings and fly. */


#include "Bird.hpp"

namespace Team_Error
{
	Bird::Bird(GameDataRef data) : _data(data)
	{
        _animationLoop = 0;

		_animationFrames.push_back(this->_data->assets.GetTexture("Bird Frame 1"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Bird Frame 2"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Bird Frame 3"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Bird Frame 4"));

		_birdSprite.setTexture(_animationFrames.at(_animationLoop));

		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));
	
		_birdState = BIRD_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);

		_birdSprite.setOrigin(origin);

		_rotation = 0;
	}

	Bird::~Bird()
	{
	}

	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float delta)
	{
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationLoop < _animationFrames.size() - 1)
			{
				_animationLoop++;
			}
			else
			{
                _animationLoop = 0;
			}

			_birdSprite.setTexture(_animationFrames.at(_animationLoop));

			_clock.restart();
		}
	}

	void Bird::Update(float delta)
	{
		if (BIRD_STATE_FALLING == _birdState)
		{
			_birdSprite.move(0, GRAVITY * delta);

			_rotation += ROTATION_SPEED * delta;

			if (_rotation > 25.0f)
			{
				_rotation = 25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}
		else if (BIRD_STATE_FLYING == _birdState)
		{
			_birdSprite.move(0, -FLYING_SPEED * delta);

			_rotation -= ROTATION_SPEED * delta;

			if (_rotation < -25.0f)
			{
				_rotation = -25.0f;
			}

			_birdSprite.setRotation(_rotation);
		}

		if (_ClockMovement.getElapsedTime().asSeconds() > FLYING_DURATION)
		{
			_ClockMovement.restart();
			_birdState = BIRD_STATE_FALLING;
		}
	}

	void Bird::Tap()
	{
		_ClockMovement.restart();
		_birdState = BIRD_STATE_FLYING;
	}

	const sf::Sprite &Bird::GetSprite() const
	{
		return _birdSprite;
	}
}