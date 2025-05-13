#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Sound/SoundManager.h"
//#include "../../header/GameLoop/Gameplay/Cell.h"
#include <functional>


namespace UIElements{
	enum class MouseButtonType
	{
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON
	};	

	class Button {
	private:

		sf::Texture button_texture;
		sf::Sprite button_sprite;

		void initialize(const std::string& texture_path, const sf::Vector2f& posisiton, float width, float height);

		void createBoard();

	public:
		Button(const sf::String& texture_path, const sf::Vector2f& position, float width, float height);
		void render(sf::RenderWindow& window) const;
	};
}