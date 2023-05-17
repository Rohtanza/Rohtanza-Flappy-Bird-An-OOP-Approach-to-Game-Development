//#pragma once` is a preprocessor directive that ensures that the header file is only included once during compilation, even if it is included multiple times in different parts of the code. The rest of the code defines a class `AssetManager` that manages loading and accessing textures and fonts using the SFML library. The class has private member variables `_textures` and `_fonts` that are maps of strings to SFML texture and font objects, respectively. The class also has public member functions `LoadTexture`, `GetTexture`, `LoadFont`, and `GetFont` that allow the user to load and access textures and fonts by name.

#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Team_Error
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}
