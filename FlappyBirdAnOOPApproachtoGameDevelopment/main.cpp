/*
 * The main function initializes and runs the Flappy Bird game.
 * 
 * @return The main function is returning the value of `EXIT_SUCCESS`, which is a constant defined in
 * the `cstdlib` library. It indicates that the program has executed successfully and is returning a
 * status code of 0.
 */
#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{
	Team_Error::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird: An OOP Approach to Game Development");

	return EXIT_SUCCESS;
}
