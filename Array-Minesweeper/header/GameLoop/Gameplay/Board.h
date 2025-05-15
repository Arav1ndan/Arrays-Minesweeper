#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Event/EventPollingManager.h"


namespace Gameplay {
	class Board {
	private:
		
		const float boardWidth = 866.0f;
		const float boardHeight = 1080.0f;
		const float boardPosition = 530.0f;

		static const int numberOfRows = 9;
		static const int numberOfColoums = 9;

		const float horizontalCellPadding = 115.0f;
		const float verticalCellPadding = 329.0f;

		Cell* cell[numberOfColoums];

		const std::string boardTexturePath = "assets/textures/board.png";

		sf::Texture boardTexture;
		sf::Sprite boardSprite;
		void initializeBoardImage();
		void initialize();
		void createBoard();

		float getCellWidthInBoard() const;
		float getCellHeightInBoard() const;
		

	public:
		Board();
		void render(sf::RenderWindow& window);
	};
}