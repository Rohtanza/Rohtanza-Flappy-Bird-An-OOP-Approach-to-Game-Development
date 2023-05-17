cmake_minimum_required(VERSION 3.25)

project(FlappyBirdAnOOPApproachtoGameDevelopment)

set(CMAKE_CXX_STANDARD 17)

add_executable(FlappyBirdAnOOPApproachtoGameDevelopment main.cpp AssetManager.cpp AssetManager.hpp Definitions.hpp Game.cpp Game.hpp GameState.cpp GameState.hpp InputManager.cpp InputManager.hpp SplashState.cpp SplashState.hpp State.hpp StateMachine.cpp StateMachine.hpp Bird.cpp Bird.hpp Collision.cpp Collision.hpp Flash.cpp Flash.hpp GameOverState.cpp GameOverState.hpp HUD.cpp HUD.hpp Land.cpp Land.hpp MainMenuState.cpp MainMenuState.hpp Pipe.cpp Pipe.hpp )

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)

target_link_libraries(FlappyBirdAnOOPApproachtoGameDevelopment sfml-system sfml-window sfml-graphics sfml-audio sfml-network)