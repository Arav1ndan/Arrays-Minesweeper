#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Event/EventPollingManager.h"
//#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Sound/SoundManager.h"

using namespace UIElement;

namespace Gameplay {
	class Cell;
	class GameplayManager;
	class Board {
	private:

		GameplayManager* gameplay_manager;
		std::default_random_engine randomEngine;
		std::random_device randomDevice;
		
		const float boardWidth = 866.0f;
		const float boardHeight = 1080.0f;
		const float boardPosition = 530.0f;

		static const int numberOfRows = 9;
		static const int numberOfColoums = 9;

		int flaggerCells;

		const float horizontalCellPadding = 115.0f;
		const float verticalCellPadding = 329.0f;

		Cell* cell[numberOfRows][numberOfColoums];

		int countMinesAround(sf::Vector2i cell_position);
		void populateCells();
		bool isVaildCellPosition(sf::Vector2i cell_position);
		static const int minesCount = 9;
		const std::string boardTexturePath = "assets/textures/board.png";

		sf::Texture boardTexture;
		sf::Sprite boardSprite;
		void initializeBoardImage();
		void initialize(GameplayManager* gameplay_manager);
		void initializeVariables(GameplayManager* gameplay_manager);
		void createBoard();
		
		void openCell(sf::Vector2i cell_position);
		
		void toggleFlag(sf::Vector2i cell_position);
		float getCellWidthInBoard() const;
		float getCellHeightInBoard() const;

		void populateBoard();
		void populateMines();
		


		void processCellType(sf::Vector2i cell_position);

		void processEmptyCell(sf::Vector2i cell_position);
		
		void processMineCell(sf::Vector2i cell_position);

	public:
		Board(GameplayManager* gameplay_manager);
		void onCellButtonClicked(sf::Vector2i cell_position, MouseButtonType mouse_button_type);
		void update(Event::EventPollingManager& eventManager, sf::RenderWindow& window);
		void render(sf::RenderWindow& window);

		void revealAllMines();
	};
}