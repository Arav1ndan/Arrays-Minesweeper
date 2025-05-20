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
		gameplay_ui = new GameplayUI(this);
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

	void GameplayManager::gameWon()
	{
		Sound::SoundManager::PlaySound(Sound::SoundType::GAME_WON);  
		board->flagAllMines();  
		board->setBoardState(BoardState::COMPLETED);
	}

	void GameplayManager::gameLost()
	{
		Sound::SoundManager::PlaySound(Sound::SoundType::EXPLOSION);  
		board->setBoardState(BoardState::COMPLETED);  
		board->revealAllMines();
	}
	
	void GameplayManager::update(Event::EventPollingManager& eventManager, sf::RenderWindow& window)
	{
		if (!hasGameEnded()) {
			board->update(eventManager, window);
		}
		else if (board->getBoardState() != BoardState::COMPLETED) {
			processGameResult();
		}
		gameplay_ui->update(getRemainingMinesCount(),
			static_cast<int>(remaining_time),
			eventManager, window);
		
	}
	int GameplayManager::getRemainingMinesCount() const
	{
		return board->getRemainingMinesCount();
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
		checkGameWin();
	}
	void GameplayManager::render(sf::RenderWindow& window)
	{
		window.draw(background_sprite);
		board->render(window);

		gameplay_ui->render(window);
	}

	void GameplayManager::setGameResult(GameResult gameResult)
	{
		this->game_result = gameResult;
	}
	void GameplayManager::checkGameWin()
	{
		if (board->areAllCellsOpen()) {
			game_result = GameResult::WON;
		}
	}

	void GameplayManager::processGameResult()
	{
		switch (game_result) {
		case GameResult::WON:
			gameWon();    
			break;
		case GameResult::LOST:
			gameLost();  
			break;
		default:
			break;
		}
	}
	
	bool GameplayManager::hasGameEnded()
	{
		return game_result != GameResult::NONE;
	}
}