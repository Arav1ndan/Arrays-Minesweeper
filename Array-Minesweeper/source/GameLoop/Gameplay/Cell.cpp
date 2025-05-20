#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/GameLoop/Gameplay/Board.h"
//#include "../../header/UI/UIElements/Button/Button.h"
#include <iostream>

namespace Gameplay {
	
	Cell::Cell(float width, float heigth, sf::Vector2i position, Board* board)
	{
		//this->position = position;
		//sf::Vector2f cellScreenPosition = getcellScreenPosition(width, heigth);
		//cell_button = new Button(cell_texture_path, cellScreenPosition, width * slice_count, heigth);

		initialize(width,heigth,position,board);
	}
	void Cell::initialize(float width, float height, sf::Vector2i position,Board* board)
	{
		this->position = position;
		this->board = board;
		sf::Vector2f cellScreenPosition = getcellScreenPosition(width, height);
		//sf::Vector2f float_position(static_cast <float>(position.x), static_cast <float>(position.y));
		cell_button = new Button(cell_texture_path, cellScreenPosition, width * slice_count, height);
		current_cell_state = CellState::HIDDEN;
		//setCellTexture();
		registerCellButtonCallBack();
	}
	void Cell::registerCellButtonCallBack()
	{
		cell_button->registerCallbackFunction([this](MouseButtonType button_type) {
			cellButtonCallback(button_type);
			});
	}
	void Cell::cellButtonCallback(MouseButtonType button_type)
	{
		board->onCellButtonClicked(getCellPosition(), button_type);
	}
	sf::Vector2f Cell::getcellScreenPosition(float width, float height) const
	{
		float xScreenPosition = cell_left_offset + position.x * width;
		float yScreenPosition = cell_top_offset + position.y * height;

		return sf::Vector2f(xScreenPosition, yScreenPosition);
	}
	sf::Vector2i Cell::getCellPosition()
	{
		return position;
	}
	void Cell::render(sf::RenderWindow& window) {
		setCellTexture();
		if (cell_button) cell_button->render(window);
	}
	bool Cell::canOpenCell() const
	{
		return current_cell_state == CellState::HIDDEN;
	}
	void Cell::open()
	{
		setCellState(CellState::OPEN);
	}
	void Cell::reset()
	{
		current_cell_state = CellState::HIDDEN;  // Back to hidden
		cell_type = CellType::EMPTY;
	}
	void Cell::toggleFlag()
	{
		if (current_cell_state == CellState::HIDDEN) {
			setCellState(CellState::FLAGGED);
		}
		else if (current_cell_state == CellState::FLAGGED) {
			setCellState(CellState::HIDDEN);
		}
	}
	CellState Cell::getCellState() const
	{
		return current_cell_state;
	}
	void Cell::setCellState(CellState state)
	{
		current_cell_state = state;
	}

	CellType Cell::getCellType() const
	{
		return cell_type;
	}

	void Cell::setCellType(CellType type)
	{
		cell_type = type;
	}

	void Cell::update(Event::EventPollingManager& eventManager, sf::RenderWindow& window)
	{
		if (cell_button)
			cell_button->handleButtonInteractions(eventManager, window);
	}

	void Cell::setCellTexture()
	{
		int index = static_cast<int>(cell_type);

		switch (current_cell_state)
		{
		case CellState::OPEN:
			cell_button->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
			break;

		case CellState::HIDDEN:
			cell_button->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
			break;

		case CellState::FLAGGED:
			cell_button->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
			break;
		}
	}

}