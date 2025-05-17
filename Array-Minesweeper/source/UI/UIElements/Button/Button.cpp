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
	bool Button::isMouseOnSprite(Event::EventPollingManager& event_manager, const sf::RenderWindow& window) {
		sf::Vector2i mouse_position = event_manager.getMousePosition();

		return button_sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
	}
	void Button::setTextureRect(const sf::IntRect& rect)
	{
		button_sprite.setTextureRect(rect);
	}
	void Button::registerCallbackFunction(CallbackFunction button_callback)
	{
		callback_function = button_callback;
	}

	void Button::handleButtonInteractions(Event::EventPollingManager& event_manager, const sf::RenderWindow& window)
	{
		if (event_manager.pressedLeftMouseButton() && isMouseOnSprite(event_manager, window)) {
			callback_function(MouseButtonType::LEFT_MOUSE_BUTTON);
		}
		else if (event_manager.pressedRightMouseButton() && isMouseOnSprite(event_manager, window)) {
			callback_function(MouseButtonType::RIGHT_MOUSE_BUTTON);
		}
	}

	void Button::render(sf::RenderWindow& window) const
	{
		window.draw(button_sprite);
	}
}