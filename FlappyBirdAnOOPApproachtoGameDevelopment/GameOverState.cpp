/* This is the implementation of the `GameOverState` class in a game developed using SFML library in
C++. The class handles the game over state of the game, where the player's score is displayed along
with the high score and a medal based on the score achieved. The class also updates the high score
if the player's score is higher than the current high score. The class loads textures and fonts
required for the game over state and handles user input to restart the game. */
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"

#include <iostream>
#include <fstream>

namespace Team_Error
{
    GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
    {
        
    }
    
    void GameOverState::Initialize()
    {
        std::ifstream readFile;
        readFile.open( "Resources/Highscore.txt" );
        
        if ( readFile.is_open( ) )
        {
            while ( !readFile.eof( ) )
            {
                readFile >> _highScore;
            }
        }
        
        readFile.close( );
        
        std::ofstream writeFile( "Resources/Highscore.txt" );
        
        if ( writeFile.is_open( ) )
        {
            if ( _score > _highScore )
            {
                _highScore = _score;
            }
            
            writeFile << _highScore;
        }
        
        writeFile.close( );
        
        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        this->_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
        _gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
        _retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        _gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
        _gameOverTitle.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));
        _retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));
        
        _scoreText.setFont(this->_data->assets.GetFont("Flappy Font"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
        _scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15));
        
        _highScoreText.setFont(this->_data->assets.GetFont("Flappy Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
        _highScoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78));
        
        if ( _score >= PLATINUM_MEDAL_SCORE )
        {
            _medal.setTexture( _data->assets.GetTexture( "Platinum Medal" ) );
        }
        else if ( _score >= GOLD_MEDAL_SCORE )
        {
            _medal.setTexture( _data->assets.GetTexture( "Gold Medal" ) );
        }
        else if ( _score >= SILVER_MEDAL_SCORE )
        {
            _medal.setTexture( _data->assets.GetTexture( "Silver Medal" ) );
        }
        else
        {
            _medal.setTexture( _data->assets.GetTexture( "Bronze Medal" ) );
        }
        
        _medal.setPosition( 175, 465 );
    }
    
    void GameOverState::InputHandle()
    {
        sf::Event event;
        
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }
    
    void GameOverState::Update(float delta)
    {
        
    }
    
    void GameOverState::Draw(float delta)
    {
        this->_data->window.clear(sf::Color::Red);
        
        this->_data->window.draw(this->_background);
        
        _data->window.draw(_gameOverTitle);
        _data->window.draw(_gameOverContainer);
        _data->window.draw(_retryButton);
        _data->window.draw(_scoreText);
        _data->window.draw(_highScoreText);
        
        _data->window.draw( _medal );
        
        this->_data->window.display();
    }
}
