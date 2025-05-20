#include "../../header/GameLoop/Gameplay/GameplayManager.h"

namespace Gameplay {
	
	GameplayManager::GameplayManager()
	{
		initialize();
	}
	void GameplayManager::initialize()
	{
		initializeVariables();
		initializeBackgroundImage();
	}
	void GameplayManager::initializeVariables()
	{
		board = new Board(this);
		remaining_time = max_level_duration;
	}
	
	void GameplayManager::initializeBackgroundImage()
	{
		if (!background_texture.loadFromFile(background_texture_path)) {
			std::cerr << "Failed to load background texture!" << std::endl;
		}
		background_sprite.setTexture(background_texture);
		background_sprite.setColor(sf::Color(255, 255, 255, background_alpha));
	}
	
	void GameplayManager::update(Event::EventPollingManager& eventManager, sf::RenderWindow& window)
	{
		if (!hasGameEnded()) {
			board->update(eventManager, window);
		}
		
	}
	void GameplayManager::updateRemainingTime()
	{
		remaining_time -= TimeManager::getDeltaTime();
		processTimeOver();
	}
	void GameplayManager::processTimeOver() {
		if (remaining_time <= 0) {
			remaining_time = 0; // Don't go negative
			game_result = GameResult::LOST; // Game over!
		}
	}
	void GameplayManager::handleGameplay(EventPollingManager& eventManager, sf::RenderWindow& window)
	{
		updateRemainingTime();
		board->update(eventManager, window);
	}
	void GameplayManager::render(sf::RenderWindow& window)
	{
		window.draw(background_sprite);
		board->render(window);
	}

	void GameplayManager::setGameResult(GameResult gameResult)
	{
		this->game_result = gameResult;
	}
	
	bool GameplayManager::hasGameEnded()
	{
		return game_result != GameResult::NONE;
	}
}