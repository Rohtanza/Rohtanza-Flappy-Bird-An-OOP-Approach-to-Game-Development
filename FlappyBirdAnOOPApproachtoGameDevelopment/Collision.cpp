/* This is a C++ code defining a class called `Collision` with two methods `CheckSpriteCollision`. The
first method takes two `sf::Sprite` objects as arguments and checks if their global bounds
intersect. The second method takes two `sf::Sprite` objects and two scaling factors as arguments,
sets the scaling factors for the sprites, and then checks if their global bounds intersect. The code
is also including the `Collision.hpp` header file and the `iostream` library. The code is enclosed
in the `Team_Error` namespace. */


#include "Collision.hpp"
#include <iostream>
namespace Team_Error
{
	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
	{
		sprite1.setScale(scale1, scale1);
		sprite2.setScale(scale2, scale2);

		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}