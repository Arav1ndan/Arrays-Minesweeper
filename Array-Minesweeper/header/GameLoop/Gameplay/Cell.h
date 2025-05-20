#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Event/EventPollingManager.h"
//#include "../../header/GameLoop/Gameplay/Board.h"

using namespace UIElement;


namespace Gameplay
{
	
	enum class CellState {
		
		OPEN,
		HIDDEN,
		FLAGGED,
	};
	enum class CellType {
		EMPTY,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		MINE,
	};
	class Board;
	class Cell {
	private:
		sf::Vector2i position;

		Board* board;

		const int tile_size = 128;
		const int slice_count = 12;
		const float cell_top_offset = 274.0f;
		const float cell_left_offset = 583.0f;

		const std::string cell_texture_path = "assets/textures/cells.jpeg";

		Button* cell_button;

		void initialize(float width, float height, sf::Vector2i position,Board* board);
		void registerCellButtonCallBack();
		void cellButtonCallback(MouseButtonType button_type);


		CellState current_cell_state;
		CellType cell_type;

		sf::Vector2f getcellScreenPosition(float width, float height) const;
	public:
		Cell(float width, float height, sf::Vector2i position, Board* board);
		sf::Vector2i getCellPosition();
		~Cell() = default;

		
		void render(sf::RenderWindow& window);
		
		bool canOpenCell() const;
		void open();
		
		void reset();

		void toggleFlag();
		CellState getCellState() const;
		void setCellState(CellState state);
		CellType getCellType() const;
		void setCellType(CellType type);
		void update(Event::EventPollingManager& eventManager, sf::RenderWindow& window);
		void setCellTexture();
	};
}