#pragma once
#include "SFML/Graphics.hpp"

namespace Gameplay {
	class Board {
	private:
		const float boardWidth = 866.0f;
		const float boardHeight = 1080.0f;
		const float boardPosition = 530.0f;

		const std::string boardTexturePath = "assets/textures/board.png";

		sf::Texture boardTexture;
		sf::Sprite boardSprite;
		void initializeBoardImage();
		void initialize();

	public:
		Board();
		void render(sf::RenderWindow& window);
	};
}