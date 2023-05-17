/* This is a C++ code that defines the implementation of the AssetManager class. It includes the SFML
Graphics library and the AssetManager header file. The AssetManager class has methods to load and
retrieve textures and fonts. The LoadTexture method loads a texture from a file and stores it in a
map with a given name. The GetTexture method retrieves a texture from the map with a given name. The
LoadFont method loads a font from a file and stores it in a map with a given name. The GetFont
method retrieves a font from the map with a given name. The namespace Team_Error is used to
encapsulate the implementation of the AssetManager class. */


#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

namespace Team_Error
{
	
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}