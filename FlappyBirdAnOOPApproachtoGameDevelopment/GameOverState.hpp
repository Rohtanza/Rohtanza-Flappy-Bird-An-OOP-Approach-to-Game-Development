//This is a C++ header file for the `GameOverState` class in a game development project. It includes the necessary SFML graphics library and other header files for the project. The `GameOverState` class inherits from the `State` class and has several public and private member functions and variables for initializing, handling input, updating, and drawing the game over screen. The `#pragma once` directive is a preprocessor directive that ensures the header file is only included once in the compilation process, preventing multiple definitions and potential errors.
#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Team_Error
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data, int score);
        
        void Initialize();
        
        void InputHandle();
        void Update(float delta);
        void Draw(float delta);
        
    private:
        GameDataRef _data;
        
        sf::Sprite _background;
        
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _medal;
        
        sf::Text _scoreText;
        sf::Text _highScoreText;
        
        int _score;
        int _highScore;
        
    };
}










