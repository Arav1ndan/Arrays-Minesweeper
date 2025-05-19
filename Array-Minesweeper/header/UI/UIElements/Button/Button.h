#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Sound/SoundManager.h"
//#include "../../header/GameLoop/Gameplay/Board.h"
#include <functional>


namespace UIElement {
	enum class MouseButtonType
	{
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON
	};	

	class Button {
	private:


		using CallbackFunction = std::function<void(MouseButtonType)>;
		CallbackFunction callback_function = nullptr;


		sf::Texture button_texture;
		sf::Sprite button_sprite;

		void initialize(const std::string& texture_path, const sf::Vector2f& posisiton, float width, float height);

		void createBoard();
		//to check if the mouse is clicked from inside the grid..
		bool isMouseOnSprite(Event::EventPollingManager& event_manager, const sf::RenderWindow& window);

	public:
		Button(const sf::String& texture_path, const sf::Vector2f& position, float width, float height);
		
		void setTextureRect(const sf::IntRect& rect);
		
		void handleButtonInteractions(Event::EventPollingManager& event_manager, const sf::RenderWindow& window);
		
		void registerCallbackFunction(CallbackFunction button_callback);
		
		void render(sf::RenderWindow& window) const;
	};
}