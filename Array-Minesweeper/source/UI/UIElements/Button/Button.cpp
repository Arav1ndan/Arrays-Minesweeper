#include "../../header/UI/UIElements/Button/Button.h"
#include <iostream>
namespace UIElements {
	
	Button::Button(const sf::String& texture_path, const sf::Vector2f& position, float width, float height)
	{
		initialize(texture_path,position,width,height);
	}
	
	void Button::initialize(const std::string& texture_path, const sf::Vector2f& posisiton, float width, float height)
	{
		if (!button_texture.loadFromFile(texture_path)) {
			std::cerr << "Failed to load button texture: " << texture_path << std::endl;
			return;
		}
		button_sprite.setTexture(button_texture);
		button_sprite.setPosition(posisiton);
		button_sprite.setScale(width / button_texture.getSize().x, height / button_texture.getSize().y);
	}
	void Button::createBoard()
	{
	}
	void Button::setTextureRect(const sf::IntRect& rect)
	{
		button_sprite.setTextureRect(rect);
	}


	void Button::render(sf::RenderWindow& window) const
	{
		window.draw(button_sprite);
	}
}